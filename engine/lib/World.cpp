#include "../include/World.h"
#include "../include/Chunk.h"
namespace Whitedrop {

	World::World(Ogre::SceneManager* sceneManager, WhitedropEngine* engine)
	{
		mSceneMgr = sceneManager;
		mEngine = engine;
	}
	World::World(void)
	{
	
	}
	World::~World(void)
	{
	
	}
	
	WhitedropEngine* World::getEngine()
	{
		return mEngine;
	}
	
	void World::setSceneMgr(Ogre::SceneManager* sceneManager)
	{
		mSceneMgr = sceneManager;
	}

	Ogre::SceneManager* World::getSceneMgr(void)
	{
		return mSceneMgr;
	}
	void World::addEntity(Entity entity, Chunk* chunk)
	{
		chunk->addEntity(entity);
	}
	
	void World::setup(void)
	{
		typedef std::map<int, Chunk*>::iterator it_type;
		for (it_type iterator = mChunks.begin(); iterator != mChunks.end(); iterator++) {
			iterator->second->setup();
		}
	}
	bool World::update(void)
	{
		return(true);
	}

	Chunk* World::getChunkAt(int x, int y)
	{

		int pos = x + y * 256;
		if (!mChunks.count(pos))
		{

			mChunks[pos] = new Chunk(this, x, y);
			return getChunkAt(x, y);
		}
		
		Chunk* chunk = mChunks.find(pos)->second;

		return chunk;
	}
}