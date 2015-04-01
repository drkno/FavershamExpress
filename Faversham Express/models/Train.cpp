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

	glDisable(GL_LIGHTING);
	glColor4f(1.0, 1.0, 0.0, 1.0);
	glTranslatef(0.0, 4.0, 0.2);
	gluDisk(SceneObject::q, 0.0, 1.0, 20, 2);  //headlight!
	glEnable(GL_LIGHTING);

	glPopMatrix();
}

float Train::getCarrigeSeparationAngle(float angle)
{
	return 2.6*cos((2 * 3.1415927*angle) / 360) + 7.9;
}

float Train::getCarrigeSubtractionAngle(float angle, float x, float z)
{
	float radius = sqrtf(powf(x, 2) + powf(z, 2));
	return atanf(radius) * 57.2957795;
}

void Train::draw()
{
	angle += reverseDirection ? ANGLE_STEP_SIZE : -ANGLE_STEP_SIZE;
	if (angle >= 360.0) angle = 0.0;
	else if (angle < 0.0) angle = 359.0;

	

	glPushMatrix();
		float x = trackDefinition->getX(reverseDirection ? -angle : angle);
		float z = trackDefinition->getZ(reverseDirection ? -angle : angle);

		glTranslatef(x, 1.0, z);

		glRotatef(trackDefinition->getTangentAngle(reverseDirection ? -angle : angle) + 90, 0, 1, 0);

		glPushMatrix();
			float lgt2_pos[] = { 0.0f, 14.0f, 0.0f, 1.0f };
			float spotDir[] = { -1.0, -1.0, 0.0 };
			//glRotatef(-90, 0, 1, 0);
			glLightfv(light, GL_POSITION, lgt2_pos);
			glLightfv(light, GL_SPOT_DIRECTION, spotDir);

		glPopMatrix();

		engine();
	glPopMatrix();

	float separateAngle = reverseDirection ? -angle : angle;
	for (int i = 1; i <= carriages.size(); i++)
	{
		glPushMatrix();
			separateAngle += trackDefinition->getSeparationAngle(separateAngle, 0);
			glTranslatef(trackDefinition->getX(separateAngle), 1.0, trackDefinition->getZ(separateAngle));
			glRotatef(trackDefinition->getTangentAngle(separateAngle) + 90, 0, 1, 0);

			carriages[i-1].display();
		glPopMatrix();
	}

	for (int i = 0; i < notifications.size(); i++)
	{
		if (notifications[i]->angle + ANGLE_STEP_SIZE > angle && notifications[i]->angle - ANGLE_STEP_SIZE < angle)
		{
			notifications[i]->callback->locationReachedCallback(notifications[i]->value);
		}
	}
}

void Train::drawCamera()
{
	float angle = reverseDirection ? -this->angle : this->angle;
	float x = trackDefinition->getX(angle);
	float z = trackDefinition->getZ(angle);
	float sub = trackDefinition->getSeparationAngle(angle, 0);
	float x1 = trackDefinition->getX(angle + sub);
	float z1 = trackDefinition->getZ(angle + sub);

	glRotatef(cameraViewAngle, 0, 1, 0);
	glTranslatef(0, -24, 0);
	gluLookAt(x1, 0, z1, x, 0, z, 0, 1, 0);
}

void Train::changeCameraViewAngle(int change)
{
	cameraViewAngle += change;
	if (cameraViewAngle < 0) cameraViewAngle = 359;
	if (cameraViewAngle >= 360) cameraViewAngle = 0;
}

void Train::setAngle(int angle)
{
	if (angle == 1)	cameraViewAngle = 0;
}

void Train::addNotificationAngle(TrackCallback* callback, float angle, int value)
{
	notification_t* notification = new notification_t();
	notification->callback = callback;
	notification->angle = angle;
	notification->value = value;
	notifications.push_back(notification);
}

Train::Train(int carriagesCount, TrackDefinition* trackdef, GLenum light, bool reverseDirection)
{
	this->light = light;
	this->reverseDirection = reverseDirection;
	trackDefinition = trackdef;
	vector<Carriage> carriages;
	for (int i = 0; i < carriagesCount; i++) {
		carriages.push_back(Carriage());
	}
	this->carriages = carriages;

	float grey[4] = { 0.2, 0.2, 0.2, 1.0 };
	float white[4] = { 1.0, 1.0, 1.0, 1.0 };

	glEnable(light);
	//glLightfv(light, GL_AMBIENT, white);
	glLightfv(light, GL_DIFFUSE, white);
	glLightfv(light, GL_SPECULAR, white);
	glLightf(light, GL_SPOT_CUTOFF, 35.0);
	glLightf(light, GL_SPOT_EXPONENT, 0.1);
}