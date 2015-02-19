#ifndef QUANTUMENGINE_H
#define QUANTUMENGINE_H

#include <config.h>

namespace Whitedrop {
	namespace Quantum
	{

		enum Flags {
			NOT_WORKING = 0x0,
			WORKING = 0x1,
			PARTIAL = 0x2,
			DISABLED = 0x3,
			UNSTABLE = 0x4
		};
	}
}
#if QUANTUM_ENGINE == DEFAULT


#include "../default/include/DefaultQEngine.h"

#endif

#endif
