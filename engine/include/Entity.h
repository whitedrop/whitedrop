/** 
* @file Entity.h
* @page EntityPage Entity
* @brief represent an entity in the game
* @author vinz243
* @version 0.1.0
* This file represents an Entity in the game system
* This parent type is a static entity which is shown and loaded into the Physics engine but never updated
*/

#ifndef ENTITY_H
#define ENTITY_H

#include "base.h"
#include <memory>
#include <utility>
#include "LOD.h"

/// @namespace Whitedrop
namespace Whitedrop {
	typedef LevelOfDetail LOD;
	typedef std::pair<LOD, LOD> lod_couple;

	class Chunk;
	/** @class Entity
	* This parent type is a static entity which is shown and loaded into the Physics engine but never updated
	*/
	class Entity {
	public:
		
		/**
		 * @brief a constance type of the entity
		 * @details depends of the class. 
		 * May contain STATIC, DYNAMIC or ETHERAL
		 */
		const std::string type = "";

		/**
		 * @brief set the entity's chunk
		 * 
		 * @param chunk the chunk
		 */
		virtual void attachToChunk(std::shared_ptr<Chunk> chunk) = 0;
		
		/**
		 * @brief Attach the entity to specified sceneManager
		 * @details This creates the OgreEntity using sceneMgr,
		 * set material, create a Node with name as `<id>_n`,
		 * scale it to match dimensions and translate the node to pos
		 * @param sceneMgr the scene manager to use
		 */
		virtual void setup(Ogre::SceneManager* sceneMgr) = 0;

		/**
		 * @brief the update method
		 * @details this method should be called on each world update.
		 * Even though the method is necessary declared, the main impl of 
		 * a static entity should be empty since it is not updated by physics
		 * However, a Dynamic entity should implement this function in order to:
		 * 1) Get from the physics engine the actor position in the physic world
		 * 2) Update the OgreEntity position and rotation from the previous actor
		 * @return whether it was successful or not, if falsey engine should stop
		 */
		virtual bool update(void) = 0;

	protected:
		std::string 			mId;
		Ogre::Vector3 			mDimensions;
		Ogre::Vector3 			mPosition;
		Ogre::Entity* 			mEntity = NULL;
		Ogre::SceneNode* 		mNode = NULL;
		lod_couple				mDrawDistances;
		std::shared_ptr<Chunk>  mChunk;
		std::string				mMesh;
		std::string				mMaterial;
	};
}


#endif