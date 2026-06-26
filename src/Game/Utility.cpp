#include <glm/glm.hpp>
#include <memory>
#include "Entity.h"

class Utility: public Entity
{
public:
	Utility() = default;
	virtual ~Utility() = default;

	void update(float deltaTime) override {
		lifetime += deltaTime;
	}

protected:
	float lifetime{0.0f};
};