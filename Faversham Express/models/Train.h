#pragma once

#include <math.h>
#include <vector>
#include "SceneObject.h"
#include "Carriage.h"
#include "TrackCallback.h"
#include "track/TrackDefinition.h"

using namespace std;

#define ANGLE_STEP_SIZE 0.5
#define ANGLE_RATIO 0.0174532925
#define GL_SEPARATE_SPECULAR_COLOR 0x81FA
#define GL_LIGHT_MODEL_COLOR_CONTROL 0x81F8

class Train : public SceneObject
{
public:
	Train(int, TrackDefinition*, GLenum light, bool reverseDirection = false);
	void changeCameraViewAngle(int);
	void addNotificationAngle(TrackCallback*, float, int);

private:
	TrackDefinition* trackDefinition;
	vector<Carriage> carriages;
	float angle = 0.0;
	bool reverseDirection;
	GLenum light;
	int cameraViewAngle;
	vector<notification_t*> notifications;

	void base();
	void engine();
	void wagon();
	void draw();
	void drawCamera();
	float getCarrigeSeparationAngle(float);
	float getCarrigeSubtractionAngle(float, float, float);
	void setAngle(int);
};

