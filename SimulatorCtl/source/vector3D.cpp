#include "vector3D.h"

CVector3D::CVector3D(float X /*= 0.0f*/, float Y /*= 0.0f*/, float Z /*= 0.0f*/)
{
	x = X;
	y = Y;
	z = Z;
}

void CVector3D::Zero()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

float CVector3D::Length()
{
	return sqrt(x*x + y*y + z*z);
}

void CVector3D::Normalize()
{
	float fLength = Length();
	x /= fLength;
	y /= fLength;
	z /= fLength;
}

bool CVector3D::operator==(const CVector3D& that)
{
	CVector3D vec3DTemp(x - that.x, 0, z - that.z);
	if (DOUBLE_IS_NULL(vec3DTemp.x) && DOUBLE_IS_NULL(vec3DTemp.z))
	{
		return true;
	}

	return false;
}

float CVector3D::GetPitch()
{
	if (DOUBLE_IS_NULL(z))
	{
		return 0.0f;
	}
	float fTemp = sqrt(x*x + z*z);
	return atan(y / fTemp) * 180.0f / M_PI;
}

float CVector3D::GetCourse()
{
	if (DOUBLE_IS_NULL(z))
	{
		return 0.0f;
	}
	float fTemp = sqrt(x*x + y*y);
	return atan(fTemp / z) * 180.0f / M_PI;
}

CVector3D CVector3D::operator-(const CVector3D& that)
{
	return CVector3D(x - that.x, y - that.y, z - that.z);
}

CVector3D CVector3D::operator+(const CVector3D& that)
{
	return CVector3D(x + that.x, y + that.y, z + that.z);
}