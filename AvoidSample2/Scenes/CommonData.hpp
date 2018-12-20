#pragma once

#include <Siv3d.hpp>
#include <HamFramework.hpp>

namespace GameInfo
{
	const int GAMEPAD_NUM = 1;
	const String Title = L"îÇØÉQÅ[Ç≥ÇÒÇ’ÇÈ";
}

struct GameData
{
	bool chaos;
	bool isDebug;
	int score;
};

using MyApp = SceneManager<String, GameData>;

