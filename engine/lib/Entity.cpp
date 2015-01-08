#include "../include/Entity.h"
#include "../include/Chunk.h"
#include <iostream>
namespace Whitedrop {
	


	// -----------------------------------------------------------------------------------

	Entity::Entity(std::string id, Ogre::Vector3 dimensions, Ogre::Vector3 position, ObjectData* data, std::shared_ptr<Chunk> chunk)
	{
		mId = id;
		mDimensions = dimensions;
		mPosition = position;
		mData = data;
		mChunk = chunk;
	}

	Entity::~Entity(void)
	{

	}

	Entity::Entity(const Entity &ref)
	{
		mData = ref.mData;
		mId = ref.mId;
		mDimensions = ref.mDimensions;
		mPosition = ref.mPosition;
		mChunk = ref.mChunk;
	}
	Entity& Entity:: operator=(Entity ref)
	{
		mData = ref.mData;
		mId = ref.mId;
		mDimensions = ref.mDimensions;
		mPosition = ref.mPosition;
		mChunk = ref.mChunk;
		return *this;

	}
	void Entity::attachToChunk(std::shared_ptr<Chunk> chunk)
	{
		if( chunk != NULL )
		{
			mChunk = chunk;
		}
	}
	void Entity::setup(Ogre::SceneManager* sceneMgr)
	{
		// Create an Entity
		if( mEntity == NULL)
		{
			std::string mesh = mData->get(mChunk->getLOD().getIndex()).first;
			// std::cout << mChunk->getLOD().getIndex() << mesh << std::endl;
			if ( mesh != "" )
			{
			    mEntity = sceneMgr->createEntity(mId, mesh);
		    	std::string material = mData->get(mChunk->getLOD().getIndex()).second;
		    	if( material != "")
		    		mEntity->setMaterialName(material);
		    	// Create a SceneNode and attach the Entity to it
		    	if(mNode == NULL)
		    		mNode = sceneMgr->getRootSceneNode()->createChildSceneNode(mId + "_n");
		    
		    	Ogre::AxisAlignedBox box = mEntity->getBoundingBox();
		    	Ogre::Vector3 realSizes = box.getSize();
		    
		    	mNode->attachObject(mEntity);
		    	 mNode->translate(mPosition);
		    
			    Ogre::Vector3 scaler = Ogre::Vector3(mDimensions.x / realSizes.x, mDimensions.y / realSizes.y, mDimensions.z / realSizes.z);
			    mNode->scale(scaler);
			}
		 } else {

		 	if( mNode != NULL )
			{
				// mNode->showBoundingBox(true);
		 		mNode->detachObject(mId);
			}
		 	if( sceneMgr != NULL)
		 		sceneMgr->destroyEntity(mId);
		 	// if( mEntity != NULL)
		 		// delete mEntity;
		 	mEntity = NULL;
		 	this->setup(sceneMgr);

		 }


    }
	bool Entity::update(void)
	{
		return(true);
	}

   
	
}
