#pragma once

#include <GL/freeglut.h>
#include "../textures/loadBMP.h"
#include "../textures/loadTGA.h"
#include "../textures/loadRAW.h"

class SceneObject
{
public:
	void display();
	static GLUquadric* getQuad();
	static void setQuad(GLUquadric*);
	virtual void drawCamera();
	virtual void setAngle(int);
	virtual void changeCameraViewAngle(int);

protected:
	static GLUquadric* q;
	virtual void draw();
	static GLuint loadTexture(std::string, GLint, int = 0, int = 0);
};

