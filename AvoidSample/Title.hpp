#pragma once

#include "CommonData.hpp"

class Title : public MyApp::Scene
{
public:
	void init() override
	{
		// ����������
		// ����́A�������Ȃ�
	}

	void update() override
	{
		// Enter�L�[�������ꂽ��AGame�V�[���ɑJ��
		if (Input::KeyEnter.clicked)
		{
			changeScene(L"Game");
		}
	}

	void draw() const override
	{
		// �^�C�g��
		FontAsset(L"Title")(GameInfo::Title).drawCenter(Window::Center());
	}
};