#pragma once

#include "SceneObject.h"

class TrainStation : public SceneObject
{
public:
	TrainStation();

private:
	GLuint txId;
	static const float* points;
	void end(float, float);
	void draw();
	void body(float depth);
};

