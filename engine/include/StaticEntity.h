/** 
* @file StaticEntity.h
* @brief represent a static entity in the game
* @author vinz243
* @version 0.1.0
* This file represents an StaticEntity in the game system
* This parent type is a static entity which is shown and loaded into the Physics engine but never updated
*/

#ifndef STATIC_ENTITY_H
#define STATIC_ENTITY_H

#include "base.h"
#include <memory>
#include <utility>
#include "LOD.h"
#include "Entity.h"


/// @namespace Whitedrop
namespace Whitedrop {
	typedef LevelOfDetail LOD;
	typedef std::pair<LOD, LOD> lod_couple;

	class Chunk;
	/** @class StaticEntity
	* A static entity is an entity which is loaded into the quantum engine, 
	* but this entity will never move (i.e frozen) and the update() method is almost never called.
	* 
	* They'd better use very often as their footprint is rather lightweight
	*/

	class StaticEntity : public Entity{

	public:
		/**
		 * @brief Create static entity
		 * @details creates a static entity instance according to the mesh and the id, the position
		 * This needs to be attached to a World after!
		 * The material name is not the file name but the material name!
		 * @ref WorldPage
		 * @ref ObjectData
		 * @param id an unique identifier for the object, shortest as possible
		 * @param dimensions an Ogre::Vector3 which contains the dimensions in meter
		 * @param position the Vector3 which contains it position 
		 * @param data a pointer to the corresponding ObjectData
		 * @param chunk (optionnal) the chunk which this entity is attached to
		 */
		StaticEntity(std::string id, std::string material, std::string mesh, Ogre::Vector3 dimensions, Ogre::Vector3 position, lod_couple drawDistances, std::shared_ptr<Chunk> chunk = NULL);
		
		/**
		 * @brief The copy constructor
		 * @details A copy constr
		 * 
		 * @param ref the StaticEntity to be copied from
		 */
		StaticEntity(const StaticEntity &ref);

		/**
		 * @brief The assignement operator
		 * @details 
		 * 
		 * @param ent the entity to be copied
		 */
		StaticEntity& operator=(const StaticEntity ent);

		/**
		 * @brief destrctor
		 * @details
		 */
		virtual ~StaticEntity(void);

		/**
		 * @brief a constance type of the entity
		 * @details depends of the class. 
		 * May contain STATIC, DYNAMIC or ETHERAL
		 */
		const std::string type = "STATIC";

		/**
		 * @brief set the entity's chunk
		 * 
		 * @param chunk the chunk
		 */
		virtual void attachToChunk(std::shared_ptr<Chunk> chunk);
		
		/**
		 * @brief Attach the entity to specified sceneManager
		 * @details This creates the OgreEntity using sceneMgr,
		 * set material, create a Node with name as `<id>_n`,
		 * scale it to match dimensions and translate the node to pos
		 * @param sceneMgr the scene manager to use
		 */
		virtual void setup(Ogre::SceneManager* sceneMgr);

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
		virtual bool update(void);

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