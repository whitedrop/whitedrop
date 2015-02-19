#ifndef QUANTUM_ENTITY_H
#define QUANTUM_ENTITY_H
#include <Common.h>
namespace Whitedrop {

	namespace Quantum {

		typedef Common::Position3 Pos;
		typedef Common::Dimensions3 Dim;
		typedef Common::Rotation Rot;

		/**
		 * @brief Represents a QuantumEntity
		 * @details
		 * This class is the bridge between Whitedrop engine entities
		 * and the Physic Engine. This is only a header, and according
		 * to built quantum engine (Default, Bullet, ODE, HAVOK or Physx)
		 * it will bridge between this engine.
		 *
		 * This class was mainly created to be used by a Whitedrop entity
		 *
		 */
		class QEntity {
		public:

			/**
			 * @brief Default ctor
			 * @details create an entity at (0,0,0) with null dim and rotation
			 */
			QEntity();

			/**
			 * @brief Create an QEntity
			 * @details
			 *
			 * @param pos its position
			 * @param dim its dimensions
			 * @param rot its rotation
			 */
			QEntity(Pos pos, Dim dim, Rot rot = Rot(0, 0, 0, 0));

			/**
			 * @brief dtor
			 */
			~QEntity();

			/**
			 * @brief update pattern
			 */
			void update();

			/**
			 * @brief get position
			 * @details (updated)
			 * @return position
			 */
			Pos getPosition();
			// Rest is self-explicit
			void setPosition(Pos pos);

			Dim getDimensions();
			void setDimensions(Dim dim);

			Rot getRotation();
			void setRotation(Rot rot);
		protected:
			Pos position;
			Dim dimensions;
			Rot rotation;
		};
	}
}
#endif