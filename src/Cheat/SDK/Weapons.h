#pragma once
#include <array>
#include "../Utils/Math.h"


//Classes for bombs and rockets - projectiles
class Projectile
{
public:
	char pad_0000[456];		//0x0000
	char* Name;				//0x01C8
	char pad_01D0[224];		//0x01D0
	Vector3 Position;		//0x02B0
}; 

class Projectiles {
public:
	std::array<Projectile*, 100U> projectiles;
};

class ProjectileList {
public:
	Projectiles* projectileList;
};
