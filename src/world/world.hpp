#ifndef WORLD_HPP
#define WORLD_HPP

#include <cstdint>
//
#include <entity/entityContainer.hpp>
#include <world/chunk/chunkContainer.hpp>
#include <world/worldGenerator.hpp>

struct Point;
struct Rectangle;
class ObjectRenderer;
class Dataset;
class Player;

class World : public EntityContainer, public ChunkContainer
{
public:
	World( const Dataset& dataset, const int& seed ) noexcept;

	void simulate( void ) noexcept;
	bool canMove( const Point& target ) noexcept;

	Player* createPlayer( const Point& position, const Rectangle& screenSize ) noexcept;
private:
	const Dataset& mDataset;
	WorldGenerator mGenerator;
};

#endif
