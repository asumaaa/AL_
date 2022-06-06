#include "Vector3.h"
#include "Matrix4.h"
#include <d3d12.h>
#include "WorldTransform.h"

//WorldTransform�̊g��k���̊֐�
void worldTransformScale(WorldTransform *worldTransform_, float x, float y, float z);

//WorldTransform�̕��s�ړ��̊֐�
void worldTransformMove(WorldTransform *worldTransform_, float x, float y, float z);

//WorldTransform�̉�]�̊֐�
void worldTransformRole(WorldTransform *worldTransform_, float x, float y, float z);


void matScaleSet(WorldTransform* worldTransform_, float x, float y, float z);
void matTransrationSet(WorldTransform* worldTransform_, float x, float y, float z);
void matRoleSet(WorldTransform* worldTransform_, float x, float y, float z);