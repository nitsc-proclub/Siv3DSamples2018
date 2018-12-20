#pragma once

#include "CommonData.hpp"

class Title : public MyApp::Scene
{
public:
	void init() override
	{
		// ����������
		offsets = Array<Point>(100, Point(0, 0));
		drawPos = FontAsset(L"Title")(GameInfo::Title).regionCenter(Window::Center()).pos.asPoint();
	}

	void update() override
	{
		// Enter�L�[�������ꂽ��AGame�V�[���ɑJ��
		if (Input::KeyEnter.clicked || (Gamepad( GameInfo::GAMEPAD_NUM ).isConnected() && Gamepad( GameInfo::GAMEPAD_NUM ).button(0).clicked))
		{
			// �f�o�b�O���[�h
			m_data->isDebug = Input::KeyControl.pressed || (Gamepad( GameInfo::GAMEPAD_NUM ).isConnected() && Gamepad( GameInfo::GAMEPAD_NUM ).button(5).pressed);

			// Chaos���[�h
			
			m_data->chaos = Input::KeyC.pressed || (Gamepad( GameInfo::GAMEPAD_NUM ).isConnected() && Gamepad( GameInfo::GAMEPAD_NUM ).button(4).pressed);

			changeScene(L"Stage");
		}

		if (System::FrameCount() % 5 == 0)
		{
			for (auto& offset : offsets)
			{
				offset = RandomPoint(1, 5);
			}
		}
	}

	void draw() const override
	{
		// �^�C�g��
		const auto animation = [&](KineticTypography& k)
		{
			k.pos += offsets[k.index % offsets.size()];
		};

		FontAsset(L"Title")(GameInfo::Title).drawKinetic(drawPos, animation, Palette::Limegreen, 1.4);

	}

private:
	Array<Point> offsets;
	Point drawPos;

};