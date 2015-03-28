#pragma once

#include <GL/freeglut.h>

class SceneObject
{
public:
	void display();
	static GLUquadric* getQuad();
	static void setQuad(GLUquadric* quad);

protected:
	static GLUquadric* q;
	virtual void draw();
};

