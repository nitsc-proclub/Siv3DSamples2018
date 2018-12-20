#pragma once

#include <Siv3d.hpp>
#include <HamFramework.hpp>

namespace GameInfo
{
	const String Title = L"”ğ‚¯ƒQ[‚³‚ñ‚Õ‚é";
}

struct GameData
{
	int score;
};

using MyApp = SceneManager<String, GameData>;

