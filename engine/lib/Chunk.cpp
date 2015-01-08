#include "../include/Chunk.h"
#include <iostream>

namespace Whitedrop {

	Chunk::Chunk()
	{

	}
	Chunk::~Chunk()
	{
		// delete[] mStaticEntities;
	}
	Chunk::Chunk(World* world, int x, int y)
	{
		mWorld = world;
		mPosX = x;
		mPosY = y;
	}

	Chunk::Chunk(const Chunk &ref)
	{
		mWorld = ref.mWorld;
		mStaticEntities = ref.mStaticEntities;
		mPosX = ref.mPosX;
		mPosY = ref.mPosY;
		mLOD = ref.mLOD;
	}

	Chunk& Chunk::operator=(const Chunk ref)
	{
		mWorld = ref.mWorld;
		mStaticEntities = ref.mStaticEntities;
		mPosX = ref.mPosX;
		mPosY = ref.mPosY;
		mLOD = ref.mLOD;
		return *this;
	}

	void Chunk::addEntity(Entity ent)
	{
		mStaticEntities.push_back(ent);
	}
	void Chunk::update()
	{	
		setup();
	}
	void Chunk::setup()
	{
		float distance = getDistanceFromCam();
		LevelOfDetail newLOD = LevelOfDetail(LODDistance(distance));
		if(newLOD != mLOD)	
			
		{
			// std::cout << mPosX << ";" << mPosY << ";" << newLOD.getIndex() << ":" << distance << std::endl;
			mLOD = newLOD;

			for(int i = 0 ; i < mStaticEntities.size() ; i++)
			{
				mStaticEntities[i].setup(mWorld->getSceneMgr());
			}
		}
	}

	float Chunk::getDistanceFromCam()
	{
		float camX = mWorld->getEngine()->getCameraPosition().x;
		float camY = mWorld->getEngine()->getCameraPosition().y;
		float chuX = mPosX * size;
		float chuY = mPosY * size;

		return sqrt(abs((camX - chuX)*(camX - chuX) + (camY - chuY)*(camY - chuY)));
	}

	LevelOfDetail Chunk::getLOD()
	{
		return mLOD;
	}
}