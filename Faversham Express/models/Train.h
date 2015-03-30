#pragma once

#include <vector>
#include "SceneObject.h"
#include "Carriage.h"
#include "track/TrackDefinition.h"

using namespace std;

#define ANGLE_STEP_SIZE 0.5
#define ANGLE_RATIO 0.0174532925

class Train : public SceneObject
{
public:
	Train(int, TrackDefinition*, bool reverseDirection = false);

private:
	TrackDefinition* trackDefinition;
	vector<Carriage> carriages;
	float angle = 0.0;
	bool reverseDirection;

	void base();
	void engine();
	void wagon();
	void draw();
	void drawCamera();
	float getCarrigeSeparationAngle(float);
	float getCarrigeSubtractionAngle(float, float, float);
};

