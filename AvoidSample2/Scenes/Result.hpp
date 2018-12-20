#pragma once

#include "CommonData.hpp"

class Result : public MyApp::Scene
{
public:
	void init() override
	{
		// 初期化処理
	}

	void update() override
	{
		// Enterキーが押されたら、Titleシーンに遷移
		if (Input::KeyEnter.clicked || (Gamepad(GameInfo::GAMEPAD_NUM).isConnected() && Gamepad(GameInfo::GAMEPAD_NUM).button(0).clicked))
		{
			changeScene(L"Title");
		}
	}

	void draw() const override
	{
		// スコア
		FontAsset(L"Title")(L"Score: ", m_data->score).drawCenter(Window::Center(), Palette::Orange);

		FontAsset(L"Label")(L"Press Enter to Continue").drawCenter(Window::Center() + Vec2(0, 200));
	}
};