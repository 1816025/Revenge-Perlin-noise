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

//ì‡êœ
const float Dot(Vector3 vec, Vector3 vec2);


