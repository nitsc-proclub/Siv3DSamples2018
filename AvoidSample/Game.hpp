#pragma once

#include "CommonData.hpp"

class Game : public MyApp::Scene
{
public:
	void init() override
	{
		// ����������
		// �G�̐���
		for (int i = 0; i < 10; i++)
		{
			// x:0-640, y:0-120�͈̔͂Ń����_���Ƀ|�C���g�𐶐����A�G�@���X�g�ɒǉ�
			enemies.push_back(RandomPoint({ 0, 640 }, { 0, 240 }));
		}

		timer.start();
	}

	void update() override
	{
		// �G�̒e����
		for (int i = 0; i < enemies.size(); i++) // for (auto e : enemies) �Ƃ�������
		{
			if (Random() <= 0.01) // 1%
			{
				bullets.push_back(enemies[i]);
			}
		}

		// �e�̈ʒu�X�V
		for (int i = 0; i < bullets.size(); i++)
		{
			bullets[i].moveBy(0, speed);
			// ��ʊO����
			if (bullets[i].y > Window::Height() /* 480 */)
			{
				bullets.erase(bullets.begin() + i);
			}
		}

		// ���@�ƒe�Ƃ̂����蔻��
		for (int i = 0; i < bullets.size(); i++)
		{
			if (player.intersects(Circle(bullets[i], 7)))
			{
				m_data->score = timer.s();
				changeScene(L"Result", 1000, true);
			}
		}

		// ------------------------------------------------------------
		// ���͎󂯎��
		if (Input::KeyUp.pressed) player.moveBy(0, -speed);
		if (Input::KeyDown.pressed) player.moveBy(0, speed);
		if (Input::KeyLeft.pressed) player.moveBy(-speed, 0);
		if (Input::KeyRight.pressed) player.moveBy(speed, 0);
	}

	void draw() const override
	{
		// �o�ߎ��Ԃ��E��ɕ\��
		FontAsset(L"Label")(L"Time: ", timer.s()).draw();

		// �G�@
		for (int i = 0; i < enemies.size(); i++)
		{
			Circle(enemies[i], 15).draw(Palette::Orange);
		}

		// �e
		for (int i = 0; i < bullets.size(); i++)
		{
			Circle(bullets[i], 7).draw();
		}

		// ���@
		player.draw(Palette::Red);
	}

private:
	const int speed = 5; // ���@�̃X�s�[�h
	Triangle player = Triangle(Window::Center(), 20); // ���@ (�ʒu)

	Array<Point> enemies; //�G�@���X�g (�ʒu�̔z��)
	Array<Point> bullets; // �e���X�g
	const int bulletSpeed = 2; // �e�̃X�s�[�h

	Stopwatch timer;

};