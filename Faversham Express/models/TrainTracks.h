#pragma once

#include <math.h>
#include "SceneObject.h"

class TrainTracks : public SceneObject
{
public:
	TrainTracks();

private:
	void draw();
	void track(float radius);
};

