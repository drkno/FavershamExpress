#pragma once

#include <math.h>
#include <GL/freeglut.h>

class Scene
{
public:
	Scene();
	void display();

private:
	void floor();
	void initialize();
};

