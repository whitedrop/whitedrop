
#include "../include/Entity.h"

namespace Whitedrop {
	
	Entity::Entity(std::string mesh, std::string id, Ogre::Vector3 dimensions, Ogre::Vector3 position, std::string material)
	{
		mMesh = mesh;
		mId = id;
		mDimensions = dimensions;
		mPosition = position;
		mMaterial = material;
	}
	Entity::~Entity(void)
	{

	}

	Entity::Entity(const Entity &ref)
	{
		mMesh = ref.mMesh;
		mId = ref.mId;
		mDimensions = ref.mDimensions;
		mPosition = ref.mPosition;
		mMaterial = ref.mMaterial;
	}
	Entity& Entity:: operator=(Entity ref)
	{
		mMesh = ref.mMesh;
		mId = ref.mId;
		mDimensions = ref.mDimensions;
		mPosition = ref.mPosition;
		mMaterial = ref.mMaterial;
		return *this;



	}

	void Entity::setup(Ogre::SceneManager* sceneMgr)
	{
		// Create an Entity
		mEntity = sceneMgr->createEntity(mId, mMesh);
 		mEntity->setMaterialName(mMaterial);
    	// Create a SceneNode and attach the Entity to it
		mNode = sceneMgr->getRootSceneNode()->createChildSceneNode(mId + "_n");

    	Ogre::AxisAlignedBox box = mEntity->getBoundingBox();
		Ogre::Vector3 realSizes = box.getSize();

    	mNode->attachObject(mEntity);
    	mNode->translate(mPosition);

 		Ogre::Vector3 scaler = Ogre::Vector3(mDimensions.x / realSizes.x, mDimensions.y / realSizes.y, mDimensions.z / realSizes.z);
   		mNode->scale(scaler);
  

    }
	bool Entity::update(void)
	{
		return(true);
	}

	
}
