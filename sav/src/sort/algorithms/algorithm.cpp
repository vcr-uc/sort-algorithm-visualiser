#include "algorithm.h"
#include <thread>

void algorithm::selection( std::vector < bar > &bars ) {
	/*							      Note:
	 *	On process termination the bar vector will be freed whilst this thread is still
	 *	running. You should wait for the thread to complete before allowing memory to be freed.
	 */

	for ( size_t i = 0; i < bars.size( ) - 1; i++ ) {
		auto swap = i;
		bars [ i ].m_colour = { 0, 255, 0 };

		for ( auto j = i + 1; j < bars.size( ); j++ ) {
			bars [ j ].m_colour = { 255, 0, 0 };

			if ( bars [ j ].m_height < bars [ swap ].m_height ) {
				swap = j;
			}

			std::this_thread::sleep_for( std::chrono::nanoseconds( 1000 ) );

			bars [ j ].m_colour = { 101, 66, 244 };
		}

		bars [ i ].m_colour = { 101, 66, 244 };
		std::iter_swap( bars.begin( ) + i, bars.begin( ) + swap );
	}
}