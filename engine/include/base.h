/**
* @file base.h
* @brief this header includes every OGRE header
* @author vinz243
* @version 0.1.0
* @date 20/12/14
*/
#ifndef BASE_H
#define BASE_H


#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include <SdkTrays.h>
#include <SdkCameraMan.h>

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif


static inline float fastSqrt( float x )
{
// 	long i;
// 	float x2, y;
// 	const float threehalfs = 1.5F;
 
// 	x2 = number * 0.5F;
// 	y  = number;
// 	i  = * ( long * ) &y;                       // evil floating point bit level hacking
// 	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
// 	y  = * ( float * ) &i;
// 	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
// //      y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
 
// 	return y;

  unsigned int i = *(unsigned int*) &x;

  // adjust bias
  i  += 127 << 23;
  // approximation of square root
  i >>= 1;

  return *(float*) &i;
}

/**
 * @brief Faster exp() function using 256 iterations (n = 256)
 * @details This function is 360 times faster than math.h's 
 * But less accurate, mostly for large numbers
 * See http://codingforspeed.com/using-faster-exponential-approximation/
 * for more details
 * 
 * @param x the number
 * @return the exp
 */
static inline double exp256(double x) {
  x = 1.0 + x / 256.0;
  x *= x; x *= x; x *= x; x *= x;
  x *= x; x *= x; x *= x; x *= x;
  return x;
}


/**
 * @brief Faster exp() function using 1024 iterations (n = 1024)
 * @details This function is 330 times faster than math.h's 
 * But less accurate, mostly for large numbers
 * See http://codingforspeed.com/using-faster-exponential-approximation/
 * for more details
 * 
 * @param x the  number
 * @return the exp
 */
static inline double exp1024(double x) {
  x = 1.0 + x / 1024;
  x *= x; x *= x; x *= x; x *= x;
  x *= x; x *= x; x *= x; x *= x;
  x *= x; x *= x;
  return x;
}
struct Position2
{
	float x, y;
	explicit Position2(float a, float b): x(a), y(b) {}
};

#endif
