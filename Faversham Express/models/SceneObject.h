#pragma once

#include <GL/freeglut.h>
#include "../textures/loadBMP.h"

class SceneObject
{
public:
	void display();
	static GLUquadric* getQuad();
	static void setQuad(GLUquadric*);

protected:
	static GLUquadric* q;
	virtual void draw();
	static GLuint loadTexture(std::string, GLint = GL_DIFFUSE);
};

