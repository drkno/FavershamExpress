#include "InnerTrack.h"

InnerTrack::InnerTrack()
{
	TrackMinRadius = 100;
	TrackMaxRadius = 100;
}

float InnerTrack::getX(float angle, float radiusAddition)
{
	return OuterTrack::getX(-angle, radiusAddition);
}

float InnerTrack::getZ(float angle, float radiusAddition)
{
	return OuterTrack::getZ(-angle, radiusAddition);
}