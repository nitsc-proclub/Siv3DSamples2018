#pragma once

#include <Siv3d.hpp>
#include <HamFramework.hpp>

namespace GameInfo
{
	const String Title = L"�����Q�[����Ղ�";
}

struct GameData
{
	int score;
};

using MyApp = SceneManager<String, GameData>;

