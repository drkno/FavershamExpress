#pragma once
#include <math.h>
#include "SceneObject.h"
class Humanoid : public SceneObject
{
public:
	Humanoid();

private:
	float theta, val;
	void draw();
};

