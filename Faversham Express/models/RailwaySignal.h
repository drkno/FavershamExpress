#pragma once

#include "SceneObject.h"
#include <cstdlib> 
#include <ctime> 

class RailwaySignal : public SceneObject
{
public:
	RailwaySignal(float,float,float);
	void switchColour(int signalNumber, int colour);

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

