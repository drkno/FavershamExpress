#pragma once

#include "SceneObject.h"
#include "Humanoid.h"

class TrainStation : public SceneObject
{
public:
	TrainStation();

private:
	const float depth = 64;
	GLuint txId;
	Humanoid* humanoid;
	float angle;
	static const float* points;
	void end(float, float);
	void draw();
	void body(float depth);
	void walkHuman();
};

