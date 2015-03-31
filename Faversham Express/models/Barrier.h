#pragma once

#include "SceneObject.h"

class Barrier : public SceneObject
{
public:
	Barrier(float, float, float);
	void toggleBarrier();

private:
	int toggleIterator;
	int loweredState;
	float loweredAngle;
	float rotation;
	float x;
	float z;

	void draw();
	void drawLight(bool);
};

