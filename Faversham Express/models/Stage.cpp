#include "Stage.h"

Stage::Stage()
{
	//txId = loadTexture("./textures/GrassTexture.bmp", GL_DIFFUSE);

	float grey[4] = { 0.2, 0.2, 0.2, 1.0 };
	float white[4] = { 1.0, 1.0, 1.0, 1.0 };

	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, grey);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);

	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialf(GL_FRONT, GL_SHININESS, 50);
	cameraAngle = 0;
	cameraViewAngle = 0;
}

void Stage::setAngle(int angle)
{
	cameraAngle = angle;
}

void Stage::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txId);

	float lgt1_pos[] = { 0.0f, 50.0f, 0.0f, 1.0f };  //light0 position (directly above the origin)
	glLightfv(GL_LIGHT0, GL_POSITION, lgt1_pos);   //light position
	floor();

	glDisable(GL_TEXTURE_2D);
}

void Stage::changeCameraViewAngle(int change)
{
	cameraViewAngle -= change;
}

void Stage::drawCamera()
{
	const float CDR = 3.14159265 / 180.0;		//Degrees to radians conversion factor
	switch (cameraAngle)
	{
	default:
	case -1: {
		float x = 196.0 * cosf((float)cameraViewAngle * CDR);
		float z = 196.0 * sinf((float)cameraViewAngle * CDR);
		gluLookAt(x, 50, z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		break;
	}
	case 0: gluLookAt(-139, 50, -139, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); break;
	case 1: gluLookAt(139, 50, -139, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); break;
	case 2: gluLookAt(139, 50, 139, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); break;
	case 3: gluLookAt(-139, 50, 139, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); break;
	}
	
}

//-- Ground Plane --------------------------------------------------------
void Stage::floor()
{
	const float textureScale = 0.03;
	float white[4] = { 1., 1., 1., 1. };
	float black[4] = { 0 };
	float green[4] = { 0.0, 1.0, 0.0, 1.0 };

	glColor4f(0.17, 0.22, 0.0, 1.0);
	glNormal3f(0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, black);  //No specular reflections from the floor.

	//The floor is made up of several tiny squares on a 200x200 grid. Each square has a unit size.
	glBegin(GL_QUADS);
	
	for (int i = -HALF_WIDTH; i < HALF_WIDTH; i++)
	{
		float x = (i + HALF_WIDTH) * textureScale;
		for (int j = -HALF_DEPTH; j < HALF_DEPTH; j++)
		{
			float z = (j + HALF_DEPTH) * textureScale;
			glTexCoord2f(x, z);
			glVertex3f(i, 0.0, j);
			glTexCoord2f(x, z + textureScale);
			glVertex3f(i, 0.0, j + 1);
			glTexCoord2f(x + textureScale, z + textureScale);
			glVertex3f(i + 1, 0.0, j + 1);
			glTexCoord2f(x + textureScale, z);
			glVertex3f(i + 1, 0.0, j);
		}
	}
	glEnd();

	glMaterialfv(GL_FRONT, GL_SPECULAR, white);  //Enable specular reflections for remaining objects
}