#pragma once

#include <Siv3D.hpp>
#include "../Bullet.hpp"
#include "../Player.hpp"

class Enemy
{
public:
	Enemy( const Vec2& pos ) : m_pos( pos )
	{
		
	}

	virtual void update( Array<Bullet>& bullets, const Player& player ) = 0;
	virtual void draw() const = 0;

	void setChaos( const bool chaos )
	{
		isChaos = chaos;
	}

protected:
	Vec2 m_pos;
	bool isChaos = false;

};
