#include "entity.h"
#include "ship.h"
#include "bullet.h"
#include "asteroid.h"

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

ship player = ship(0.0f, 0.0f);
asteroid asteroid1 = asteroid(0.0f, 0.0f, 0.0f, 0.0f);

const int entityLimit = 20;
entity* entities[entityLimit] = {&player, &asteroid1};
int entityCount = 2;

float lastTime = 0.0f;

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key == GLFW_KEY_UP)
	{
		player.thrust();
	}

	if (key == GLFW_KEY_DOWN)
	{
	}

	if (key == GLFW_KEY_LEFT)
	{
		player.rotate(3.5f);
	}

	if (key == GLFW_KEY_RIGHT)
	{
		player.rotate(-3.5f);
	}

	if (key == GLFW_KEY_SPACE)
	{
		if(entityCount < entityLimit)
		{
			//entities[entityCount] = new bullet(player.getX(), player.getY(), player.getRotation());;
			//entityCount++;
		}
	}
}

int main(void)
{
	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	
	while (!glfwWindowShouldClose(window))
	{
		float time = (float) glfwGetTime();

		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float) height;
		glViewport(0, 0, width, height);
		
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		for(int i = 0; i < entityCount; i++)
		{
	        //if(player.collidesWith(ball))
			//	printf("Collision!");
			entities[i]->update(time);
			entities[i]->draw();
		}
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
