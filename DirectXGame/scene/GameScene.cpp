﻿#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include "math.h"
#include "Matrix4.h"

#define PI 3.1415

GameScene::GameScene() {}

GameScene::~GameScene() 
{
	delete model_;
	delete debugCamera_;
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	debugText_ = DebugText::GetInstance();

	//ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("Mario.jpg");

	//3Dモデルの生成
	model_ = Model::Create();
	worldTransform_.scale_ = { 5.0f,1.0f,1.0f };
	//デバッグカメラの生成
	debugCamera_ = new DebugCamera(1280, 720);
	//ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	//ビュープロジェクション
	viewProjection_.Initialize();

	worldTransformScale(&worldTransform_, 5, 5, 5);
	worldTransformMove(&worldTransform_, 0, 15, 0);
	worldTransformRole(&worldTransform_, PI/3, PI/3, PI/3);

	worldTransform_.TransferMatrix();

}

void GameScene::Update() 
{

	debugCamera_->Update();
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	
	//3Dモデル描画
	/*model_->Draw(worldTransform_, viewProjection_, textureHandle_);*/
	model_->Draw(worldTransform_, debugCamera_->GetViewProjection(), textureHandle_);

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// デバッグテキストの描画
	debugText_->DrawAll(commandList);
	//
	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
