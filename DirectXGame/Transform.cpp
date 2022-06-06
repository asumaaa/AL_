#include "Transform.h"
#include <cassert>
#include "math.h"

void worldTransformScale(WorldTransform *worldTransform_, float x, float y, float z)
{
	worldTransform_->scale_ = { x,y,z };
	Matrix4 matScale(
		worldTransform_->scale_.x, 0.0f, 0.0f, 0.0f,
		0.0f, worldTransform_->scale_.y, 0.0f, 0.0f,
		0.0f, 0.0f, worldTransform_->scale_.z, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	worldTransform_->matWorld_ *= matScale;
}

void worldTransformMove(WorldTransform *worldTransform_, float x, float y, float z)
{
	worldTransform_->translation_ = { x,y,z };
	Matrix4 matTrans(
		1.0f, 0.0f, 0.0f, 0,
		0.0f, 1.0f, 0.0f, 0,
		0.0f, 0.0f, 1.0f, 0,
		worldTransform_->translation_.x, worldTransform_->translation_.y, worldTransform_->translation_.z, 1.0f
	);
	worldTransform_->matWorld_ *= matTrans;
}

void worldTransformRole(WorldTransform *worldTransform_, float x, float y, float z)
{
	worldTransform_->rotation_ = { x,y,z };
	Matrix4 matRot;
	Matrix4 matRotX(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, cos(worldTransform_->rotation_.x), sin(worldTransform_->rotation_.x), 0.0f,
		0.0f, -sin(worldTransform_->rotation_.x), cos(worldTransform_->rotation_.x), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	Matrix4 matRotY(
		cos(worldTransform_->rotation_.y), 0.0f, -sin(worldTransform_->rotation_.y), 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		sin(worldTransform_->rotation_.y), 0.0f, cos(worldTransform_->rotation_.y), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	Matrix4 matRotZ(
		cos(worldTransform_->rotation_.z), sin(worldTransform_->rotation_.z), 0.0f, 0.0f,
		-sin(worldTransform_->rotation_.z), cos(worldTransform_->rotation_.z), 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	matRot = matRotZ;
	matRot *= matRotX;
	matRot *= matRotY;
	worldTransform_->matWorld_ *= matRot;
}

void matScaleSet(WorldTransform* worldTransform_, float x, float y, float z)
{
	worldTransform_->matWorld_.m[0][0] *= x;
	worldTransform_->matWorld_.m[1][1] *= y;
	worldTransform_->matWorld_.m[2][2] *= z;
}

void matTransrationSet(WorldTransform* worldTransform_, float x, float y, float z)
{
	worldTransform_->matWorld_.m[3][0] *= x;
	worldTransform_->matWorld_.m[3][1] *= y;
	worldTransform_->matWorld_.m[3][2] *= z;
}

void matRoleSet(WorldTransform* worldTransform_, float x, float y, float z)
{
	Matrix4 matRot;
	Matrix4 matRotX(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, cos(x), sin(x), 0.0f,
		0.0f, -sin(x), cos(x), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	Matrix4 matRotY(
		cos(y), 0.0f, -sin(y), 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		sin(y), 0.0f, cos(y), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	Matrix4 matRotZ(
		cos(z), sin(z), 0.0f, 0.0f,
		-sin(z), cos(z), 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	matRot = matRotZ;
	matRot *= matRotX;
	matRot *= matRotY;
	worldTransform_->matWorld_ *= matRot;

	/*worldTransform_->matWorld_.m[0][0] *= cos(y) * cos(z);
	worldTransform_->matWorld_.m[0][1] *= -sin(z);
	worldTransform_->matWorld_.m[0][2] *= sin(y);
	worldTransform_->matWorld_.m[1][0] *= sin(z);
	worldTransform_->matWorld_.m[1][1] *= cos(x) * cos(z);
	worldTransform_->matWorld_.m[1][2] *= -sin(x);
	worldTransform_->matWorld_.m[2][0] *= -sin(y);
	worldTransform_->matWorld_.m[2][1] *= sin(x);
	worldTransform_->matWorld_.m[2][2] *= cos(x) * cos(y);*/

	/*worldTransform_->matWorld_.m[1][1] = cos(x);
	worldTransform_->matWorld_.m[1][2] = -sin(x);
	worldTransform_->matWorld_.m[2][1] = sin(x);
	worldTransform_->matWorld_.m[2][2] = cos(x);*/
}
