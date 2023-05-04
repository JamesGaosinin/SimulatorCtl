#ifndef _VECTOR_3D_H
#define _VECTOR_3D_H

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>  //��ѧͷ

#define DOUBLE_IS_NULL(a) (a < 0.0001 && a > -0.0001)

class CVector3D
{
public:
	float x, y, z;

	//����
	CVector3D(float X = 0.0f, float Y = 0.0f, float Z = 0.0f);

	//����  
	void Zero();	//�� x y ����Ϊ0

	//���Ȼ�ȡ		
	float Length();	//sqrt(������) ��������

	//��λ��
	void Normalize();	//������λ��

	//�����ӷ�
	CVector3D operator +(const CVector3D& that);

	//��������
	CVector3D operator -(const CVector3D& that);

	//��������ж�����(����Y�ᣬ��Ϊ����ƽֻ̨�ܷ����ϵ�Ťת�������븩���ı仯)
	bool operator ==(const CVector3D& that);

	// ��ȡ����
	float GetPitch();

	// ��ȡ����
	float GetCourse();
};

#endif