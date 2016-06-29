#include "camera.hpp"

void Camera::render( ObjectRenderer* objectRenderer, EntityProxy* entityProxy ) const
{
	if( objectRenderer == NULL )
	{
		throw std::invalid_argument( "ERROR: Camera::render, null pointer given in argument 1." );
		return;
	}
	for( Point::coordinate iteratorY = position.y - viewRange.height, renderY = 0;
		iteratorY < position.y + viewRange.height;
		iteratorY++, renderY += TileSubtype::getSpriteSize() )
	{
		for( Point::coordinate iteratorX = position.x - viewRange.width, renderX = 0;
			iteratorX < position.x + viewRange.width;
			iteratorX++, renderX += TileSubtype::getSpriteSize() )
		{
			SDL_RectWrapper renderPosition( renderX, renderY, TileSubtype::getSpriteSize(), TileSubtype::getSpriteSize() );
			world.renderTile( Point( iteratorX, iteratorY ), objectRenderer, renderPosition );
			Entity* tileEntity = entityProxy->findEntity( Point( iteratorX, iteratorY ) );
			if( tileEntity != NULL )
			{
				tileEntity->render( objectRenderer, Point( renderX, renderY ) );
			}
		}
	}
	return;
}
