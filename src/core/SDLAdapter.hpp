#ifndef SDLADAPTER_HPP
#define SDLADAPTER_HPP

#include <cstdint>
#include <exception>
#include <vector>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//
#include <geometry/rectangle.hpp>

class SDLAdapter
{
	SDL_Window* window;
	SDL_Renderer* renderer;

	void initialize( void );
	void initializeWindow( const Rectangle& windowSize, const std::string& windowTitle );
	void initializeRenderer( void );
	void deinitializeSDL( void );
public:
	void update( void ) noexcept;

	SDL_Renderer* getRenderer( void ) const noexcept { return renderer; }
	std::vector< SDL_Event > getEvents( void ) const noexcept;
	const uint8_t* getKeystate( void ) const noexcept { return SDL_GetKeyboardState( nullptr ); }
	Rectangle getWindowSize( void ) const noexcept;

	SDLAdapter( const Rectangle& windowSize, const std::string& windowTitle );
	virtual ~SDLAdapter( void );
};

#endif