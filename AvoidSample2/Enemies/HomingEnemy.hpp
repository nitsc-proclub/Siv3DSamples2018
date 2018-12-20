#pragma once

#include "Enemy.hpp"

class HomingEnemy : public Enemy
{
public:
	HomingEnemy(const Vec2& pos) : Enemy(pos) {}

	void update(Array<Bullet>& bullets, const Player& player)
	{
		// 1%‚ÌŠm—¦‚Å
		if ( Random() <= 0.01 * (isChaos ? 2 : 1) )
		{
			// Atan2‚ÅŽ©‹@‚Ö‚ÌŠp“x‚ð‹‚ßA’e‚ð”­ŽË
			Vec2 d = player.getPos() - m_pos;
			bullets.push_back( Bullet( m_pos, Atan2(d.y, d.x) ) );
		}
	}

	void draw() const
	{
		Circle(m_pos, BODY_RADIUS).draw(BODY_COLOR);
	}

private:

	const int BODY_RADIUS = 10;
	const Color BODY_COLOR = Palette::Aqua;

};
