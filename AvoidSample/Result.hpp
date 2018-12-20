#pragma once

#include "CommonData.hpp"

class Result : public MyApp::Scene
{
public:
	void init() override
	{
		// ����������
	}

	void update() override
	{
		// Enter�L�[�������ꂽ��ATitle�V�[���ɑJ��
		if (Input::KeyEnter.clicked)
		{
			changeScene(L"Title");
		}
	}

	void draw() const override
	{
		// �X�R�A
		FontAsset(L"Title")(L"Score: ", m_data->score).drawCenter(Window::Center(), Palette::Orange);

		FontAsset(L"Label")(L"Press Enter to Continue").drawCenter(Window::Center() + Vec2(0, 200));
	}
};