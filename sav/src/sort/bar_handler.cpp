#include "bar_handler.h"

void bar_handler::draw( sf::RenderWindow &window ) {
	for ( size_t i = 0; i < m_bars.size( ); i++ ) {
		auto bar = m_bars [ i ];

		sf::RectangleShape rect( sf::Vector2f( static_cast < float >( m_bar_width ), static_cast < float >( bar.m_height ) ) );
		rect.setPosition( static_cast < float >( m_bar_width * i ), static_cast < float >( 684 - bar.m_height ) );
		rect.setFillColor( bar.m_colour );

		window.draw( rect );
	}
}

std::vector< bar > &bar_handler::bars( ) {
	return m_bars;
}