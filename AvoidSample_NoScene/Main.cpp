#include <Siv3D.hpp>

void Main()
{
	const Font font(30);

	const int speed = 5; // constつけると定数になる (再代入不可)
	Triangle player = Triangle(Window::Center(), 20); // 自機 (位置)

	Array<Point> enemies; //敵機リスト (位置の配列)
	Array<Point> bullets; // 弾リスト
	const int bulletSpeed = 2; // 弾のスピード

	bool gameover = false; // ゲームオーバーならtrue

	// 敵の生成
	for (int i = 0; i < 10; i++)
	{
		// x:0-640, y:0-120の範囲でランダムにポイントを生成し、敵機リストに追加
		enemies.push_back(RandomPoint({ 0, 640 }, { 0, 240 }));
	}

	while (System::Update())
	{
		if (gameover)
		{
			font(L"GAME OVER!").drawCenter(Window::Center());

			// これによって、以後の処理は無視されて、次のループに飛ぶ (for, while, etc...で使う)
			continue;
		}

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

		// 画面外判定はこうも書ける
		// Erase_if(bullets, [](const Point& p) { return p.y > Window::Height(); });

		// 自機と弾とのあたり判定
		for (int i = 0; i < bullets.size(); i++)
		{
			if (player.intersects(Circle(bullets[i], 7)))
			{
				gameover = true;
			}
		}

		// ------------------------------------------------------------
		// 入力受け取り
		if (Input::KeyUp.pressed) player.moveBy(0, -speed);
		if (Input::KeyDown.pressed) player.moveBy(0, speed);
		if (Input::KeyLeft.pressed) player.moveBy(-speed, 0);
		if (Input::KeyRight.pressed) player.moveBy(speed, 0);

		// ------------------------------------------------------------
		// 描画
		// ※ 描画順注意！ (後に実行したもののほうが上に表示される)

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
}
