/**
 * @file LOD.h
 * @brief represents a LOD 
 * @author vinz243
 * @version 0.1.0
 * @see LevelOfDetail
 * @details
 */

#ifndef LOD_H
#define LOD_H

#include <cmath>
/**
 * @namespace Whitedrop
 */

namespace Whitedrop {
	/**
	 * @brief represents a LOD distance
	 * @details it ctor build a single struct w/ a single value
	 * distance from player to target in meters
	 * 
	 */
	struct LODDistance {
		int distance;
		explicit LODDistance(int d): distance(d) {}
	};

	/**
	 * @brief reprsents a levelm of detail from 0 to 10
	 * @details absolutely
	 */
	struct LODIndex
	{
		int index;
		explicit LODIndex(int i): index(i) {}
		
	};
	/**
	 * @class LevelOfDetail
	 * @brief represents the LOD of an entity, a chunk...
	 * @details it is prefered to a single int since we
	 * ensure this way the LOD is always correct.
	 * 
     * @code
     * 
     * // Example of usage:
     * LevelOfDetail lod = LevelOfDetail(LODDistance(entity.getDistanceToPlayer()));
     * 
     * // or...
     * 
     * LevelOfDetail lod = LevelOfDetail(LODIndex(5));
     * 
     * // for isnatnce
     * 
     * @endcode
	 * 
	 */
	class LevelOfDetail {
	public:

		/**
		 * @brief create a LevelOfDetail according to the distance
		 * @details 
		 * 
		 * @param dist the LODDistance strcut initialized with the distance in meters
		 */
		LevelOfDetail(LODDistance dist);

		/**
		 * @brief create a LevelOfDetail according to the specified LOD index
		 * @details 
		 * 
		 * @param index the LOD index
		 */
		LevelOfDetail(LODIndex index);
		/**
		* @brief default ctor
		* @details
		*/
		LevelOfDetail();

		/**
		 * @brief dtor
		 */
		~LevelOfDetail();

		int getIndex();

		/**
		 * @brief Overload `<`operator 
		 * @param b the second object to test
		 * @return whether b is superior to a
		 */
		bool LevelOfDetail::operator< (const LevelOfDetail& b) const;

		/**
		 * @brief Overload `<=` operator 
		 * @param b the second object to test
		 * @return whether b is superior or equal to a
		 */
		bool LevelOfDetail::operator<= (const LevelOfDetail& b) const;

		/**
		 * @brief Overload `>` operator 
		 * @param b the second object to test
		 * @return whether b is inferior to a
		 */
		bool LevelOfDetail::operator> (const LevelOfDetail& b) const;

		/**
		 * @brief Overload `>=` operator 
		 * @param b the second object to test
		 * @return whether b is inferior or equal to a
		 */
		bool LevelOfDetail::operator>= (const LevelOfDetail& b) const;

		/**
		 * @brief Overload `==` operator 
		 * @param b the second object to test
		 * @return whether b is equal to a
		 */
		bool LevelOfDetail::operator== (const LevelOfDetail& b) const;


		/**
		 * @brief Overload `==` operator 
		 * @param b the second object to test
		 * @return whether b is different from a
		 */
		bool LevelOfDetail::operator!= (const LevelOfDetail& b) const;
		
	protected:
		int mLOD = 0;
	};
	/**
	 * @fn float getLODFactor()
	 * @brief this determines the LOD factor. the lesser, the more detailed
	 * 
	 * @details The Level Of detail $\delta$, from 0 to 10, is given according
	 * to the distance $d$ and the factor $\alpha$ by:
	 * $\delta = 10 - \exp(d \cdot \alpha)$
	 * Of course it is rounded and maxed to 10
	 * @return [description]
	 */
	static float getLODFactor()
	{
		return 0.01f;
	} 
}
#endif