#include "SFMLAdapter.hpp"
#include <iostream>

SFMLAdapter::~SFMLAdapter( void ) noexcept
{
	deinitialize();
}

void SFMLAdapter::initialize( const Point& windowSize, const std::string& windowTitle )
{
	mWindow.create( sf::VideoMode( windowSize.x, windowSize.x, 32 ), windowTitle );
	if( !mWindow.isOpen() )
	{
		throw std::runtime_error( "SFMLAdapter::initialize, couldn't initialize window." );
		return;
	}
	mWindow.clear( sf::Color( 0, 0, 0 ) );
	mWindow.setVerticalSyncEnabled( true );
	mWindow.setFramerateLimit( 60 );
	return;
}

void SFMLAdapter::deinitialize( void ) noexcept
{
	mWindow.close();
	return;
}

void SFMLAdapter::update( void ) noexcept
{
	mWindow.display();
	mWindow.clear( sf::Color( 0, 0, 0 ) );
	return;
}

bool SFMLAdapter::isRunning( void ) const noexcept
{
	return mWindow.isOpen();
}

bool SFMLAdapter::isKeyPressed( sf::Keyboard::Key key ) const noexcept
{
	return mKeyboard.isKeyPressed( key );
}

std::vector< sf::Event > SFMLAdapter::getEvents( void ) noexcept
{
	std::vector< sf::Event > output;
	while( mWindow.pollEvent( mEvent ) )
	{
		output.push_back( mEvent );
	}
	return output;
}

sf::RenderWindow& SFMLAdapter::getWindow( void ) noexcept
{
	return mWindow;
}

Point SFMLAdapter::getWindowSize( void ) const noexcept
{
	return mWindow.getSize();
}
