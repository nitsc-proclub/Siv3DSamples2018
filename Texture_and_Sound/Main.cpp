# include <Siv3D.hpp>

void Main()
{
	const Font font(24);

	// テクスチャ(画像)をロード
	const Texture texture(L"Example/Windmill.png");

	// サウンドファイルをロード
	const Sound sound(L"Example/風の丘.mp3");

	if (!sound)
	{
		// ロードに失敗したら終了
		return;
	}

	// サウンドの再生
	sound.play();

	while (System::Update())
	{
		// 位置 (100, 50) にテクスチャを描く
		texture.draw(100, 50);

		// 再生位置を表示
		font(L"再生位置: ", sound.streamPosSec()).draw();

	}
}
