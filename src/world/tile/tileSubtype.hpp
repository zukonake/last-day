#ifndef TILESUBTYPE_HPP
#define TILESUBTYPE_HPP

#include <cstdint>
#include <string>
#include <iostream>
//
#include <render/renderable.hpp>

class TileSubtype : public Renderable
{
public:
	const static uint8_t spriteSize = 32;

	TileSubtype( std::istream& in ) noexcept;
	TileSubtype( void ) = default;

	const std::string& getName( void ) const noexcept;
	const bool& getIsPassable( void ) const noexcept;
private:
	bool mIsPassable;
	std::string mName;
};

#endif
