#pragma once

#include <Siv3D.hpp>
#include "Scenes\CommonData.hpp"

class Player
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos">自機の位置</param>
	Player( const Vec2& pos )
	{
		m_pos = pos;
	}

	Player() { }

	/// <summary>
	/// copy constructor
	/// </summary>
	Player(const Player& p)
	{
		m_pos = p.m_pos;
		m_speed = p.m_speed;
	}

	/// <summary>
	/// = operator overload
	/// </summary>
	Player& operator= ( const Player& p )
	{
		m_pos = p.m_pos;
		m_speed = p.m_speed;

		return *this;
	}

	/// <summary>
	/// 自機の座標を返します
	/// </summary>
	/// <returns>自機の座標</returns>
	Vec2 getPos() const
	{
		return m_pos;
	}

	/// <summary>
	/// 与えられたオブジェクトとの当たり判定を返します
	/// </summary>
	/// <param name="shape">判定したいオブジェクト</param>
	/// <returns>当たっているかどうか</returns>
	bool intersects( const Circle& shape )
	{
		// 点判定
		return m_pos.intersects( shape );
	}

	/// <summary>
	/// 自機の速度を設定します
	/// </summary>
	/// <param name="speed">速度</param>
	void setSpeed(const double speed)
	{
		m_speed = speed;
	}

	/// <summary>
	/// 毎フレームの更新処理
	/// </summary>
	void update()
	{
		Vec2 n = { 0, 0 };
		double speed = m_speed;
		
		// コントローラ入力
		if ( Gamepad( GameInfo::GAMEPAD_NUM ).isConnected() )
		{
			n = { Gamepad( GameInfo::GAMEPAD_NUM ).x, Gamepad( GameInfo::GAMEPAD_NUM ).y };
			if ( n.length() > 0.1 ) speed *= n.length();
			else n = { 0, 0 };
		}

		// キーボード入力
		if ( Input::KeyUp.pressed ) n += Vec2::Up;
		if ( Input::KeyDown.pressed ) n += Vec2::Down;
		if ( Input::KeyLeft.pressed ) n += Vec2::Left;
		if ( Input::KeyRight.pressed ) n += Vec2::Right;

		// 画面内判定
		Vec2 d = speed * n.normalized();
		if ( Rect( { 0, 240, 640, 240 } ).contains( m_pos.movedBy( d ) ) )
		{
			m_pos.moveBy(d);
		}
	}

	/// <summary>
	/// 毎フレームの描画処理
	/// </summary>
	void draw() const
	{
		Triangle( m_pos, RADIUS ).draw(BODY_COLOR);
	}

private:
	Vec2 m_pos = { 0, 0 };
	double m_speed = 5;

	const int RADIUS = 20;
	const Color BODY_COLOR = Palette::Red;

};
