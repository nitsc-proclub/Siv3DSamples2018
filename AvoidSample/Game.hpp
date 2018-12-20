#pragma once

#include "CommonData.hpp"

class Game : public MyApp::Scene
{
public:
	void init() override
	{
		// 初期化処理
		// 敵の生成
		for (int i = 0; i < 10; i++)
		{
			// x:0-640, y:0-120の範囲でランダムにポイントを生成し、敵機リストに追加
			enemies.push_back(RandomPoint({ 0, 640 }, { 0, 240 }));
		}

		timer.start();
	}

	void update() override
	{
		// 敵の弾発射
		for (int i = 0; i < enemies.size(); i++) // for (auto e : enemies) とも書ける
		{
			if (Random() <= 0.01) // 1%
			{
				bullets.push_back(enemies[i]);
			}
		}

		// 弾の位置更新
		for (int i = 0; i < bullets.size(); i++)
		{
			bullets[i].moveBy(0, speed);
			// 画面外判定
			if (bullets[i].y > Window::Height() /* 480 */)
			{
				bullets.erase(bullets.begin() + i);
			}
		}

		// 自機と弾とのあたり判定
		for (int i = 0; i < bullets.size(); i++)
		{
			if (player.intersects(Circle(bullets[i], 7)))
			{
				m_data->score = timer.s();
				changeScene(L"Result", 1000, true);
			}
		}

		// ------------------------------------------------------------
		// 入力受け取り
		if (Input::KeyUp.pressed) player.moveBy(0, -speed);
		if (Input::KeyDown.pressed) player.moveBy(0, speed);
		if (Input::KeyLeft.pressed) player.moveBy(-speed, 0);
		if (Input::KeyRight.pressed) player.moveBy(speed, 0);
	}

	void draw() const override
	{
		// 経過時間を右上に表示
		FontAsset(L"Label")(L"Time: ", timer.s()).draw();

		// 敵機
		for (int i = 0; i < enemies.size(); i++)
		{
			Circle(enemies[i], 15).draw(Palette::Orange);
		}

		// 弾
		for (int i = 0; i < bullets.size(); i++)
		{
			Circle(bullets[i], 7).draw();
		}

		// 自機
		player.draw(Palette::Red);
	}

private:
	const int speed = 5; // 自機のスピード
	Triangle player = Triangle(Window::Center(), 20); // 自機 (位置)

	Array<Point> enemies; //敵機リスト (位置の配列)
	Array<Point> bullets; // 弾リスト
	const int bulletSpeed = 2; // 弾のスピード

	Stopwatch timer;

};