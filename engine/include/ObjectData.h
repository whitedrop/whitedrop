#ifndef OBJECTDATA_H
#define OBJECTDATA_H

#include "base.h"
#include <string>
#include <map>
#include <utility>
#include "LOD.h"


namespace Whitedrop {

	typedef std::pair<std::string, std::string> string_couple ;
	/**
	 * @class ObjectData
	 * @brief pairs of meshes and material according to LODs
	 */
	class ObjectData {

		public:
			/**
			 * @brief default ctor
			 */
			ObjectData();

			/**
			 * @brief create an object data according to param
			 * 
			 * @param lods a map of pairs of mesh name and material name according to LOD
			 */
			ObjectData(std::map<int, string_couple> lods);

			/**
			 * @brief dtor
			 */
			~ObjectData();


			string_couple get(int i);
			/**
			 * @brief bracket operator overloading
			 * @details get a pait according to LOD index
			 * 
			 * @param i the LOD index
			 * @return a pair of mesh and material
			 */
			string_couple operator [](int i) const;

		protected:
			std::map<int, string_couple> 		mLODs;
	};
}

#endif