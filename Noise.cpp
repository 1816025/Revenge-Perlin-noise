#include "Noise.h"

Noise::Noise(uint_fast32_t seed)
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

Noise::~Noise()
{
}

void Noise::UpDate(void)
{
}
float Noise::MakeNoise(Position3 pos)
{
	int xi = static_cast<int>(pos.x);
	int yi = static_cast<int>(pos.y);
	int zi = static_cast<int>(pos.z);


	return 0.0f;
}

const std::array<uint_fast8_t, 512> Noise::GetHash()
{
	return hash_;
}
