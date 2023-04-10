#pragma once
#include "../../Config/Config.h"
#include "../../Utils/Memory.h"

#include "../../../Extenal/imgui/imgui.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "../../../Extenal/imgui/imgui_internal.h"


bool WorldToScreen(const Vector3& in, Vector3& out);

void DrawBox(Matrix3x3 rotation, Vector3 bbmin, Vector3 bbmax, Vector3 position, bool Invulnerable, Vector3& bbcenter);
void DrawBox(Matrix3x3 rotation, Vector3 bbmin, Vector3 bbmax, Vector3 position);

void DrawOffscreenIndicator(Vector3 origin, float distance);

void ESP();
void debug();