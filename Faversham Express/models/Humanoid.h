#pragma once
#include "../models/SceneObject.h"
class Humanoid : public SceneObject
{
public:
	Humanoid();

private:
	float theta, val;
	void draw();
};

