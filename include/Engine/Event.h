#ifndef EVENT_H
#define EVENT_H

#include <functional>
#include <vector>

struct Event { virtual ~Event() = default; };

template<typename T>
class EventBus {
	public:
		using EventHandler = std::function<void(const T&)>;

		void subscribe(const EventHandler& handler) {
			handlers.push_back(handler);
		}

		void emit(const T& event) {
			for (const auto& handler : handlers) {
				handler(event);
			}
		}
	private:
		std::vector<EventHandler> handlers;
};

#endif 