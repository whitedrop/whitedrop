#include "QuantumEntity.h"
#include <assert.h>
namespace Whitedrop {

	namespace Quantum {

		QEntity::QEntity()
		{

		}

		QEntity::QEntity(Pos pos, Dim dim, Rot rot)
		{
			position = pos;
			dimensions = dim;
			rotation = rot;
		}

		QEntity::~QEntity()
		{

		}

		void QEntity::update()
		{

		}

		Pos QEntity::getPosition()
		{
			return position;
		}

		void QEntity::setPosition(Pos pos)
		{
			position = pos;
		}


		Dim QEntity::getDimensions()
		{
			return dimensions;
		}

		void QEntity::setDimensions(Dim dim)
		{
			dimensions = dim;
		}


		Rot QEntity::getRotation()
		{
			return rotation;
		}

		void QEntity::setRotation(Rot rot)
		{
			rotation = rot;

		}
	}

}