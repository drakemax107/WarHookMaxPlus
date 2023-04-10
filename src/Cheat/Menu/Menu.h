#pragma once
#include "../../Extenal/imgui/imgui.h"
#include "../../Extenal/imgui/imgui_internal.h"

#ifndef _FONT_H
#define _FONT_H
#include "../Utils/Font.h"

#endif // !_FONT_H


namespace menu {
	void showMenu();
	void showWarningwindow();
	void SetupImGuiStyle();

	extern ImFont* def_main;
	extern ImFont* med_main;
	extern ImFont* big_main;
	extern ImFont* icons;

	extern bool agree;
	extern bool open;
	extern bool tab_esp;
	extern bool tab_misc;
	extern bool tab_support;
	extern bool def_tab;
	extern bool def_choice;
	extern ImVec2 sizeScr;
}
