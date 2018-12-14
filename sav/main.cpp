#include "src\sort\algorithms\algorithm.h"
#include "src\sort\bar_handler.h"
#include <thread>
#include <windows.h>

int main( ) {
	//	instantiate window
	sf::RenderWindow window( { 1216, 684 }, "SAV: Sorting Algorithms Visualiser", sf::Style::Titlebar | sf::Style::Close );

	//	instantiate bar handler
	bar_handler bars;

	//	sort thread to allow sleeping and not halt window
	std::thread th( &algorithm::selection, std::ref( bars.bars( ) ) );

	while ( window.isOpen( ) ) {
		sf::Event event { };

		while ( window.pollEvent( event ) ) {
			if ( event.type == sf::Event::Closed ) {
				window.close( );
			}
		}

		window.clear( );

		//	render bars
		bars.draw( window );

		window.display( );
	}

	th.detach( );
	return 0;
}