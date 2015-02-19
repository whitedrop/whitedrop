#ifndef COMMON_H
#define COMMON_H
namespace Common {
	struct Vector2 {
		double x, y;
		explicit Vector2() : x(0), y(0) {}
		explicit Vector2(double x_, double y_): x(x_), y(y_) {}
	};
	struct Vector3 {
		double x, y, z;
		explicit Vector3() : x(0), y(0), z(0) {}
		explicit Vector3(double x_, double y_, double z_): x(x_), y(y_), z(z_) {}

	};

	struct Quaternion {
		double x, y, z, w;
		explicit Quaternion() : x(0), y(0), z(0), w(0) {}
		explicit Quaternion(double w_, double x_, double y_, double z_): w(w_), x(x_), y(y_), z(z_) {}

	};

	// struct Rotation : Quaternion {};
	typedef Quaternion Rotation;
	// struct Position3 : public Vector3 {};

	typedef Vector3 Position;
	typedef Vector3 Position3;
	typedef Vector2 Position2;

	// struct Position2 : public Vector2 {};

	// struct Dimensions3 : public Vector3 {};
	typedef Vector3 Dimensions;
	typedef Vector3 Dimensions3;
	typedef Vector2 Dimensions2;

	// struct Dimensions2 :  public Vector2 {};

}

#endif