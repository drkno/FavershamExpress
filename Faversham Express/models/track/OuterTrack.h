#pragma once

#include <math.h>
#include "TrackDefinition.h"

class OuterTrack : public TrackDefinition
{
public:
	float getX(float, float);
	float getZ(float, float);
	float getNormalX(float, float);
	float getNormalZ(float, float);
	float getTangentAngle(float, float, float, float);
	float getMaxRadius() { return TrackMaxRadius; }

protected:
	const float CDR = 3.14159265 / 180.0;		//Degrees to radians conversion factor
	int TrackMinRadius = 120;
	int TrackMaxRadius = 120;
};

