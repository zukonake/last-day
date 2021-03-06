
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <memory>
#include <entity/entity.hpp>

struct Point;
class BuildingSubtype;
class World;

class Building : public Entity
{
public:
	Building( const Point& position, const BuildingSubtype* subtype, World& world ) noexcept;
	Building( void ) = default;
};

#endif
