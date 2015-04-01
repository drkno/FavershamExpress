#include "Barrier.h"

Barrier::Barrier(float rotationAngle, float xPos, float zPos, GLenum light, bool alternateFlash)
{
	this->alternateFlash = alternateFlash;
	this->light = light;
	rotation = rotationAngle;
	x = xPos;
	z = zPos;
	toggleIterator = 0;
	loweredState = 0;
	loweredAngle = -90;

	float grey[4] = { 0.2, 0.2, 0.2, 1.0 };
	float orange[4] = { 0.91, 0.46, 0.0, 1.0 };

	glEnable(light);
	glLightfv(light, GL_DIFFUSE, orange);
	glLightfv(light, GL_SPECULAR, orange);
	glLightf(light, GL_SPOT_CUTOFF, 40.0);
	glLightf(light, GL_SPOT_EXPONENT, 0.01);
}

void Barrier::draw()
{
	switch (loweredState)
	{
		case 1:	// lowering
		{
			loweredAngle += 5;
			if (loweredAngle >= 0)
			{
				loweredAngle = 0;
				loweredState = 2;
			}
			break;
		}
		case 3:	// raising
		{
			loweredAngle -= 5;
			if (loweredAngle <= -90)
			{
				loweredAngle = -90;
				loweredState = 0;
			}
			break;
		}
	}

	if (toggleIterator > 30) toggleIterator = 0;
	
	glEnable(GL_LIGHTING);
	float lgt2_pos[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float spotDir[] = { -0.5, -1.0, 0.0 };

	glTranslatef(x, 0, z);
	glRotatef(rotation, 0, 1, 0);


	// pole
	glPushMatrix();
		glColor3f(1, 1, 1);
		glRotatef(-90, 1, 0, 0);
		gluCylinder(SceneObject::q, 1.5, 1.5, 25.0, 20, 5);
	glPopMatrix();
	glPushMatrix();
		glColor3f(1, 1, 1);
		glRotatef(-90, 0, 1, 0);
		glTranslatef(0, 25, -6);
		gluCylinder(SceneObject::q, 1.0, 1.0, 12.0, 20, 5);
	glPopMatrix();

	glPushMatrix();
		if (!alternateFlash && loweredState != 0 && toggleIterator > 15 ||
			alternateFlash && loweredState != 0 && toggleIterator <= 15)
		{
			glEnable(light);
			glTranslatef(0, 25, -1);
			glLightfv(light, GL_POSITION, lgt2_pos);
			glLightfv(light, GL_SPOT_DIRECTION, spotDir);
		}
		else if (loweredState == 0)
		{
			glDisable(light);
		}
	glPopMatrix();

	// light 1
	glPushMatrix();
		glTranslatef(-5.0, 25.0, -1.0);
		drawLight(loweredState != 0 && toggleIterator > 15);
	glPopMatrix();

	// light 2
	glPushMatrix();
		glTranslatef(5.0, 25.0, -1.0);
		drawLight(loweredState != 0 && toggleIterator <= 15);
	glPopMatrix();

	glColor3f(1, 1, 1);
	glTranslatef(0, 10, 3);

	glRotatef(loweredAngle, 0, 0, 1);

	glPushMatrix();
		glutSolidCube(4);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-25, 0, 0);
		glScalef(50, 2, 2);
		glutSolidCube(1.0);
	glPopMatrix();

	toggleIterator++;
}

void Barrier::drawLight(bool on)
{
	glPushMatrix();
		glColor3f(0, 0, 0);
		gluDisk(SceneObject::q, 0.0, 4.0, 20, 3);
		glTranslatef(0, 0, -0.5);
		gluDisk(SceneObject::q, 0.0, 4.0, 20, 3);
		glColor3f(1, 1, 1);
		gluCylinder(SceneObject::q, 4.0, 4.0, 0.5, 20, 5);
		glPushMatrix();
			if (on) glColor3f(0.91, 0.46, 0);
			else glColor3f(0, 0, 0);
			glTranslatef(0, 0, -0.01);
			glDisable(GL_LIGHTING);
			gluDisk(SceneObject::q, 0.0, 2.0, 20, 3);
			glEnable(GL_LIGHTING);
		glPopMatrix();
		glColor3f(0, 0, 0);
		glTranslatef(0, 0, -2);
		gluCylinder(SceneObject::q, 2.5, 2.5, 2, 20, 5);
	glPopMatrix();
}

void Barrier::toggleBarrier()
{
	switch (loweredState)
	{
	case 0: loweredState = 1; break;	// up
	case 1: loweredState = 3; break;	// lowering
	case 2: loweredState = 3; break;	// down
	case 3: loweredState = 1; break;	// lifting
	}
}

void Barrier::locationReachedCallback(int)
{
	toggleBarrier();
}