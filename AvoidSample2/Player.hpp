#pragma once

#include <Siv3D.hpp>
#include "Scenes\CommonData.hpp"

class Player
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="pos">���@�̈ʒu</param>
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
	/// ���@�̍��W��Ԃ��܂�
	/// </summary>
	/// <returns>���@�̍��W</returns>
	Vec2 getPos() const
	{
		return m_pos;
	}

	/// <summary>
	/// �^����ꂽ�I�u�W�F�N�g�Ƃ̓����蔻���Ԃ��܂�
	/// </summary>
	/// <param name="shape">���肵�����I�u�W�F�N�g</param>
	/// <returns>�������Ă��邩�ǂ���</returns>
	bool intersects( const Circle& shape )
	{
		// �_����
		return m_pos.intersects( shape );
	}

	/// <summary>
	/// ���@�̑��x��ݒ肵�܂�
	/// </summary>
	/// <param name="speed">���x</param>
	void setSpeed(const double speed)
	{
		m_speed = speed;
	}

	/// <summary>
	/// ���t���[���̍X�V����
	/// </summary>
	void update()
	{
		Vec2 n = { 0, 0 };
		double speed = m_speed;
		
		// �R���g���[������
		if ( Gamepad( GameInfo::GAMEPAD_NUM ).isConnected() )
		{
			n = { Gamepad( GameInfo::GAMEPAD_NUM ).x, Gamepad( GameInfo::GAMEPAD_NUM ).y };
			if ( n.length() > 0.1 ) speed *= n.length();
			else n = { 0, 0 };
		}

		// �L�[�{�[�h����
		if ( Input::KeyUp.pressed ) n += Vec2::Up;
		if ( Input::KeyDown.pressed ) n += Vec2::Down;
		if ( Input::KeyLeft.pressed ) n += Vec2::Left;
		if ( Input::KeyRight.pressed ) n += Vec2::Right;

		// ��ʓ�����
		Vec2 d = speed * n.normalized();
		if ( Rect( { 0, 240, 640, 240 } ).contains( m_pos.movedBy( d ) ) )
		{
			m_pos.moveBy(d);
		}
	}

	/// <summary>
	/// ���t���[���̕`�揈��
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
