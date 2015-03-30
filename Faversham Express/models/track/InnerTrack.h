#pragma once

#include "OuterTrack.h"

class InnerTrack : public OuterTrack
{
public:
	InnerTrack();
	float getX(float, float);
	float getZ(float, float);
};

