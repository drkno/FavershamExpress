#include "OuterTrack.h"
#include <iostream>

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

float OuterTrack::getTangentAngle(float angle)
{
	float x = getX(angle - 0.5, 0) - getX(angle + 0.5, 0);
	float z = getZ(angle - 0.5, 0) - getZ(angle + 0.5, 0);

	float tangentAngle = atanf(x / z) / CDR;

	if (z < 0)
	{
		tangentAngle += 180;
	}

	return tangentAngle;
}

float OuterTrack::getSeparationAngle(float angle, float length)
{
	const float PI = 3.14159265;
	return 2.5 * cosf((2.0 * PI * angle) / 180.0) + 8.5;
}