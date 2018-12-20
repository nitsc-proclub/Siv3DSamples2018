# include <Siv3D.hpp>

// 顔検出
// https://github.com/Siv3D/Reference-JP/wiki/%E9%A1%94%E6%A4%9C%E5%87%BA
//
void Main()
{
	Webcam webcam(0);

	if (!webcam.start())
	{
		return;
	}

	Image image;

	DynamicTexture texture;

	while (System::Update())
	{
		if (webcam.hasNewFrame())
		{
			webcam.getFrame(image);

			for (const auto rect : Imaging::DetectFaces(image, CascadeType::Photo, 3, { 40, 40 }))
			{
				rect.overwriteFrame(image, 3, 3, Palette::Red);
			}

			texture.fill(image);
		}

		if (texture)
		{
			texture.mirror().draw();
		}
	}
}
