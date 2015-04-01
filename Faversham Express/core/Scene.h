#pragma once

#include <math.h>
#include <GL/freeglut.h>
#include "../models/SceneObject.h"

class Scene
{
public:
	Scene();
	~Scene();
	void display();
	void special(int, int, int);
	void key(unsigned char, int, int);

private:
	int cameraIndex = 0;
	SceneObject* cameraObject = NULL;

	void initialize();
	void drawCamera();
	void changeCamera();
};

