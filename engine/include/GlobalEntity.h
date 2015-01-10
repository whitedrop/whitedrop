#ifdef GLOBALENTITY_H
#define GLOBALENTITY_H

#include "Entity.h"


namespace Whitedrop {

	class GlobalEntity : public Entity {

		GlobalEntity(std::string id, std::string material, std::string mesh, Ogre::Vector3 dimensions, Ogre::Vector3 position);
		/**
		 * @brief The copy constructor
		 * @details A copy constr
		 * 
		 * @param ref the GlobalEntity to be copied from
		 */
		GlobalEntity(const GlobalEntity &ref);

		/**
		 * @brief The assignement operator
		 * @details 
		 * 
		 * @param ent the GlobalEntity to be copied
		 */
		GlobalEntity& operator=(const GlobalEntity ent);


		/**
		 * @brief destrctor
		 * @details
		 */
		virtual ~GlobalEntity(void);

		/**
		 * @brief a constance type of the entity
		 * @details depends of the class. 
		 * May contain STATIC, DYNAMIC or ETHERAL
		 */
		const std::string type = "GLOBAL";

		/**
		 * @brief Attach the entity to specified sceneManager
		 * @details This creates the OgreEntity using sceneMgr,
		 * set material, create a Node with name as `<id>_n`,
		 * scale it to match dimensions and translate the node to pos
		 * @param sceneMgr the scene manager to use
		 */
		virtual void setup(Ogre::SceneManager* sceneMgr);

		protected:
			std::string 			mId;
			Ogre::Vector3 			mDimensions;
			Ogre::Vector3 			mPosition;
			Ogre::Entity* 			mEntity = NULL;
			Ogre::SceneNode* 		mNode = NULL;
			std::string				mMesh;
			std::string				mMaterial;
	};
}
#endif