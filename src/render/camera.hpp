#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SDL/SDL.h>
//
#include <geometry/point.hpp>
#include <world/world.hpp>
#include <render/interface.hpp>

class Camera
{
	World* world;
	Point2D* position;
	unsigned int viewRange;
public:
	void render( Interface* targetInterface, SDL_Rect* targetPosition );

	Camera();
	~Camera();
};

#endif
