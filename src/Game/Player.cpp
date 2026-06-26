#include <cmath>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <Entity.h>
#include <Camera.h>


class Player : public Entity {
	public:
		Player() {
			// Initialize player properties
		}

		
		
	private:
		float speed = 5.0f;
		float jumpVelocity = 10.0f;
		Camera camera;
		
 };