#pragma once

#include <math.h>
#include <GL/freeglut.h>

class Scene
{
public:
	Scene();
	~Scene();
	void display();

private:
	void initialize();
};

