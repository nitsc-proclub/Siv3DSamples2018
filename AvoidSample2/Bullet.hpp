#pragma once

#include <Siv3D.hpp>

class Bullet
{
public:
	Bullet(const Vec2& pos)
	{
		m_pos = pos;
		m_angle = 0;
	}

	Bullet(const Vec2& pos, double angle)
	{
		m_pos = pos;
		m_angle = angle;
	}

	/// <summary>
	/// = operator overload
	/// </summary>
	Bullet& operator= ( const Bullet& p )
	{
		m_angle = p.m_angle;
		m_pos = p.m_pos;
		m_speed = p.m_speed;

		return *this;
	}

	void update()
	{
		double dx = m_speed * Cos(m_angle);
		double dy = m_speed * Sin(m_angle);
		m_pos.moveBy(dx, dy);
	}

	void draw() const
	{
		Circle(m_pos, RADIUS).draw(BODY_COLOR);
	}

	bool isIn() const
	{
		// 安地回避のため、弾生存エリアをウィンドウサイズの1.2倍に設定
		return StageRect.contains( Circle( m_pos, RADIUS ) );
	}

	Circle getShape() const
	{
		return Circle( m_pos, RADIUS );
	}

	void setSpeed(const double speed)
	{
		m_speed = speed;
	}

private:
	double m_angle;
	Vec2 m_pos;
	double m_speed = 2;

	const RectF StageRect = Window::ClientRect().scaled( 1.2 ).setCenter( Window::Center() );
	const Color BODY_COLOR = Palette::White;
	const int RADIUS = 5;

};
