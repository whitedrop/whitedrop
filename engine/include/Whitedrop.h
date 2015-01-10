/**
 * @file Whitedrop.h
 * @page WhitedropPage Whitedrop
 * @brief the main class. Ogre impl
 */
#ifndef WHITEDROP_H
#define WHITEDROP_H
#include "base.h"
#include "Vector3.h"
#include "World.h"
#include "Entity.h"
#include "LOD.h"
#include <map>
#include <utility>
/**
 * @namespace Whitedrop
 */
namespace Whitedrop {
	/**
	 * @class WhitedropEngine
	 * @brief the whitedrop engine main class
	 * @details this class implements OGRE main classes
	 */
	class WhitedropEngine : public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener, public OIS::MouseListener, OgreBites::SdkTrayListener
	{
		public:
			/**
			 * @brief ctor
			 */
			WhitedropEngine(void);

			/**
			 * @brief dtor
			 */
			virtual ~WhitedropEngine(void);

			/**
			 * @brief start the engine
			 * @details call setup and if done then starts rendering
			 */
			virtual void go();

			/**
			 * @brief Adds an entity to the engine's main world
			 * @details do it before go()
			 * 
			 * @param ent the entity to add
			 * @param x the x index for chunk
			 * @param y the y coordinate of chunk
			 */
			virtual void addEntity(Entity ent, int x, int y);

			/**
			 * @brief setup the engine
			 * @details steps are:
			 * 
			 * 1) setup plugins
			 * 2) setup resources
			 * 3) chooseSceneManager()
			 * 4) create camera and viewport
			 * 5) load resources
			 * 6) create scene and listener
			 * 
			 * @return successfully done
			 */
			virtual bool setup();

			/**
			 * @brief setup the Whitedrop::World with the sceneMgr
			 * @details call it after setup
			 * @deprecated
			 */
			virtual void setupWorld();

			virtual Position2 getCameraPosition();
			
		protected:

			/**
			 * @brief show configuration dialog
			 * @return cancelled
			 */
			virtual bool configure(void);

			/**
			 * @brief create the sceneMgr
			 */
			virtual void chooseSceneManager(void);

			/**
			 * @brief create a default cam
			 * @details pos: 100, 100, 800
			 */
			virtual void createCamera(void);

			/**
			 * @brief init OIS and listener
			 */
			virtual void createFrameListener(void);

			/**
			 * @brief add some lightings and setup world
			 */
			virtual void createScene(void); // Override me!

			/**
			 * @brief destroy scene just after exit
			 */
			virtual void destroyScene(void);

			/**
			 * @brief creates viewports
			 */
			virtual void createViewports(void);

			/**
			 * @brief setup resources from config
			 */
			virtual void setupResources(void);

			virtual void createResourceListener(void);
			virtual void loadResources(void);
				
			// Ogre::FrameListener
			virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
				
			// OIS::KeyListener
			virtual bool keyPressed( const OIS::KeyEvent &arg );
			virtual bool keyReleased( const OIS::KeyEvent &arg );
			// OIS::MouseListener
			virtual bool mouseMoved( const OIS::MouseEvent &arg );
			virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID 	id );
			virtual bool mouseReleased( const OIS::MouseEvent &arg, 	OIS::MouseButtonID id );
				
			// Ogre::WindowEventListener
			//Adjust mouse clipping area
			virtual void windowResized(Ogre::RenderWindow* rw);
			//Unattach OIS before window shutdown (very important under Linux)
			virtual void windowClosed(Ogre::RenderWindow* rw);
				
			Ogre::Root *mRoot;
			Ogre::Camera* mCamera;
			Ogre::SceneManager* mSceneMgr;
			Ogre::RenderWindow* mWindow;
			Ogre::String mResourcesCfg;
			Ogre::String mPluginsCfg;
			Ogre::OverlaySystem *mOverlaySystem;
				
			// OgreBites
			OgreBites::SdkTrayManager* mTrayMgr;
			OgreBites::SdkCameraMan* mCameraMan;       // basic camera controller
			OgreBites::ParamsPanel* mDetailsPanel;     // sample details panel
			bool mCursorWasVisible;                    // was cursor visible before 	dialog appeared
			bool mShutDown;
				
			//OIS Input devices
			OIS::InputManager* mInputManager;
			OIS::Mouse*    mMouse;
			OIS::Keyboard* mKeyboard;
	
			World mWorld;
	};

	const map<std::string, std::string> configuration;
	void set(std::string key, std::string value);
	/**
	 * @brief init world
	 * @return done?
	 */
	bool init();

	/**
	 * @brief run the simulation
	 */
	void run();

	/**
	 * @brief spawn an entity to the world
	 * @details therefore attach it to a chunk and the world
	 * 
	 * @param id the entity unique id
	 * @param position the position
	 * @param dims the dimensions
	 * @param data the ObjectData
	 * @param chunkX the chunk x coordinate 
	 * @param chunkY the chunk Y coordinate
	 */
	void spawnEntity(std::string id, Vector3 position, Vector3 dims, std::pair<int, int> lods, std::string material, std::string mesh, int chunkX, int chunkY);


}
#endif