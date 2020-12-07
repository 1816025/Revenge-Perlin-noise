#pragma once
#include "Geometry.h"
#include <array>
#include <random>
class Noise
{
public:
	Noise();
	~Noise();
	void UpDate(void);
	void SetSeed(uint_fast32_t seed = 0);
	float MakeNoise(Size3 pos);
	const std::array<uint_fast8_t, 512> GetHash();
private:
	std::array<uint_fast8_t, 512> hash_;
	uint_fast32_t seed_;
};

