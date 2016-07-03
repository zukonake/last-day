#ifndef TILE_HPP
#define TILE_HPP

#include <exception>
#include <memory>
#include <cstdint>
//
#include <world/tile/tileSubtype.hpp>
#include <render/objectRenderer/objectRenderer.hpp>
#include <entity/entity.hpp>

class Tile
{
	TileSubtype* subtype;
	int8_t height;
public:
	virtual void render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const;

	const std::string& getSubtypeName( void ) const noexcept { return subtype->getName(); }
	const int8_t& getHeight( void ) const noexcept { return height; }

	Tile( TileSubtype* subtype, int8_t height ) noexcept : subtype( subtype ), height( height ) { }
	Tile( void ) noexcept : subtype( nullptr ) { }
};

#endif