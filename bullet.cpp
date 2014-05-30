#include "entity.h"
#include "bullet.h"

#include <GL/gl.h>
#include <math.h>

bullet::bullet(float x, float y, float rotation) : entity(x, y, 0.5f) {
	this->rotation = rotation;
}

void bullet::update(float time) {
	x -= 0.1f*sin((M_PI/180)*rotation);
	y += 0.1f*cos((M_PI/180)*rotation);
}

void bullet::draw(void) {
	glPushMatrix();
	
	glTranslatef(x, y, 0);
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);

	glBegin(GL_LINES);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.1f, 0.0f);
	glEnd();

	glPopMatrix();
}