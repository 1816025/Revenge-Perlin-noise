#include "Noise.h"

Noise::Noise()
{
}

Noise::~Noise()
{
}

void Noise::UpDate(void)
{
}

void Noise::SetSeed(uint_fast32_t seed)
{
	seed_ = seed;
	for (std::size_t i{}; i < 256; ++i)
	{
		this->hash_[i] = static_cast<uint_fast8_t>(i);
	}
	std::shuffle(this->hash_.begin(), this->hash_.begin() + 256, std::default_random_engine(seed));
	for (std::size_t i{}; i < 256; ++i)
	{
		this->hash_[256 + i] = this->hash_[i];
	}
}

float Noise::MakeNoise(Size3 size)
{
	for (float z = 0; z< size.z;z++)
	{
		for (float y = 0; y < size.y; y++)
		{
			for (float x = 0; x < size.x; x++)
			{
			}
		}
	}
}

const std::array<uint_fast8_t, 512> Noise::GetHash()
{
	return hash_;
}
