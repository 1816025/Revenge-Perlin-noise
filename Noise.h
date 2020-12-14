#pragma once
#include "Geometry.h"
#include <array>
#include <random>
class Noise
{
public:
	Noise(uint_fast32_t seed = 0);
	~Noise();
	void UpDate(void);
	float MakeNoise(Position3 pos);
	const std::array<uint_fast8_t, 512> GetHash();
private:
	const float Grad(uint_fast32_t hash, Position3 pos);
	const float Lerp(const float a, const float b, const float x);
	//5Ÿ‹Èü‚É‚æ‚é•âŠÔ
	const float Smoothstep(const float& t);
	std::array<uint_fast8_t, 512> hash_;
	uint_fast32_t seed_;
};

