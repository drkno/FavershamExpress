#include "InnerTrack.h"

InnerTrack::InnerTrack()
{
	TrackMinRadius = 102;
	TrackMaxRadius = 204;
}

float InnerTrack::getX(float angle, float radiusAddition)
{
	return OuterTrack::getX(-angle, radiusAddition);
}

float InnerTrack::getZ(float angle, float radiusAddition)
{
	return OuterTrack::getZ(-angle, radiusAddition);
}