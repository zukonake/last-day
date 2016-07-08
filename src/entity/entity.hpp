#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
//
#include <geometry/point.hpp>

struct Direction;
class ObjectRenderer;
class EntitySubtype;
class World;

class Entity : public sf::Drawable
{
public:
	Entity( const Point& position, const EntitySubtype* subtype, World& world ) noexcept;
	virtual ~Entity( void ) noexcept { }

	void teleport( const Point& targetPosition ) noexcept;
	virtual void move( const Direction& targetDirection );

	const std::string& getName( void ) const noexcept;
	const Point& getPosition( void ) const noexcept;
protected:
	Point mPosition;
	const EntitySubtype* pSubtype;
	World& mWorld;
private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;
};

#endif
