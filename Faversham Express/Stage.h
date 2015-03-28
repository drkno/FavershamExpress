#pragma once

#include <GL/freeglut.h>

#define BACKGROUND_COLOUR 0.0, 0.0, 0.0, 0.0
#define PERSPECTIVE_PROJECTION 60., 1.0, 10.0, 1000.0

class Stage
{
public:
	Stage();
	void display();

private:
	void floor();
};

