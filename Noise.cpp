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
	//®”•”‚Æ¬”•”‚É•ª‚¯‚éi0`255‚É‚È‚é‚æ‚¤˜_—Ï‚ğ‚Æ‚éj
	int xi = static_cast<int>(pos.x) & 255;
	int yi = static_cast<int>(pos.y) & 255;
	int zi = static_cast<int>(pos.z) & 255;
	double xf = pos.x - (int)(pos.x);
	double yf = pos.y - (int)(pos.y);
	double zf = pos.z - (int)(pos.z);

	double xfs = Smoothstep(xf);
	double yfs = Smoothstep(yf);
	double zfs = Smoothstep(zf);

	/*"a"‚ªŠî€
	  "b"= "a+1"*/
	int aaa, aba, aab, abb, baa, bba, bab, bbb;
	aaa = GetHash()[GetHash()[GetHash()[ xi   ] +  yi   ] +  zi   ];
	aba = GetHash()[GetHash()[GetHash()[ xi   ] + (yi+1)] +  zi   ];
	aab = GetHash()[GetHash()[GetHash()[ xi   ] +  yi   ] + (zi+1)];
	abb = GetHash()[GetHash()[GetHash()[ xi   ] + (yi+1)] + (zi+1)];
	baa = GetHash()[GetHash()[GetHash()[(xi+1)] +  yi   ] +  zi   ];
	bba = GetHash()[GetHash()[GetHash()[(xi+1)] + (yi+1)] +  zi   ];
	bab = GetHash()[GetHash()[GetHash()[(xi+1)] +  yi   ] + (zi+1)];
	bbb = GetHash()[GetHash()[GetHash()[(xi+1)] + (yi+1)] + (zi+1)];

	float lerp1 = this->Lerp(
				  this->Lerp(this->Grad(aaa,Vector3(xf,yf,zf)),
							this->Grad(baa,Vector3(xf -1, yf, zf)), xfs),
				  this->Lerp(this->Grad(aba,Vector3(xf, yf - 1, zf)),
							this->Grad(bba, Vector3(xf - 1, yf - 1, zf)), xfs)
							,yfs);
	
	float lerp2 = this->Lerp(
					this->Lerp(this->Grad(aab, Vector3(xf, yf, zf -1)), 
								this->Grad(bab, Vector3(xf - 1, yf, zf -1)), xfs),
					this->Lerp(this->Grad(abb, Vector3(xf, yf -1, zf -1)), 
								this->Grad(bbb, Vector3(xf - 1, yf-1, zf -1)),xfs)
								,yfs);

	return (this->Lerp(lerp1,lerp2, zfs)+1)/2;
}

const std::array<uint_fast8_t, 512> Noise::GetHash()
{
	return hash_;
}

const float Noise::Grad(uint_fast32_t hash, Position3 pos)
{
	int h = hash & 15;
	double u = (h < 8 /* 0b1000 */ ? pos.x : pos.y);
	double v;// = (h < 4 /* 0b0100 */ ? pos.y : ((h == 12 /* 0b1100 */ || h == 14 /* 0b1110*/) ? pos.x : pos.z));
	if (h < 4 /* 0b0100 */)
	{
		v = pos.y;
	}
	else if (h == 12 /* 0b1100 */ || h == 14 /* 0b1110*/)
	{
		v = pos.x;
	}
	else
	{
		v = pos.z;
	}

	return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

const float Noise::Lerp(const float a, const float b, const float x)
{
	return a + x * (b - a);
}

const float Noise::Smoothstep(const float& t)
{
	//6x^5-15x^4+10x^3
	return t * t*t * (t * (t * 6 - 15) + 10);
}
