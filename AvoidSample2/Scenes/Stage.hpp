#pragma once

#include "CommonData.hpp"

#include "../Player.hpp"
#include "../Bullet.hpp"

#include "../Enemies/Enemy.hpp"
#include "../Enemies/SimpleEnemy.hpp"
#include "../Enemies/HomingEnemy.hpp"
#include "../Enemies/ShotgunEnemy.hpp"

class Stage : public MyApp::Scene
{
public:
	void init() override
	{
		// ����������
		m_player = Player( Window::Center() + Vec2( 0, 100 ) );

		// �G�̐���
		for ( int i = 0; i < (m_data->chaos ? 25 : 10); i++ )
		{
			const Vec2 pos = RandomVec2( { 40, 600 }, { 40, 200 } );
			
			// �R�R��ւ�̊m���͂���������ł�
			const double p = Random();
			if ( p >= 0.5 ) // 50%?
			{
				m_enemies.emplace_back( std::make_shared<SimpleEnemy>( pos ) );
			}
			else if ( p >= 0.1 ) // 40%?
			{
				m_enemies.emplace_back( std::make_shared<HomingEnemy>( pos ) );
			}
			else // 10%?
			{
				m_enemies.emplace_back( std::make_shared<ShotgunEnemy>( pos ) );
			}

			m_enemies.back()->setChaos( m_data->chaos );
		}

		// ���Ԍv���̊J�n
		m_timer.start();
	}

	void update() override
	{
		// �G�̒e����
		for ( auto& enemy : m_enemies )
		{
			enemy->update( m_bullets, m_player );
		}

		// �e�̈ʒu�X�V
		for ( auto& bullet : m_bullets )
		{
			bullet.update();
		}

		// ��ʊO�̒e�̍폜
		Erase_if( m_bullets, []( const Bullet& b )
		{
			return !b.isIn();
		} );

		// ���@�ƒe�Ƃ̂����蔻��
		if ( !m_data->isDebug )
		{
			for ( auto& bullet : m_bullets )
			{
				if ( m_player.intersects( bullet.getShape() ) )
				{
					// �Q�[���I�[�o�[
					m_data->score = m_timer.s();
					changeScene( L"Result" );
				}
			}
		}

		// Player
		m_player.update();

		// Control �L�[�ŋ����V�[���J��
		if ( Input::KeyControl.clicked || (Gamepad( GameInfo::GAMEPAD_NUM ).isConnected() && Gamepad( GameInfo::GAMEPAD_NUM ).button( 5 ).clicked) )
		{
			m_data->score = m_data->isDebug ? 0 : m_timer.s();
			changeScene( L"Result" );
		}
	}

	void draw() const override
	{
		// �o�ߎ��Ԃ��E��ɕ\��
		FontAsset( L"Label" )(L"Time: ", m_timer.s()).draw();

		if ( m_data->isDebug )
		{
			FontAsset( L"Label" )(L"�ł΂������[��").draw( { Window::Width() - 175, 10 }, Palette::Gold );
		}

		if ( m_data->chaos )
		{
			FontAsset( L"Label" )(L"������������������").draw( { Window::Width() - 175, 40 }, Palette::Yellow );
		}

		// �G�@
		for ( const auto& enemy : m_enemies )
		{
			enemy->draw();
		}

		// ���S��
		Line( { 0, 240 }, { 640, 240 } ).draw(2.0, Palette::Darkorange);

		// ���@
		m_player.draw();

		// �e
		for ( const auto& bullet : m_bullets )
		{
			bullet.draw();
		}
	}

private:
	Player m_player;

	Array<std::shared_ptr<Enemy>> m_enemies; //�G�@
	Array<Bullet> m_bullets; // �e

	Stopwatch m_timer;

};
