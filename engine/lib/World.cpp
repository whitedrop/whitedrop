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
	void World::addStaticEntity(StaticEntity entity, std::shared_ptr<Chunk> chunk)
	{
		chunk->addStaticEntity(entity);
	}
	
	void World::setup(void)
	{
		typedef std::map<int, std::shared_ptr<Chunk>>::iterator it_type;
		for (it_type iterator = mChunks.begin(); iterator != mChunks.end(); iterator++) {
			iterator->second->setup();
		}
	}
	bool World::update(void)
	{
		typedef std::map<int, std::shared_ptr<Chunk>>::iterator it_type;
		for (it_type iterator = mChunks.begin(); iterator != mChunks.end(); iterator++) {
			iterator->second->update();
		}

		return(true);
	}

	std::shared_ptr<Chunk> World::getChunkAt(int x, int y)
	{

		int pos = x + y * 130;
		if (!mChunks.count(pos))
		{

			mChunks[pos] = std::make_shared<Chunk>(this, x, y);
			return getChunkAt(x, y);
		}
		
		std::shared_ptr<Chunk> chunk = mChunks.find(pos)->second;

		return chunk;
	}
}