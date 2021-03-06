#pragma once

#include "Enemy.hpp"

class ShotgunEnemy : public Enemy
{
public:
	ShotgunEnemy( const Vec2& pos ) : Enemy( pos )
	{}

	void update( Array<Bullet>& bullets, const Player& player )
	{
		// 4 bullets/s, 2%の確率で
		if ( System::FrameCount() % 15 == 0
			&& Random() <= 0.02 * (isChaos ? 2 : 1) )
		{
			// 自機に向かって5方向に散弾を発射
			const Vec2 d = player.getPos() - m_pos;
			const double angle = Atan2( d.y, d.x );
			for ( int i = 0; i < 5; i++ )
			{
				bullets.push_back( Bullet( m_pos, angle - (i - 2) * Pi / 6 ) );
				bullets.back().setSpeed( 1 ); // 追加した弾の速度を 1 にセット
			}

		}
	}

	void draw() const
	{
		Circle( m_pos, BODY_RADIUS ).draw( BODY_COLOR );
	}

private:

	const int BODY_RADIUS = 20;
	const Color BODY_COLOR = Palette::Pink;


};