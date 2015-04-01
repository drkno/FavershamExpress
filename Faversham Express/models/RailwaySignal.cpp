#include "RailwaySignal.h"

RailwaySignal::RailwaySignal(float rotation, float x, float z)
{
	signalColours[0] = signalColours[1] = 0;
	xPos = x;
	zPos = z;
	rotationAng = rotation;
}


void RailwaySignal::switchColour(int signalNumber, int colour)
{
	signalColours[signalNumber] = colour;
}

void RailwaySignal::drawSignal(int signalNum)
{
	glPushMatrix();
		glColor3f(0, 0, 0);
		gluDisk(SceneObject::q, 0.0, 4.0, 20, 3);
		glTranslatef(0, 0, -0.5);
		gluDisk(SceneObject::q, 0.0, 4.0, 20, 3);
		glColor3f(1, 1, 1);
		gluCylinder(SceneObject::q, 4.0, 4.0, 0.5, 20, 5);
		glPushMatrix();
			glTranslatef(0, 0, -0.01);
			switch (signalColours[signalNum])
			{
			default:
			case 0: glColor3f(0, 1, 0); break; // green signal
			case 1: glColor3f(1, 0, 0); break; // red signal
			case 2: glColor3f(1, 0.55, 0); break; // orange signal
			}
			glDisable(GL_LIGHTING);
			gluDisk(SceneObject::q, 0.0, 1.0, 20, 3);
			glEnable(GL_LIGHTING);
		glPopMatrix();
		glColor3f(0, 0, 0);
		glTranslatef(0, 0, -2);
		gluCylinder(SceneObject::q, 1.5, 1.5, 2, 20, 5);
	glPopMatrix();
}

void RailwaySignal::draw()
{
	glTranslatef(xPos, 0, zPos);
	glRotatef(rotationAng, 0, 1, 0);

	// pole
	glPushMatrix();
		glColor3f(1, 1, 1);
		glRotatef(-90, 1, 0, 0);
		gluCylinder(SceneObject::q, 1.0, 1.0, 28.0, 20, 5);
	glPopMatrix();
	glPushMatrix();
		glColor3f(1, 1, 1);
		glRotatef(-90, 0, 1, 0);
		glTranslatef(0, 16, 0);
		gluCylinder(SceneObject::q, 1.0, 1.0, 6.0, 20, 5);
	glPopMatrix();

	// light 1
	glPushMatrix();
		glTranslatef(0, 25.0, -1.0);
		drawSignal(0);
	glPopMatrix();

	// light 2
	glPushMatrix();
		glTranslatef(-5, 16.0, -1.0);
		drawSignal(1);
	glPopMatrix();
}

void RailwaySignal::locationReachedCallback(int segment)
{
	switch (segment)
	{
	case 0: switchColour(0, 0); break;
	case 1: switchColour(0, 1); break;
	case 2: switchColour(0, 2); break;
	case 3: switchColour(1, 0); break;
	case 4: switchColour(1, 1); break;
	case 5: switchColour(1, 2); break;
	}
}
