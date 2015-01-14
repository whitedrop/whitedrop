#ifndef parser_h
#define parser_h
#include <string>
#include <vector>

namespace Parser {
	struct Vector2
	{
		float x;
		float y;
	};
	struct Vector3
	{
		float x;
		float y;
		float z;
	};
	struct Entity
	{
		Vector3 		position;
		Vector2 		chunk;
		Vector3			dimensions;
		std::string 	id;
		std::string 	mesh;
		std::string		material;
		Vector2 lods;
	};
	struct World
	{
		std::string 			name;
		std::string 			version;
		std::vector<Entity> 	entities;
	};

	/**
	* \brief read a map file
	* \param mapFile the absolute or relative path to the map-file.map
	*/
	void input(std::string mapFile);

	/**
	* \brief start building up the world
	*/
	World load();


}

#endif