#pragma once

#include "SceneObject.h"

class Moon : public SceneObject
{
public:
	Moon(float, float, float, GLenum);

private:
	GLUquadric* q;
	float x, y, z;
	GLint txId;
	GLenum light;
	void draw();
};

