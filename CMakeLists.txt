cmake_minimum_required(VERSION 3.10)
project(FPS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find GLFW
find_package(glfw3 REQUIRED)

# Find GLM
find_package(glm REQUIRED)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Find Assimp
find_package(assimp REQUIRED)

# Collect source files from Engine directory
file(GLOB ENGINE_SOURCES "src/Engine/*.cpp")

# Add the executable
add_executable(fps ${ENGINE_SOURCES} src/glad.c src/main.cpp)
target_include_directories(fps PRIVATE include)

# Link libraries
target_link_libraries(fps PRIVATE glfw glm::glm OpenGL::GL assimp::assimp)

# Optional: Set output directory for built executable
set_target_properties(fps PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)