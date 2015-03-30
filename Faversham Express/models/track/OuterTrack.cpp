#include "OuterTrack.h"

float OuterTrack::getX(float angle, float radiusAddition)
{
	return (TrackMaxRadius + radiusAddition) * cos(angle * CDR);
}

float OuterTrack::getZ(float angle, float radiusAddition)
{
	return (TrackMinRadius + radiusAddition) * sin(angle * CDR);
}

float OuterTrack::getNormalX(float x, float radiusAddition)
{
	return x*(TrackMinRadius + radiusAddition) / (TrackMaxRadius + radiusAddition);
}

float OuterTrack::getNormalZ(float z, float radiusAddition)
{
	return z*(TrackMaxRadius + radiusAddition) / (TrackMinRadius + radiusAddition);
}

float OuterTrack::getTangentAngle(float x1, float z1, float x2, float z2)
{
	return 0.0;
}