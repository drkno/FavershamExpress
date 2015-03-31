#include "Humanoid.h"

Humanoid::Humanoid()
{
	val = 0;
}

void Humanoid::draw()
{
	const double conv = 0.0174532925;
	val += 5*conv;
	theta = cosf(val) * 20.0f;

	glScalef(1.7, 1.7, 1.7);

	glColor3f(1., 0.78, 0.06);		//Head
	glPushMatrix();
		glTranslatef(0, 7.7, 0);
		glutSolidCube(1.4);
	glPopMatrix();

	glColor3f(0., 0., 0.);			//Torso
	glPushMatrix();
		glTranslatef(0, 5.5, 0);
		glScalef(3, 3, 1.4);
		glutSolidCube(1);
	glPopMatrix();

	glColor3f(0., 0., 0.);			//Right leg
	glPushMatrix();
		glTranslatef(-0.8, 4, 0);
		glRotatef(-theta, 1, 0, 0);
		glTranslatef(0.8, -4, 0);
		glTranslatef(-0.8, 2.2, 0);
		glScalef(1, 4.4, 1);
		glutSolidCube(1);
	glPopMatrix();

	glColor3f(0., 0., 0.);			//Left leg
	glPushMatrix();
		glTranslatef(0.8, 4, 0);
		glRotatef(theta, 1, 0, 0);
		glTranslatef(-0.8, -4, 0);
		glTranslatef(0.8, 2.2, 0);
		glScalef(1, 4.4, 1);
		glutSolidCube(1);
	glPopMatrix();

	glColor3f(0., 0., 0.);			//Right arm
	glPushMatrix();
		glTranslatef(-2, 6.5, 0);
		glRotatef(theta, 1, 0, 0);
		glTranslatef(2, -6.5, 0);
		glTranslatef(-2, 5, 0);
		glScalef(1, 4, 1);
		glutSolidCube(1);
	glPopMatrix();

	glColor3f(0., 0., 0.);			//Left arm
	glPushMatrix();
		glTranslatef(2, 6.5, 0);
		glRotatef(-theta, 1, 0, 0);
		glTranslatef(-2, -6.5, 0);
		glTranslatef(2, 5, 0);
		glScalef(1, 4, 1);
		glutSolidCube(1);
	glPopMatrix();
}