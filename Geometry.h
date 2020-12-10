#pragma once

struct Vector3
{
	float x;
	float y;
	float z;
	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
}; 

using Position3 = Vector3;
using Size3 = Vector3;

////����
//const float Dot(Vector3 vec, Vector3 vec2)
//{
//	return vec.x * vec2.x + vec.y * vec2.y + vec.z * vec2.z;
//}
//
////5���Ȑ��ɂ����
//const float Smoothstep(const float& t)
//{
//	//6x^5-15x^4+10x^3
//	return t* t* (t - (t * 6 - 15) + 10);
//}
