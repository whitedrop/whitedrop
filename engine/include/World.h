/**
 * @file World.h
 * @page WorldPage World
 * @author vinz243
 */
#ifndef _WORLD_H_
#define _WORLD_H_

#include "base.h"
#include "Entity.h"
#include <map>
#include <memory>

 /**
  * @namespace Whiterop
  */
namespace Whitedrop {
	class WhitedropEngine;
	/**
	 * @class World
	 * @brief represents a world w/ entities
	 */
	class World {

		public:
			/**
			 * @brief ctor
			 * @details creates a world with a scenemgr
			 * 
			 * @param sceneManager the scene manager
			 */
			World(Ogre::SceneManager* sceneManager, WhitedropEngine* engine);

			/**
			 * @brief default ctor
			 */
			World(void);

			/**
			 * @brief default dtor
			 */
			virtual ~World(void);
			
			/**
			 * @brief access the whitedrop engine instance
			 * @return the instance
			 */
			virtual WhitedropEngine* getEngine();
			
			/**
			 * @brief add an entity to the world
			 * @details 
			 * 
			 * @param entity the entity
			 * @param Chunk a pointer to the entity's chunk
			 */
			virtual void addEntity(Entity entity, std::shared_ptr<Chunk> chunk);
	
			/**
			 * @brief setup world
			 * @details call every entity setup(), thereby attaching them to scenemgr
			 */
			virtual void setup(void);

			/**
			 * @brief update the world
			 * @details call every dynamic entity update() method
			 * @return done or not, if falsey should stop simulation
			 */
			virtual bool update(void);

			/**
			 * @brief change scenemgr
			 * 
			 * @param sceneManager the new scene manager
			 */
			virtual void setSceneMgr(Ogre::SceneManager* sceneManager);

			/**
			 * @brief get scenemgr
			 */
			virtual Ogre::SceneManager* getSceneMgr(void);

			/**
			 * @brief gets a chunk for specified indexes
			 * 
			 * @param x the x index
			 * @param y the y index
			 * 
			 * @return a pointer to the chunk
			 */
			virtual std::shared_ptr<Chunk> getChunkAt(int x, int y);
			
		protected:
			Ogre::SceneManager* mSceneMgr;
			WhitedropEngine* mEngine;
			std::map<int, std::shared_ptr<Chunk>> mChunks;
			// std::vector<Entity> dynamicEntities; TODO
	};
}


#endif