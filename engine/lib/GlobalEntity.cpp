#include "../include/GlobalGlobalEntity.h"
#include <iostream>
namespace Whitedrop {
	


	// -----------------------------------------------------------------------------------

	GlobalEntity::GlobalEntity(std::string id, std::string mesh, std::string material, Ogre::Vector3 dimensions, Ogre::Vector3 position, lod_couple drawDistances, std::shared_ptr<Chunk> chunk)
	{
		mId = id;
		mDimensions = dimensions;
		mPosition = position;
		mMaterial = material;
		mMesh = mesh;
	}

	GlobalEntity::~GlobalEntity(void)
	{

	}

	GlobalEntity::GlobalEntity(const GlobalEntity &ref)
	{
		mMaterial = ref.mMaterial;
		mMesh = ref.mMesh;
		mId = ref.mId;
		mDimensions = ref.mDimensions;
		mPosition = ref.mPosition;
	}

	GlobalEntity& GlobalEntity:: operator=(GlobalEntity ref)
	{
		mMaterial = ref.mMaterial;
		mMesh = ref.mMesh;
		mId = ref.mId;
		mDimensions = ref.mDimensions;
		mPosition = ref.mPosition;
		return *this;

	}

	void GlobalEntity::setup(Ogre::SceneManager* sceneMgr)
	{

				// std::cout << "draw " << mMesh << std::endl;

		mEntity = sceneMgr->createGlobalEntity(mId, mMesh);
		if( mMaterial != "")
			mEntity->setMaterialName(mMaterial);

			    	// Create a SceneNode and attach the GlobalEntity to it
		mNode = sceneMgr->getRootSceneNode()->createChildSceneNode(mId + "_n");
					// mNode->showBoundingBox(true);
		Ogre::AxisAlignedBox box = mEntity->getBoundingBox();
		Ogre::Vector3 realSizes = box.getSize();
					// mNode->attachObject(mEntity);
		mNode->translate(mPosition);
		Ogre::Vector3 scaler = Ogre::Vector3(mDimensions.x / realSizes.x, mDimensions.y /  realSizes.y, mDimensions.z / realSizes.z);
		mNode->scale(scaler);
		mNode->attachObject(mEntity);



	}
	bool GlobalEntity::update(void)
	{
		return(true);
	}



}
