#pragma once

#include "Enemy.hpp"

class HomingEnemy : public Enemy
{
public:
	HomingEnemy(const Vec2& pos) : Enemy(pos) {}

	void update(Array<Bullet>& bullets, const Player& player)
	{
		// 1%の確率で
		if ( Random() <= 0.01 * (isChaos ? 2 : 1) )
		{
			// Atan2で自機への角度を求め、弾を発射
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
