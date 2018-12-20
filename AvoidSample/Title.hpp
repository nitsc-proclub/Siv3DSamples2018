#pragma once

#include "CommonData.hpp"

class Title : public MyApp::Scene
{
public:
	void init() override
	{
		// 初期化処理
		// 今回は、何もしない
	}

	void update() override
	{
		// Enterキーが押されたら、Gameシーンに遷移
		if (Input::KeyEnter.clicked)
		{
			changeScene(L"Game");
		}
	}

	void draw() const override
	{
		// タイトル
		FontAsset(L"Title")(GameInfo::Title).drawCenter(Window::Center());
	}
};