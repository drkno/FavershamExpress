#include "Train.h"

extern GLUquadric *q;

//------- Base of engine, wagons (including wheels) --------------------
void Train::base()
{
	glColor4f(0.2, 0.2, 0.2, 1.0);   //The base is nothing but a scaled cube!
	glPushMatrix();
	glTranslatef(0.0, 4.0, 0.0);
	glScalef(20.0, 2.0, 10.0);     //Size 20x10 units, thickness 2 units.
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();					//Connector between wagons
	glTranslatef(11.0, 4.0, 0.0);
	glutSolidCube(2.0);
	glPopMatrix();

	//Wheels
	glColor4f(0.5, 0., 0., 1.0);
	glPushMatrix();
	glTranslatef(-8.0, 2.0, 5.1);
	gluDisk(q, 0.0, 2.0, 20, 2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(8.0, 2.0, 5.1);
	gluDisk(q, 0.0, 2.0, 20, 2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-8.0, 2.0, -5.1);
	glRotatef(180.0, 0., 1., 0.);
	gluDisk(q, 0.0, 2.0, 20, 2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(8.0, 2.0, -5.1);
	glRotatef(180.0, 0., 1., 0.);
	gluDisk(q, 0.0, 2.0, 20, 2);
	glPopMatrix();
}

//-- Locomotive ------------------------------------------------
void Train::engine()
{
	base();

	//Cab
	glColor4f(0.8, 0.8, 0.0, 1.0);

	glPushMatrix();
	glTranslatef(7.0, 8.5, 0.0);
	glScalef(6.0, 7.0, 10.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.0, 14.0, 0.0);
	glScalef(4.0, 4.0, 8.0);
	glutSolidCube(1.0);
	glPopMatrix();

	//Boiler
	glPushMatrix();
	glColor4f(0.5, 0., 0., 1.0);
	glTranslatef(4.0, 10.0, 0.0);
	glRotatef(-90.0, 0., 1., 0.);
	gluCylinder(q, 5.0, 5.0, 14.0, 20, 5);
	glTranslatef(0.0, 0.0, 14.0);
	gluDisk(q, 0.0, 5.0, 20, 3);
	glColor4f(1.0, 1.0, 0.0, 1.0);
	glTranslatef(0.0, 4.0, 0.2);
	gluDisk(q, 0.0, 1.0, 20, 2);  //headlight!


	glPopMatrix();
}

//--- A rail wagon ---------------------------------------------------
void Train::wagon()
{
	base();

	glColor4f(0.0, 1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(0.0, 10.0, 0.0);
	glScalef(18.0, 10.0, 10.0);
	glutSolidCube(1.0);
	glPopMatrix();
}


Train::Train()
{
	float grey[4] = { 0.2, 0.2, 0.2, 1.0 };
	float white[4] = { 1.0, 1.0, 1.0, 1.0 };

	q = gluNewQuadric();

	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, grey);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.01);
}