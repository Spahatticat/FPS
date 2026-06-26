#include "Engine/Entity.h"

Entity::Entity(glm::vec3 pos)
	: position(pos), velocity(glm::vec3(0.0f)), acceleration(glm::vec3(0.0f)), active(true) {}

Entity::~Entity() = default;

void Entity::update(float deltaTime) {
	velocity += acceleration * deltaTime;
	position += velocity * deltaTime;
}

glm::vec3 Entity::getPosition() const {
	return position;
}

glm::vec3 Entity::getVelocity() const {
	return velocity;
}

bool Entity::isActive() const {
	return active;
}

void Entity::setPosition(glm::vec3 pos) {
	position = pos;
}

void Entity::setVelocity(glm::vec3 vel) {
	velocity = vel;
}

void Entity::setActive(bool state) {
	active = state;
}

bool Entity::checkCollision(Entity* other) {
	(void)other;
	return false;
}

bool Entity::checkCollision(glm::vec3 point) {
	(void)point;
	return false;
}
