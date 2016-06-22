#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SDL/SDL.h>
//
#include <geometry/point.hpp>
#include <world/world.hpp>
#include <render/userInterface.hpp>

class Camera
{
	const Point2D& position;
	World& world;
	unsigned int viewRange;
public:
	void render( UserInterface* targetUserInterface, SDL_Rect* targetPosition );

	Camera( const Point2D& position, World& world );
	Camera();
	~Camera();
};

#endif
