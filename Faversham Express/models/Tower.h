#pragma once

#include <math.h>
#include "SceneObject.h"

class Tower: public SceneObject
{
public:
	Tower(float, float, float);

private:
	GLuint txId;			//Texture id
	float viewAngle = 0.0;	//Camera view angle
	float rotationAngle, xPos, zPos;

	void draw();
	void normal(float x1, float y1, float z1,
		float x2, float y2, float z2,
		float x3, float y3, float z3);
};

