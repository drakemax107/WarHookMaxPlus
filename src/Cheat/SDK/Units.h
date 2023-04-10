#pragma once
#include "../Includes.h"
#include "../Utils/Math.h"
#include <array>
#include <unordered_set>
#include <string>

class Player
{
	enum GuiState : std::uint8_t
	{
		NONE = 0,
		MENU = 1,
		ALIVE = 2,
		DEAD = 3,
		SPEC = 6,
		LIMBO = 8,
		LOADING = 10
	};

public:
	char pad_0000[168]; //0x0000
	char Name[32]; //0x00A8
	char pad_00C8[1048]; //0x00C8
	uint8_t GuiState; //0x04E0
	char pad_04E1[511]; //0x04E1
	class Unit* ControlledUnit; //0x06E0

	bool IsAlive() const noexcept
	{
		return GuiState == GuiState::ALIVE;
	}

	bool IsDead() const noexcept
	{
		return GuiState == GuiState::DEAD;
	}

	bool IsinHangar() const noexcept
	{
		return GuiState == GuiState::MENU;
	}
};


class Unit
{
	enum UnitState : std::uint8_t {
		ALIVE = 0,
		DEAD = 2,
	};

public:
	char pad_0000[504]; //0x0000
	Vector3 BBMin; //0x01F8
	Vector3 BBMax; //0x0204
	char pad_0210[592]; //0x0210
	char* UnitName; //0x0460
	char pad_0468[688]; //0x0468
	uint8_t VisualReload; //0x0718
	char pad_0719[539]; //0x0719
	Matrix3x3 RotationMatrix; //0x0934
	Vector3 Position; //0x0958
	char pad_0964[1424]; //0x0964
	float InvulTimer; //0x0EF4
	char pad_0EF8[32]; //0x0EF8
	bool Invulnerable; //0x0F18
	char pad_0F19[223]; //0x0F19
	uint8_t UnitState; //0x0FF8
	char pad_0FF9[15]; //0x0FF9
	class Player* PlayerInfo; //0x1008
	char pad_1010[64]; //0x1010
	uint8_t TeamNum; //0x1050
	char pad_1051[15]; //0x1051
	class Info* UnitInfo; //0x1060
	char pad_1068[168]; //0x1068
	class Armory* Weapons; //0x1110

	bool IsAlive() const noexcept
	{
		return UnitState == UnitState::ALIVE;
	}

	bool IsDead() const noexcept
	{
		return UnitState == UnitState::DEAD;
	}
};

class Info
{
public:
	char* unitName; //0x0000
	char* modelName; //0x0008
	char* modelPath; //0x0010
	char* FullName; //0x0018
	char* ShortName; //0x0020
	char pad_0028[8]; //0x0028
	char* unitType; //0x0030
	char pad_0038[428]; //0x0038
	float ZoomMulti; //0x01E4
	float AlternateMulti; //0x01E8
	char pad_01EC[16]; //0x01EC
	float ShadowMulti; //0x01FC


	bool isPlane() {
		static const std::unordered_set<std::string> planeTypes = { "exp_bomber", "exp_assault", "exp_fighter" };
		return planeTypes.find(unitType) != planeTypes.end();
	}

	bool isDummy() {
		static const std::unordered_set<std::string> dummyTypes = { "exp_fortification", "exp_structure", "exp_aaa", "dummy_plane", "exp_bridge", "exp_zero", "exp_ca_ship"};
		return dummyTypes.find(unitType) != dummyTypes.end();
	}
};

class EntList {
public:
	Player* players[64];
};

class Units {
public:
	std::array<Unit*, 500U> units;
};

class UnitList {
public:
	Units* unitList;
};