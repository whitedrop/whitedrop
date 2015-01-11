/**
 * @file parser.h
 * @page ParserPage
 */

#include "../include/parser.h"
#include "../include/picojson.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace picojson;
/**
 * @namespace Parser
 */
namespace Parser {
	
	std::string contents;
	/**
	* @brief read a map file
	* @param mapFile the absolute or relative path to the map-file.map
	*/
	void input(std::string mapFile)
	{

  		std::string line;
  		std::ifstream map (mapFile);
  		if (map.is_open())
  		{
  		  while ( getline (map, line) )
  		  {
  		    contents += line + '\n';
  		  }
  		  map.close();
  		}
	}

	/**
	 * @brief create a Parser::World object
	 * @details so parse json
	 * @return the world
	 */
	World load()
	{
		World world;
		value v;
		std::string err = parse(v, contents);
		if (! err.empty()) {
			return world;
		}
		object obj = v.get<object>();
		world.name = obj["worldName"].to_str();
		world.version = obj["worldVersion"].to_str();
		array arr = obj["entities"].get<array>();
      	array::iterator it;

     	for (it = arr.begin(); it != arr.end(); it++) {

        	object obj2 = it->get<object>();

	        Entity ent;
	        Vector3 pos;
	        Vector2 chunk;
	        Vector3 dim;
	        Vector2 lods;

			pos.x = std::stoi(obj2["posX"].to_str());
			pos.y = std::stoi(obj2["posY"].to_str());
			pos.z = std::stoi(obj2["posZ"].to_str());
			dim.x = std::stoi(obj2["dimX"].to_str());
			dim.y = std::stoi(obj2["dimY"].to_str());
			dim.z = std::stoi(obj2["dimZ"].to_str());
			chunk.x = std::stoi(obj2["chunkX"].to_str());
			chunk.y = std::stoi(obj2["chunkY"].to_str());
			lods.x = std::stoi(obj2["minLOD"].to_str());
			lods.y = std::stoi(obj2["maxLOD"].to_str());
			
			if(!obj2["material"].is<picojson::null>())
				ent.material = obj2["material"].to_str();
	        ent.id = 	obj2["id"].to_str();
	        ent.mesh = 	obj2["mesh"].to_str();
	        ent.position = pos;
	        ent.chunk = chunk;
	        ent.lods = lods;
	        ent.dimensions = dim;
	        world.entities.push_back(ent);
	    }
		return(world);
	}


}
