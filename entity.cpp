#include "entity.h"

entity::entity(float x, float y, float radius) {
	this->x = x;
	this->y = y;
	this->radius = radius;
}

float entity::getX(void) {
	return x;
}

float entity::getY(void) {
	return y;
}

float entity::getRadius(void) {
	return radius;
}

void entity::setX(float x) {
	this->x = x;
}

void entity::setY(float y) {
	this->y = y;
}

void entity::setRadius(float radius) {
	this->radius = radius;
}


// bool Entity::collidesWith(Entity otherEntity) {
// 	return (x <= otherEntity.getX() + otherEntity.getWidth() &&
// 			otherEntity.getX() <= x + width &&
// 			y <= otherEntity.getY() + otherEntity.getHeight() &&
// 			otherEntity.getY() <= y + height);
// }
