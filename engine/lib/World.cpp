#include "../include/World.h"

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
	void World::addEntity(Entity entity)
	{
		if(entity.type == "STATIC") {
			staticEntities.push_back(entity);
		}
	}
	
	void World::setup(void)
	{
		for(int i = 0; i < staticEntities.size(); i++){
	   		staticEntities[i].setup(mSceneMgr);
		}
	}
	bool World::update(void)
	{
		return(true);
	}

}