#include <Siv3D.hpp>

#include "Scenes/Title.hpp"
#include "Scenes/Stage.hpp"
#include "Scenes/Result.hpp"

void Main()
{
	// シーンをマネージャーに追加
	MyApp manager;
	manager.add<Title>(L"Title");
	manager.add<Stage>(L"Stage");
	manager.add<Result>(L"Result");
	
	// Fontアセットに追加
	FontAsset::Register(L"Title", 30);
	FontAsset::Register(L"Label", 16);

	while (System::Update())
	{
		if (!manager.updateAndDraw())
		{
			break;
		}
	}

}
