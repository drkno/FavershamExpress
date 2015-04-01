#pragma once

class TrackCallback
{
public:
	virtual void locationReachedCallback(int) = 0;
};

struct notification_t {
	TrackCallback* callback;
	float angle;
	int value;
};