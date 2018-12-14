#pragma once
#include <SFML\Graphics.hpp>

struct bar {
	sf::Color m_colour;
	int m_height;

	explicit bar( const int height, const sf::Color c = { 240, 240, 240 } ) {
		m_height = height;
		m_colour = c;
	}
};