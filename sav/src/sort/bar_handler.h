#pragma once
#include "bar.h"
#include <random>

class bar_handler {
	std::vector< bar > m_bars;
	int m_bar_width { 4 };

public:
	bar_handler( ) {
		//	fill bars container front to back.
		for ( auto i = 0; i < 1216 / m_bar_width; i++ ) {
			m_bars.insert( m_bars.begin( ), bar( static_cast< int >( 684 * 0.5f ) - i, { 101, 66, 244 } ) );
		}

		//	randomise bars container order
		std::shuffle( m_bars.begin( ), m_bars.end( ), std::mt19937( std::random_device( )( ) ) );
	}

public:
	void draw( sf::RenderWindow &window );
	std::vector< bar > &bars( );
};