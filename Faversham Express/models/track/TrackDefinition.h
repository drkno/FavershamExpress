#pragma once

class TrackDefinition
{
public:
	virtual float getX(float, float = 0) = 0;
	virtual float getZ(float, float = 0) = 0;
	virtual float getNormalX(float, float) = 0;
	virtual float getNormalZ(float, float) = 0;
	virtual float getTangentAngle(float, float, float, float) = 0;
	virtual float getMaxRadius() = 0;
};

