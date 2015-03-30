#pragma once

#include <math.h>
#include "../SceneObject.h"
#include "TrackDefinition.h"

class TrainTracks : public SceneObject
{
public:
	TrainTracks(TrackDefinition*);

private:
	GLuint txId;
	TrackDefinition* trackDefinition;

	void draw();
	void track(float radius);
	void textureRectangles(float radius);
};

