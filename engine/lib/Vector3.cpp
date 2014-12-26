#include "../include/Vector3.h"

namespace Whitedrop {
	Vector3::Vector3(float x, float y, float z)
	{
		mX = x;
		mY = y;
		mZ = z;
	}
	Vector3::~Vector3(void)
	{

	}
	Ogre::Vector3 Vector3::getOgreVector()
	{
		return Ogre::Vector3(mX, mY, mZ);
	}

}