#include "entity.h"
#include "ship.h"

#include <GL/gl.h>
#include <math.h>

ship::ship(float x, float y) : entity(x, y, 0.06f) {
	this->rotation = 0.0f;
}

float ship::getDx(void) {
	return dx;
}

float ship::getDy(void) {
	return dy;
}

float ship::getRotation(void) {
	return rotation;
}

void ship::setDx(float dx) {
	this->dx = dx;
}

void ship::setDy(float dy) {
	this->dy = dy;
}

void ship::setRotation(float rotation) {
	if(rotation >= 360.0f)
		rotation -= 360.0f;
	else if(rotation < 360.0f)
		rotation += 360.0f;

	this->rotation = rotation;
}

void ship::rotate(float amount) {
	this->setRotation(rotation + amount);
}

void ship::thrust(void) {
	float oldDx = dx;
	float oldDy = dy;

	dx -= 0.001f*sin((M_PI/180)*rotation);
	dy += 0.001f*cos((M_PI/180)*rotation);

	if(fabs(dx) > 0.05f)
		dx = oldDx;
	if(fabs(dy) > 0.05f)
		dy = oldDy;
}

void ship::update(float time) {
	x += dx;
	y += dy;

	if(x > 1.5f)
		x -= 3.0f;
	else if(x < -1.5f)
		x += 3.0f;

	if(y > 1.1f)
		y -= 2.2f;
	else if(y < -1.1f)
		y += 2.2f;
}

void ship::draw(void) {
	glPushMatrix();
	
	glTranslatef(x, y, 0);
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);

	glBegin(GL_LINE_LOOP);
		glVertex3f(0.0f, 0.09f, 0.0f);
		glVertex3f(0.06f, -0.06f, 0.0f);
		glVertex3f(0.0f, -0.03f, 0.0f);
		glVertex3f(-0.06f, -0.06f, 0.0f);
	glEnd();

	glPopMatrix();
}