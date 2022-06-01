#include "PlayerBullet.h"

void PlayerBullet::Initialize(Model* model, const Vector3& position)
{
	assert(model);

	model_ = model;
	//�e�N�X�`���ǂݍ���
	textureHandle_ = TextureManager::Load("black.png");

	//���[���h���W������
	worldTransform_.Initialize();
	//�����Ŏ󂯎�����������W���Z�b�g
	worldTransform_.translation_ = { position.x,position.y,position.z };
}

void PlayerBullet::Update()
{
	worldTransformScale(&worldTransform_, scale.x, scale.y, scale.z);
	worldTransformMove(&worldTransform_, worldTransform_.translation_.x, worldTransform_.translation_.y, worldTransform_.translation_.z);
	worldTransformRole(&worldTransform_, rotation.x, rotation.y, rotation.z);

	worldTransform_.TransferMatrix();

}

void PlayerBullet::Draw(const ViewProjection& viewProjection)
{
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}
