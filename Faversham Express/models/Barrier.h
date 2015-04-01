#pragma once

#include "SceneObject.h"
#include "TrackCallback.h"

class Barrier : public SceneObject, public TrackCallback
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
	void locationReachedCallback(int);
};

