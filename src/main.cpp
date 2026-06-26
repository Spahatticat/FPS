#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>
#include <Engine/Entity.h>
#include <Engine/Event.h>
#include <Engine/Input.h>
#include <string>

std::vector<Entity> worldRenderQueue;
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
EventBus<Input::KeyboardUpdateEvent> keyboardEventBus;
EventBus<Input::MouseMoveEvent> mouseMoveEventBus;
EventBus<Input::MouseButtonEvent> mouseButtonEventBus;

int main(int argc, char** argv) {
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	// Initialize GLFW
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	keyboardEventBus.subscribe([](const Input::KeyboardUpdateEvent& event) {
		std::cout << "Key " << (event.pressed ? "Pressed" : "Released") << ": " << event.key << std::endl;
	});

	mouseButtonEventBus.subscribe([](const Input::MouseButtonEvent& event) {
		std::cout << "Mouse Button " << (event.pressed ? "Pressed" : "Released") << ": " << event.button << std::endl;
	});

	// Create window
	GLFWwindow* window = glfwCreateWindow(1280, 720, "FPS Project", NULL, NULL);
	if (!window) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	// glfwSwapInterval(std::stoi(argv[1])); // Enable vsync

	glfwSetKeyCallback(window, KeyCallback);
	glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
		if (action == GLFW_PRESS) {
			mouseButtonEventBus.emit({button, true});
		} else if (action == GLFW_RELEASE) {
			mouseButtonEventBus.emit({button, false});
		}
	});

	// Main loop
	while (!glfwWindowShouldClose(window)) {

		// Clear screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.1, 0.1f, 0.1f, 1.0f);

		// Render here

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

		// std::cout << "Delta Time: " << deltaTime << " seconds" << std::endl;
	}

	// Cleanup
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		keyboardEventBus.emit({key, true});
	} else if (action == GLFW_RELEASE) {
		keyboardEventBus.emit({key, false});
	}
}