/**
 * @file Vector3.h
 * @page Vector3Page Vector3
 * @brief represents a 3d vector
 */

#ifndef _VECTOR3_
#define _VECTOR3_
#include "base.h"

namespace Whitedrop {
	/**
	 * @brief represents a 3d vector
	 * @details This object represents a 3d vector.
	 * It is used to avoid that the main function needs to talk with OGRE
	 * in order to reduce coupling
	 */
	class Vector3 {
	public:
		/**
		 * @brief main ctor
		 * @param x The x coordinate in meter
		 * @param y The y coordinate in meter
		 * @param z The z coordinate in meter
		 */
		Vector3(float x, float y, float z);

		/**
		 * @brief destructor
		 */
		virtual ~Vector3(void);

		/**
		 * @brief Returns an Ogre::Vector3 corresponding to this vector
		 * @details should be ovewritten in the feature by a cast operator
		 * @return the Ogre::Vector3 corresponding to the vector
		 **/
		virtual Ogre::Vector3 getOgreVector();

	protected:
		float mX;
		float mY;
		float mZ;
	};
}

#endif