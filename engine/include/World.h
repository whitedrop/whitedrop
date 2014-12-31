/**
 * @file World.h
 * @page WorldPage World
 * @author vinz243
 */
#ifndef _WORLD_H_
#define _WORLD_H_

#include "base.h"
#include "Entity.h"

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
			
			virtual WhitedropEngine* getEngine();
			/**
			 * @brief add an entity to the world
			 * @details 
			 * 
			 * @param entity [the entity
			 */
			virtual void addEntity(Entity entity);
	
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
			
		protected:
			Ogre::SceneManager* mSceneMgr;
			WhitedropEngine* mEngine;
			std::vector<Entity> staticEntities;
			// std::vector<Entity> dynamicEntities; TODO
	};
}


#endif