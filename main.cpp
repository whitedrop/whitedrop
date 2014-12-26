#include <windows.h>
#include "parser/include/parser.h"
#include "engine/include/Whitedrop.h"
#include <string>
int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
	Parser::input("../media/maps/basic-map.json");
	Parser::World world = Parser::load();
	
	if(Whitedrop::init())
	{
		for(int i=0; i < world.entities.size(); i++){
 		  	std::string material = world.entities[i].material;
 		  	std::string mesh = world.entities[i].mesh;
 		  	std::string id = world.entities[i].id;
 		  	Whitedrop::Vector3 pos = Whitedrop::Vector3(world.entities[i].position.x, world.entities[i].position.y, world.entities[i].position.y);
 		  	Whitedrop::Vector3 dim = Whitedrop::Vector3(world.entities[i].dimensions.x, world.entities[i].dimensions.y, world.entities[i].dimensions.z);
			Whitedrop::spawnEntity(mesh, id, pos, dim, material);
		}		
		
		Whitedrop::run();

	}
    return 0;
}