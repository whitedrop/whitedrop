
// #include "parser/include/parser.h"
// #include "engine/include/Whitedrop.h"


// #include "parser/include/parser.h"
// #include "engine/include/Whitedrop.h"
#include <string>
#include <functional>
#include <utility>

#define BOOST_ALL_NO_LIB

#include <boost/program_options.hpp>

#include <iostream>
//#include <iterator>
#include "scripting/v8/include/Interface.h"
#include "common/include/Event.h"
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#include <windows.h>

#include <shellapi.h>
#endif



#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32

int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
#else 
int main(int argc, char* argv[])
#endif

{


	Scribe::V8Interface v8Interface = Scribe::V8Interface();
	v8Interface.initialize();

 	for(Whitedrop::WorldEvent* event : Whitedrop::worldEvents)
 	{
 		event->onStart();
 	}
	// if(Whitedrop::init())
 // 	{
	// 	Whitedrop::run();

	// }

	// #if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	// 	int argc;
	// 	LPWSTR *argv = CommandLineToArgvW(GetCommandLineW(), &argc);
	// #endif 
	// namespace po = boost::program_options;

	// po::options_description desc("Allowed options");
	// desc.add_options()
	//     ("help", "produce help message")
	//     ("map", po::value<std::string>(), "set path to map. example: '../media/maps/basic-map.json'")
	//     ("lod", "create a test map for lods")
	// ;
	
	// po::variables_map vm;
	// po::store(po::parse_command_line(argc, argv, desc), vm);
	// po::notify(vm);    
	
	// if (vm.count("help")) {
	//     std::cout << desc << "\n";
	//     return 1;
	// }
	// // if()
	// if (vm.count("map")) {
	//     std::string map = vm["map"].as<std::string>();
	//     Parser::input(map);
	// 	Parser::World world = Parser::load();
		
	// 	if(Whitedrop::init())
	// 	{

	// 		typedef std::pair<int, int> int_couple;

	// 		for(int i=0; i < world.entities.size(); i++){

 // 			  	std::string material = world.entities[i].material;
 // 			  	std::string mesh = world.entities[i].mesh;
 // 			  	std::string id = world.entities[i].id;
 // 			  	std::cout << mesh << std::endl;
 // 			  	int_couple lods = std::make_pair<int, int>((int) world.entities[i].lods.x, (int) world.entities[i].lods.y);

 // 			  	Whitedrop::Vector3 pos = Whitedrop::Vector3(world.entities[i].position.x, world.entities[i].position.y, world.entities[i].position.y);
 // 			  	Whitedrop::Vector3 dim = Whitedrop::Vector3(world.entities[i].dimensions.x, world.entities[i].dimensions.y, world.entities[i].dimensions.z);

	// 			Whitedrop::spawnEntity(id, pos, dim, lods, mesh, material, world.entities[i].chunk.x, world.entities[i].chunk.y);
	// 		}		
			
	// 		Whitedrop::run();
	
	// 	}
	// }
	// else
	// {	
	// 	int id = 0;

	// 	if(Whitedrop::init())
	// 	{
	// 		for(int cX = 0 ; cX < 64 ; cX++)
	// 		{
	// 			for(int cY = 0 ;  cY < 64 ; cY++)
	// 			{
	// 				for( int x = 0 ; x < 2 ; x++)
	// 				{
	// 					for (int y= 0 ; y < 2 ; y++)
	// 					{
	// 						Whitedrop::spawnEntity(std::to_string(id++), Whitedrop::Vector3(cX * 16 + x * 8, 0, cY * 16 + y * 8), Whitedrop::Vector3(4,4,4), std::make_pair<int, int>(10, 5), "sphere.mesh", "",cX, cY);
	// 						Whitedrop::spawnEntity(std::to_string(id++), Whitedrop::Vector3(cX * 16 + x * 8, 0, cY * 16 + y * 8), Whitedrop::Vector3(4,4,4), std::make_pair<int, int>(5, 3), "cube.mesh", "",cX, cY);
	// 					}
	// 				}
	// 			}
	// 		}
	// 		Whitedrop::spawnEntity("0x2A", Whitedrop::Vector3(64 * 8, 0, 64 * 8), Whitedrop::Vector3(64*16,1,64*16), std::make_pair<int, int>(10, 0), "Wellington.mesh", "",0, 0);
						


	// 		// Whitedrop::spawnEntity(std::to_string(0x2A), Whitedrop::Vector3(0, 0,0), Whitedrop::Vector3(4,4,4), std::make_pair<int, int>(10, 5), "sphere.mesh", "",0, 0);
	// 		// Whitedrop::spawnEntity("s", Whitedrop::Vector3(0, 8,0), Whitedrop::Vector3(4,4,4), std::make_pair<int, int>(10, 5), "sphere.mesh", "",0, 0);
	// 		// // Whitedrop::spawnEntity(std::to_string(0x2B), Whitedrop::Vector3(1, 1,1), Whitedrop::Vector3(4,4,4), std::make_pair<int, int>(10, 5), "sphere.mesh", "",0, 0);

	// 		Whitedrop::run();
	// 	}
	// }

    return 0;
}
