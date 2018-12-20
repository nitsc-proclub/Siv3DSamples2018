
# include <Siv3D.hpp>

void Main()
{
	Circle me = { { 320, 240 }, 30 };
	Circle other = { { 100, 100 }, 50 };

	Font font(20);

	while (System::Update())
	{
		// 移動
		if (Input::KeyRight.pressed) me.center.x += 5;
		if (Input::KeyUp.pressed) me.center.y -= 5;
		if (Input::KeyLeft.pressed) me.center.x -= 5;
		if (Input::KeyDown.pressed) me.center.y += 5;

		// 当たり判定
		if (me.intersects(other))
		{
			font(L"当たってる").draw();
		}

		// 描画
		other.draw();
		me.draw({ 255, 0, 0, 255 });
	}
}
