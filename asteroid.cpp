#include "entity.h"
#include "asteroid.h"

#include <GL/gl.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

asteroid::asteroid(float x, float y, float dx, float dy) : entity(x, y, 0.5f) {
	this->dx = dx;
	this->dy = dy;
	this->vertexes = 12;
	this->vertexX = (float*) malloc(vertexes*sizeof(float));
	this->vertexY = (float*) malloc(vertexes*sizeof(float));


	srand(4);
	float angle = 0;
	for(int i = 0; i < vertexes; i++)
	{
		float randRadius = radius*(0.95 + (rand() / (float)(RAND_MAX))/10);
		float randAngle = angle*(0.95 + (rand() / (float)(RAND_MAX))/10);
		printf("A: %f\n", randAngle);
		this->vertexX[i] = randRadius*sin(randAngle);
		this->vertexY[i] = randRadius*cos(randAngle);
		angle += M_PI/6;
	}
}

float asteroid::getDx(void) {
	return dx;
}

float asteroid::getDy(void) {
	return dy;
}

void asteroid::setDx(float dx) {
	this->dx = dx;
}

void asteroid::setDy(float dy) {
	this->dy = dy;
}

void asteroid::update(float time) {
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

void asteroid::draw(void) {
	glPushMatrix();
	
	glTranslatef(x, y, 0);

	float angle = 0.0f;
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i < vertexes; i++)
			glVertex3f(vertexX[i], vertexY[i], 0.0f);
	glEnd();

	glPopMatrix();
}