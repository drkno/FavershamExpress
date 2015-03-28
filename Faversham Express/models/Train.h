#pragma once

#include <vector>
#include "SceneObject.h"
#include "Carriage.h"

using namespace std;

#define ANGLE_STEP_SIZE 0.5
#define ANGLE_RATIO 0.0174532925

class Train : public SceneObject
{
public:
	Train(int carriages);

private:
	vector<Carriage> carriages;
	float angle = 0.0;

	void base();
	void engine();
	void wagon();
	virtual void draw();
};

