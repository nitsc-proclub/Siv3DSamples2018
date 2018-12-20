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
		// 初期化処理
		m_player = Player( Window::Center() + Vec2( 0, 100 ) );

		// 敵の生成
		for ( int i = 0; i < (m_data->chaos ? 25 : 10); i++ )
		{
			const Vec2 pos = RandomVec2( { 40, 600 }, { 40, 200 } );
			
			// ココらへんの確率はいいかげんです
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

		// 時間計測の開始
		m_timer.start();
	}

	void update() override
	{
		// 敵の弾発射
		for ( auto& enemy : m_enemies )
		{
			enemy->update( m_bullets, m_player );
		}

		// 弾の位置更新
		for ( auto& bullet : m_bullets )
		{
			bullet.update();
		}

		// 画面外の弾の削除
		Erase_if( m_bullets, []( const Bullet& b )
		{
			return !b.isIn();
		} );

		// 自機と弾とのあたり判定
		if ( !m_data->isDebug )
		{
			for ( auto& bullet : m_bullets )
			{
				if ( m_player.intersects( bullet.getShape() ) )
				{
					// ゲームオーバー
					m_data->score = m_timer.s();
					changeScene( L"Result" );
				}
			}
		}

		// Player
		m_player.update();

		// Control キーで強制シーン遷移
		if ( Input::KeyControl.clicked || (Gamepad( GameInfo::GAMEPAD_NUM ).isConnected() && Gamepad( GameInfo::GAMEPAD_NUM ).button( 5 ).clicked) )
		{
			m_data->score = m_data->isDebug ? 0 : m_timer.s();
			changeScene( L"Result" );
		}
	}

	void draw() const override
	{
		// 経過時間を右上に表示
		FontAsset( L"Label" )(L"Time: ", m_timer.s()).draw();

		if ( m_data->isDebug )
		{
			FontAsset( L"Label" )(L"でばっぐもーど").draw( { Window::Width() - 175, 10 }, Palette::Gold );
		}

		if ( m_data->chaos )
		{
			FontAsset( L"Label" )(L"†††かおす†††").draw( { Window::Width() - 175, 40 }, Palette::Yellow );
		}

		// 敵機
		for ( const auto& enemy : m_enemies )
		{
			enemy->draw();
		}

		// 中心線
		Line( { 0, 240 }, { 640, 240 } ).draw(2.0, Palette::Darkorange);

		// 自機
		m_player.draw();

		// 弾
		for ( const auto& bullet : m_bullets )
		{
			bullet.draw();
		}
	}

private:
	Player m_player;

	Array<std::shared_ptr<Enemy>> m_enemies; //敵機
	Array<Bullet> m_bullets; // 弾

	Stopwatch m_timer;

};
