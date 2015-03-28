#include "Stage.h"

Stage::Stage()
{
	float grey[4] = { 0.2, 0.2, 0.2, 1.0 };
	float white[4] = { 1.0, 1.0, 1.0, 1.0 };
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, grey);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);

	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialf(GL_FRONT, GL_SHININESS, 50);
}

void Stage::display()
{
	float lgt1_pos[] = { 0.0f, 50.0f, 0.0f, 1.0f };  //light0 position (directly above the origin)
	glLightfv(GL_LIGHT0, GL_POSITION, lgt1_pos);   //light position
	floor();
}

//-- Ground Plane --------------------------------------------------------
void Stage::floor()
{
	float white[4] = { 1., 1., 1., 1. };
	float black[4] = { 0 };
	glColor4f(0.7, 0.7, 0.7, 1.0);
	glNormal3f(0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, black);  //No specular reflections from the floor.

	//The floor is made up of several tiny squares on a 200x200 grid. Each square has a unit size.
	glBegin(GL_QUADS);
	for (int i = -200; i < 200; i++)
	{
		for (int j = -200; j < 200; j++)
		{
			glVertex3f(i, 0.0, j);
			glVertex3f(i, 0.0, j + 1);
			glVertex3f(i + 1, 0.0, j + 1);
			glVertex3f(i + 1, 0.0, j);
		}
	}
	glEnd();

	glMaterialfv(GL_FRONT, GL_SPECULAR, white);  //Enable specular reflections for remaining objects
}