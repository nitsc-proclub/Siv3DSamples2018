#pragma once

#include "Enemy.hpp"

class SimpleEnemy : public Enemy
{
public:
	SimpleEnemy( const Vec2& pos ) : Enemy( pos ) {}

	void update( Array<Bullet>& bullets, const Player& player )
	{
		// 1%�̊m����
		if ( Random() <= 0.01 * (isChaos ? 2 : 1) )
		{
			bullets.push_back( Bullet( m_pos, HalfPi ) );
			bullets.back().setSpeed( 4.5 ); // �ǉ������e�̑��x�� 4.5 �ɃZ�b�g
		}
	}

	void draw() const
	{
		Circle( m_pos, BODY_RADIUS ).draw( BODY_COLOR );
	}

private:

	const int BODY_RADIUS = 10;
	const Color BODY_COLOR = Palette::Orange;


};