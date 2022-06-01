#include "Player.h"

void Player::Initialize(Model* model, uint32_t textureHandle, ViewProjection viewProjection)
{
	assert(model);
	this->model_ = model;
	this->textureHandle_ = textureHandle;
	this->viewProjection_ = viewProjection;

	//シングルトンインスタンスを取得する
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	//ワールド変換初期化
	worldTransform_.Initialize();
}

void Player::Update()
{
	Move();
	worldTransform_.TransferMatrix();

	debugText_->SetPos(50, 150);
	debugText_->Printf("%f.%f.%f",worldTransform_.matWorld_.m[3][0],
		worldTransform_.matWorld_.m[3][1], worldTransform_.matWorld_.m[3][2]);
}

void Player::Draw()
{
	model_->Draw(worldTransform_, viewProjection_, textureHandle_);
}

void Player::Move()
{
	if (input_->PushKey(DIK_A))
	{
		move = { -speed,0,0 };
	}
	else if (input_->PushKey(DIK_D))
	{
		move = { speed,0,0 };
	}
	else if (input_->PushKey(DIK_W))
	{
		move = { 0,speed,0 };
	}
	else if (input_->PushKey(DIK_S))
	{
		move = { 0,-speed,0 };
	}
	else
	{
		move = { 0,0,0 };
	}

	//移動限界座標
	const float kMoveLimitX = 36;
	const float kMoveLimitY = 20;

	worldTransform_.matWorld_.m[3][0] = max(worldTransform_.matWorld_.m[3][0], -kMoveLimitX);
	worldTransform_.matWorld_.m[3][0] = min(worldTransform_.matWorld_.m[3][0],+kMoveLimitX);
	worldTransform_.matWorld_.m[3][1] = max(worldTransform_.matWorld_.m[3][1], -kMoveLimitY);
	worldTransform_.matWorld_.m[3][1] = min(worldTransform_.matWorld_.m[3][1], +kMoveLimitY);

	worldTransformMove(&worldTransform_, move.x, move.y, move.z);
}
