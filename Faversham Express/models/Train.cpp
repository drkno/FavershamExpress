#include "Train.h"

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
	gluDisk(SceneObject::q, 0.0, 2.0, 20, 2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(8.0, 2.0, 5.1);
	gluDisk(SceneObject::q, 0.0, 2.0, 20, 2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-8.0, 2.0, -5.1);
	glRotatef(180.0, 0., 1., 0.);
	gluDisk(SceneObject::q, 0.0, 2.0, 20, 2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(8.0, 2.0, -5.1);
	glRotatef(180.0, 0., 1., 0.);
	gluDisk(SceneObject::q, 0.0, 2.0, 20, 2);
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
	gluCylinder(SceneObject::q, 5.0, 5.0, 14.0, 20, 5);
	glTranslatef(0.0, 0.0, 14.0);
	gluDisk(SceneObject::q, 0.0, 5.0, 20, 3);
	glColor4f(1.0, 1.0, 0.0, 1.0);
	glTranslatef(0.0, 4.0, 0.2);
	gluDisk(SceneObject::q, 0.0, 1.0, 20, 2);  //headlight!


	glPopMatrix();
}

void Train::draw()
{
	angle += ANGLE_STEP_SIZE;
	if (angle >= 360.0) angle = 0.0;

	float lgt2_pos[] = { -10.0f, 14.0f, -120.0f, 1.0f };
	float spotDir[] = { -1.0, -1.0, 0.2 };
	glRotatef(angle, 0, 1, 0);

	glPushMatrix();
		glLightfv(GL_LIGHT1, GL_POSITION, lgt2_pos);
		glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDir);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 1.0, -120.0);
		engine();
	glPopMatrix();

	for (int i = 1; i <= carriages.size(); i++) {
		glPushMatrix();
			glRotatef((-10.5) * i, 0, 1, 0);
			glTranslatef(0.0, 1.0, -120.0);
			carriages[i-1].display();
		glPopMatrix();
	}
}

Train::Train(int carriagesCount)
{
	vector<Carriage> carriages;
	for (int i = 0; i < carriagesCount; i++) {
		carriages.push_back(Carriage());
	}
	this->carriages = carriages;

	float grey[4] = { 0.2, 0.2, 0.2, 1.0 };
	float white[4] = { 1.0, 1.0, 1.0, 1.0 };

	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, grey);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.01);
}