#pragma once

#include <GL/freeglut.h>

class Train
{
public:
	Train();
	void display();

private:
	GLUquadric *q;

	void base();
	void engine();
	void wagon();
};

