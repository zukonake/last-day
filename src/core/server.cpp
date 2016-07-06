#include "server.hpp"
#include <exception>
#include <cstdlib>
#include <algorithm>
#include <ctime>
//
#include <core/client.hpp>

Server::Server( void ) noexcept :
	dataset(),
	world( dataset, ( int ) time( nullptr ) )
{
	srand( time( nullptr ) );
}

Server::~Server( void ) noexcept
{
	for( auto iterator : connectedClients )
	{
		disconnectClient( iterator );
	}
}

void Server::connectClient( Client* target )
{
	if( target == nullptr )
	{
		throw std::invalid_argument( "Server::disconnectClient, null pointer given in argument 1." );
		return;
	}
	connectedClients.push_back( target );
	target->connect( world );
	return;
}

void Server::disconnectClient( Client* target )
{
	if( target == nullptr )
	{
		throw std::invalid_argument( "Server::disconnectClient, null pointer given in argument 1." );
		return;
	}
	auto iterator = std::find( connectedClients.begin(), connectedClients.end(), target);
	connectedClients[ std::distance( connectedClients.begin(), iterator ) ]->disconnect();
	connectedClients.erase( iterator );
	return;
}

void Server::simulate( void ) noexcept
{
	if( simulationClock.getElapsedTime() >= sf::milliseconds( 250 ) )
	{
		world.simulate();
		simulationClock.restart();
	}
	return;
}
