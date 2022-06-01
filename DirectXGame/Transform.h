#include "Vector3.h"
#include "Matrix4.h"
#include <d3d12.h>
#include "WorldTransform.h"

//WorldTransform‚ÌŠg‘åk¬‚ÌŠÖ”
void worldTransformScale(WorldTransform *worldTransform_, float x, float y, float z);

//WorldTransform‚Ì•½sˆÚ“®‚ÌŠÖ”
void worldTransformMove(WorldTransform *worldTransform_, float x, float y, float z);

//WorldTransform‚Ì‰ñ“]‚ÌŠÖ”
void worldTransformRole(WorldTransform *worldTransform_, float x, float y, float z);
