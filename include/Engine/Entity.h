#ifndef ENTITY_H
#define ENTITY_H

#include <glm/glm.hpp>

class Entity {
protected:
	glm::vec3 position;
	glm::vec3 velocity;
	glm::vec3 acceleration;
	bool active;

public:
	Entity(glm::vec3 pos = glm::vec3(0.0f));
	virtual ~Entity();

	virtual void update(float deltaTime);
	virtual void render() = 0;

	glm::vec3 getPosition() const;
	glm::vec3 getVelocity() const;
	bool isActive() const;

	void setPosition(glm::vec3 pos);
	void setVelocity(glm::vec3 vel);
	void setActive(bool state);

	virtual bool checkCollision(Entity* other);
	virtual bool checkCollision(glm::vec3 point);
};

#endif // ENTITY_H