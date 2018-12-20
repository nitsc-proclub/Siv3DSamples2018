# include <Siv3D.hpp>

void Main()
{
	const Font font(18);

	const Circle stickL(400, 150, 90);

	const int GAMEPAD_NUM = 1;

	while (System::Update())
	{
		font(L"Gamepad 1: ", Gamepad(GAMEPAD_NUM).isConnected()).draw();
		font(L"Button 0 :", Gamepad(GAMEPAD_NUM).button(0).pressed).draw({ 0, 50 });
		font(L"X Axis :", Gamepad(GAMEPAD_NUM).x).draw({ 0, 100 });
		font(L"Y Axis :", Gamepad(GAMEPAD_NUM).y).draw({ 0, 150 });
		font(L"Z Axis :", Gamepad(GAMEPAD_NUM).z).draw({ 0, 200 });

		stickL.draw(Color(127));
		Circle(stickL.center + Vec2(Gamepad(1).u, Gamepad(1).r) * 25, 70).draw();

	}

}