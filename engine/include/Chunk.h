/**
 * @file Chunk.h
 * @brief Contains a Chunk class which represents chunk in a world
 * @author vinz243
 * A Chunk represents a way to divide a world.
 * @see Chunk
 * 
 */

#ifndef CHUNK_H
#define CHUNK_H

#include "base.h"
#include "World.h"
#include "LOD.h"
#include "Entity.h"
#include "World.h"
#include "Whitedrop.h"
#include <cmath>
/**
 * @namespace Whitedrop
 */
namespace Whitedrop {
	/**
	 * @class Chunk
	 * @brief Represents a part of the whole world
	 * @details In WhitedropEngine, the world is divided into smaller parts, chunks.
	 * Like in other engines you can have uGrids (skyrim) or chunks (Minecraft).
	 * A chunk has a static size that has to parametized at the setup (or at the map)
	 * Each entity in the world is thereby attached to a chunk,
	 * so when a chunk gets loaded or updated, every entities of this chunks
	 * are to be loaded or updated as well.
	 * 
	 * A chunk is defined by its x and y index (not in meter or inch or whatever)
	 * The entities of said chunk should be located in the chunk position, 
	 * that-is-to-say $chunkX * chunkSize < entPosX < (chunkX + 1) * chunkSize$
	 * but  is not limited to. Theorically, you could even attach every entities of
	 * a 100 km wide world to a single chunk of 10m, but it's not recommended
	 * (increase of loading time, useless foreach....)
	 * 
	 * This Chunk should allow the engine to match the spatial partition pattern
	 * (c. f. http://gameprogrammingpatterns.com/spatial-partition.html).
	 * This allows fast draw distance updating: Rather than browsing every entity
	 * and find which has reached a certain distance and should be drawn or faded away,
	 * it does it by chunks. SO it loops through chunks and compare distances for example.
	 * 
	 */
	class Chunk {
	public:

		/**
		 * @brief default constructor
		 * @details initialialize an empty chunk, unsable
		 */
		Chunk();

		/**
		 * @brief initialize a chunk
		 * @details construct a chunk. Note that it must be added to the world after
		 * 
		 * @param world the world instance where the chunk is
		 * @param x its x coordinate (index)
		 * @param y its y coordinate (index)
		 */
		Chunk(World* world, int x, int y);

		/**
		 * @brief destructor
		 */
		~Chunk();

		/**
		 * @brief The copy constructor
		 * @details A copy constr
		 * 
		 * @param ref the Chunk to be copied from
		 */
		Chunk(const Chunk &ref);

		/**
		 * @brief The assignement operator
		 * @details 
		 * 
		 * @param ent the Chunk to be copied
		 */
		Chunk& operator=(const Chunk ent);

		/**
		 * @brief Update a chunk
		 * @details see Chunk::setup()
		 * @ref Chunk::setup
		 * @ref Entity::setup() 
		 * @ref LevelOfDetail
		 */
		virtual void update();

		/**
		 * @brief setup a chunk.
		 * @details compute chunk's distance from camera,
		 * then compute its LOD accordingly. If it has changed from last update,
		 * then update every static entity. 
		 * @details [long description]
		 */
		virtual void setup();

		/**
		 * @brief add an entity to the chunk
		 * @details add an entity to the chunk, so it will be updated allong w/ the chunk
		 * 
		 * @param ent the entity to add
		 */
		virtual void addEntity(Entity ent);

		/**
		 * @brief Get the chunk's distance from player
		 * @details used for LOD and draw distance
		 * @return the distance in meters
		 */
		virtual float getDistanceFromCam();

		/**
		 * @brief Get the chunk's LOD
		 * @return the LevelOfDetails
		 */
		virtual LevelOfDetail getLOD();

	protected:
		World* mWorld;
		std::vector<Entity> mStaticEntities;
		int mPosX;
		int mPosY;
		LevelOfDetail mLOD;
	};
	static int size = 16;
}


#endif