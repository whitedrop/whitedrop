#include "parser/include/parser.h"
#include "engine/include/Whitedrop.h"
#include <string>
#include <utility>
// #include <boost/program_options.hpp>

// #include <iostream>
// #include <iterator>

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#include <windows.h>
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
#else 
int main(int argc, char* argv[])
#endif
{

	// namespace po = boost::program_options;

	// po::options_description desc("Allowed options");
	// desc.add_options()
	//     ("help", "produce help message")
	//     ("map", po::value<string>(), "set path to map")
	//     ("lod", "create a test map for lods")
	// ;
	
	// po::variables_map vm;
	// po::store(po::parse_command_line(ac, av, desc), vm);
	// po::notify(vm);    
	
	// if (vm.count("help")) {
	//     cout << desc << "\n";
	//     return 1;
	// }
	// if()
	// if (vm.count("map")) {
	//     std::string map = vm["map"].as<string>();
	//  //    Parser::input(map);
	// 	// Parser::World world = Parser::load();
		
	// 	// if(Whitedrop::init())
	// 	// {
	// 	// 	for(int i=0; i < world.entities.size(); i++){
 // 	// 		  	std::string material = world.entities[i].material;
 // 	// 		  	std::string mesh = world.entities[i].mesh;
 // 	// 		  	std::string id = world.entities[i].id;
 // 	// 		  	Whitedrop::Vector3 pos = Whitedrop::Vector3(world.entities[i].position.x, world.entities[i].position.y, world.entities[i].position.y);
 // 	// 		  	Whitedrop::Vector3 dim = Whitedrop::Vector3(world.entities[i].dimensions.x, world.entities[i].dimensions.y, world.entities[i].dimensions.z);
	// 	// 		Whitedrop::spawnEntity(mesh, id, pos, dim, material);
	// 	// 	}		
			
	// 	// 	Whitedrop::run();
	
	// 	// }
	// }
	// else
	// {	
		int id = 0;

		// std::map<int, Whitedrop::string_couple> lod;
		// lod[0] = std::make_pair("cube.mesh", "");
		// lod[1] = std::make_pair("cube.mesh", "");
		// lod[2] = std::make_pair("cube.mesh", "");
		// lod[3] = std::make_pair("cube.mesh", "");
		// lod[4] = std::make_pair("cube.mesh", "");
		// lod[5] = std::make_pair("cube.mesh", "");
		// lod[6] = std::make_pair("cube.mesh", "");
		// lod[7] = std::make_pair("sphere.mesh", "");
		// lod[8] = std::make_pair("sphere.mesh", "");
		// lod[9] = std::make_pair("sphere.mesh", "");
		// lod[10] = std::make_pair("sphere.mesh", "");
		// Whitedrop::ObjectData data = Whitedrop::ObjectData(lod);
		if(Whitedrop::init())
		{
			for(int cX = 0 ; cX < 64 ; cX++)
			{
				for(int cY = 0 ;  cY < 64 ; cY++)
				{
					for( int x = 0 ; x < 2 ; x++)
					{
						for (int y= 0 ; y < 2 ; y++)
						{
							Whitedrop::spawnEntity(std::to_string(id++), Whitedrop::Vector3(cX * 16 + x * 8, 0, cY * 16 + y * 8), Whitedrop::Vector3(4,4,4), std::make_pair<int, int>(10, 5), "sphere.mesh", "",cX, cY);
							Whitedrop::spawnEntity(std::to_string(id++), Whitedrop::Vector3(cX * 16 + x * 8, 0, cY * 16 + y * 8), Whitedrop::Vector3(4,4,4), std::make_pair<int, int>(5, 3), "cube.mesh", "",cX, cY);
						}
					}
				}
			}
			Whitedrop::spawnEntity("0x2A", Whitedrop::Vector3(64 * 8, 0, 64 * 8), Whitedrop::Vector3(64*16,1,64*16), std::make_pair<int, int>(10, 0), "Wellington.mesh", "",0, 0);
						


			// Whitedrop::spawnEntity(std::to_string(0x2A), Whitedrop::Vector3(0, 0,0), Whitedrop::Vector3(4,4,4), std::make_pair<int, int>(10, 5), "sphere.mesh", "",0, 0);
			// Whitedrop::spawnEntity("s", Whitedrop::Vector3(0, 8,0), Whitedrop::Vector3(4,4,4), std::make_pair<int, int>(10, 5), "sphere.mesh", "",0, 0);
			// // Whitedrop::spawnEntity(std::to_string(0x2B), Whitedrop::Vector3(1, 1,1), Whitedrop::Vector3(4,4,4), std::make_pair<int, int>(10, 5), "sphere.mesh", "",0, 0);

			Whitedrop::run();
		}
	// }



	
    return 0;
}
