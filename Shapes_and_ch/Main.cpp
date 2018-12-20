
# include <Siv3D.hpp>

void Main()
{
	const Font font(30);

	while (System::Update())
	{
		// 円
		Circle({ 100, 100 }, 30).draw();

		// 長方形
		Rect({ 200, 200, 200, 100 }).draw();

		// 線分
		Line({ 600, 100 }, { 500, 400 }).draw();

		// 文字
		font(L"Siv3D強い").draw({ 100, 300 });
	}
}
