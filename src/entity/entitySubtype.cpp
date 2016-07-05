#include "entitySubtype.hpp"
#include <exception>

EntitySubtype::EntitySubtype( std::istream& in ) noexcept :
RenderableObject( in )
{
	in.ignore( 255, ' ' );
	in >> name;
}

const std::string& EntitySubtype::getName( void ) const noexcept
{
	return name;
}
