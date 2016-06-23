#include "entitySubtype.hpp"

EntitySubtype::EntitySubtype( std::istream& in ) :
	Sprite( in )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> name;
	std::cout << "INFO: Initializing entitySubtype: " << name << " .\n";
}

EntitySubtype::~EntitySubtype()
{

}
