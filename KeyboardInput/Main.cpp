
# include <Siv3D.hpp>

void Main()
{
	while (System::Update())
	{
		if (Input::KeyLeft.pressed)
		{
			Circle({ 140, 230 }, 50).draw(Palette::Red);
		}

		if (Input::KeyDown.clicked)
		{
			Triangle({ 340, 240 }, 100).draw(Palette::Green);
		}

		if (Input::KeyRight.released)
		{
			Rect({ 490, 180 }, 100).draw(Palette::Blue);
		}
	}
}
