#pragma once

#include <math.h>
#include "../SceneObject.h"
#include "TrackDefinition.h"

class TrainTracks : public SceneObject
{
public:
	TrainTracks(TrackDefinition*);

private:
	TrackDefinition* trackDefinition;

	void draw();
	void track(float radius);
};

