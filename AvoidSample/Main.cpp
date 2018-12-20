#include <Siv3D.hpp>

#include "Title.hpp"
#include "Game.hpp"
#include "Result.hpp"

void Main()
{
	// シーンをマネージャーに追加
	MyApp manager;
	manager.add<Title>(L"Title");
	manager.add<Game>(L"Game");
	manager.add<Result>(L"Result");

	// Fontアセットに追加
	FontAsset::Register(L"SystemFont", 30);

	while (System::Update())
	{
		if (!manager.updateAndDraw())
		{
			break;
		}
	}

}
