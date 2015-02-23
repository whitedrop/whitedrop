#include "../include/StaticEntity.h"
#include "../include/Chunk.h"
#include <iostream>
namespace Whitedrop {
	


	// -----------------------------------------------------------------------------------

	StaticEntity::StaticEntity(std::string id, std::string mesh, std::string material, Ogre::Vector3 dimensions, Ogre::Vector3 position, lod_couple drawDistances, std::shared_ptr<Chunk> chunk)
	{
		mId = id;
		mDimensions = dimensions;
		mPosition = position;
		mMaterial = material;
		mMesh = mesh;
		mDrawDistances = drawDistances;
		mChunk = chunk;
	}

	StaticEntity::~StaticEntity(void)
	{

	}

	StaticEntity::StaticEntity(const StaticEntity &ref)
	{
		mMaterial = ref.mMaterial;
		mMesh = ref.mMesh;
		mDrawDistances = ref.mDrawDistances;
		mId = ref.mId;
		mDimensions = ref.mDimensions;
		mPosition = ref.mPosition;
		mChunk = ref.mChunk;
	}
	StaticEntity& StaticEntity::operator=(StaticEntity ref)
	{
		mMaterial = ref.mMaterial;
		mMesh = ref.mMesh;
		mDrawDistances = ref.mDrawDistances;
		mId = ref.mId;
		mDimensions = ref.mDimensions;
		mPosition = ref.mPosition;
		mChunk = ref.mChunk;
		return *this;

	}
	void StaticEntity::attachToChunk(std::shared_ptr<Chunk> chunk)
	{
		if( chunk != NULL )
		{
			mChunk = chunk;
		}
	}
	void StaticEntity::setup(Ogre::SceneManager* sceneMgr)
	{
		LOD chunkLOD = mChunk->getLOD();

		
			// we split this in to ifs to avoid mDrawDistances calls
		LOD minLOD = mDrawDistances.first;
		LOD maxLOD = mDrawDistances.second;
		if( chunkLOD >= minLOD && chunkLOD <= maxLOD)
		{

			if( mEntity == NULL)
			{
				// std::cout << "draw " << mMesh << std::endl;

				mEntity = sceneMgr->createEntity(mId, mMesh);
				if( mMaterial != "")
					mEntity->setMaterialName(mMaterial);

			    	// Create a SceneNode and attach the StaticEntity to it
				if(mNode == NULL)
				{
					mNode = sceneMgr->getRootSceneNode()->createChildSceneNode(mId + "_n");
					// mNode->showBoundingBox(true);
					Ogre::AxisAlignedBox box = mEntity->getBoundingBox();
					Ogre::Vector3 realSizes = box.getSize();
					// mNode->attachObject(mEntity);
					mNode->translate(mPosition);
					Ogre::Vector3 scaler = Ogre::Vector3(mDimensions.x / realSizes.x, mDimensions.y /  realSizes.y, mDimensions.z / realSizes.z);
					mNode->scale(scaler);
				}
				mNode->attachObject(mEntity);
			}
		// Nothing should be drawn
		} else {

			// But there's already an Staticentity
			if( mEntity != NULL ) 
			{
				mNode->detachObject(mId);
				sceneMgr->destroyEntity(mId);
				mEntity = NULL;
				// setup(sceneMgr);
			}
		}


	}
	bool StaticEntity::update(void)
	{
		return(true);
	}



}
