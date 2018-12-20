
# include <Siv3D.hpp>

void Main()
{
	while (System::Update())
	{
		for (int i : step(16))
		{
			Circle({ i * 40 + 20, 20 }, 20).draw(HSV(360 / 16 * i));
		}

		for (int i : step(16))
		{
			Rect({ i * 40, 60 }, 40).draw(Color(255.0 / 16 * i, 0, 0));
		}

		Triangle(Window::Center(), 40).draw(Palette::Aqua);
	}
}
