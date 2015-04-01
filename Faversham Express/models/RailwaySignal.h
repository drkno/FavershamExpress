#pragma once

#include "SceneObject.h"
#include "TrackCallback.h"

#define GREEN_SIGNAL 0
#define RED_SIGNAL 1
#define ORANGE_SIGNAL 2
#define SIGNAL_OFFSET 3

class RailwaySignal : public SceneObject, public TrackCallback
{
public:
	RailwaySignal(float,float,float);
	void switchColour(int signalNumber, int colour);
	void locationReachedCallback(int);

private:
	float xPos;
	float zPos;
	float rotationAng;
	int signalChangeCount;
	int lastSignalChanged;

	int signalColours[2];
	void draw();
	void drawSignal(int);
};

