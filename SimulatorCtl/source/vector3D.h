#ifndef _VECTOR_3D_H
#define _VECTOR_3D_H

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>  //数学头

#define DOUBLE_IS_NULL(a) (a < 0.0001 && a > -0.0001)

class CVector3D
{
public:
	float x, y, z;

	//构造
	CVector3D(float X = 0.0f, float Y = 0.0f, float Z = 0.0f);

	//重置  
	void Zero();	//把 x y 设置为0

	//长度获取		
	float Length();	//sqrt(浮点数) 开方函数

	//单位化
	void Normalize();	//将自身单位化

	//向量加法
	CVector3D operator +(const CVector3D& that);

	//向量减法
	CVector3D operator -(const CVector3D& that);

	//向量相等判断重载(忽略Y轴，因为动感平台只管方向上的扭转，不参与俯仰的变化)
	bool operator ==(const CVector3D& that);

	// 获取俯仰
	float GetPitch();

	// 获取航向
	float GetCourse();
};

#endif