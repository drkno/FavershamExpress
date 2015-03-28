#pragma once

#include <GL/freeglut.h>

class SceneObject
{
public:
	void display();

protected:
	static GLUquadric *q;

	virtual void draw();
};

