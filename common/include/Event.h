#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H
// #include <boost/signals2.hpp>
#include <string>
#include <vector>
#include <functional>
#include <map>

namespace Whitedrop {

	class Event
	{
	public:
		Event() {}
		~Event() {}
	};

	class WorldEvent : public Event 
	{
	public:
		virtual void onUpdate(int timeSinceLastFrame);
		virtual void onExit();
		virtual void onStart();
	};
	extern std::vector<WorldEvent*> worldEvents;

};
#endif