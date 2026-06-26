#ifndef INPUT_H
#define INPUT_H
#include <Engine/Event.h>

class Input {
	public:
		struct KeyboardUpdateEvent : Event {
			int key;
			bool pressed;

			KeyboardUpdateEvent(int key, bool pressed) {
				this->key = key;
				this->pressed = pressed;
			}
		};

		struct MouseMoveEvent : Event {
			double xPos;
			double yPos;

			MouseMoveEvent(double xPos, double yPos) {
				this->xPos = xPos;
				this->yPos = yPos;
			}
		};
		
		struct MouseButtonEvent : Event {
			int button;
			bool pressed;

			MouseButtonEvent(int button, bool pressed) {
				this->button = button;
				this->pressed = pressed;
			}
		};

};
#endif // INPUT_H