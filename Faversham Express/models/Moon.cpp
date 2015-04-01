#include "Moon.h"

Moon::Moon(float x, float y, float z, GLenum light)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->light = light;

	q = gluNewQuadric();
	txId = loadTexture("./textures/Moon.raw", GL_REPLACE, 256, 128);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	float black[4] = { 0.0, 0.0, 0.0, 1.0 };
	float white[4] = { 1.0, 1.0, 1.0, 1.0 };
	float lightWhite[4] = { 1.0, 1.0, 1.0, 0.5 };

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f); 	 //Background
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(light);
	glLightfv(light, GL_AMBIENT, black);
	glLightfv(light, GL_DIFFUSE, white);
	glLightfv(light, GL_SPECULAR, white);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	gluQuadricDrawStyle(q, GLU_FILL);
	gluQuadricNormals(q, GLU_SMOOTH);
	gluQuadricTexture(q, GL_TRUE);
}


void Moon::draw()
{
	glTranslatef(x, y, z);

	const float moonLightColour[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	const float moonLightPos[] = { 0.0f, 0.0f, 0.0f };
	glColor4f(1.0, 1.0, 1.0, 1.0);        //Base colour
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, moonLightColour);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txId);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glPushMatrix();
		glRotatef(-90., 1.0, 0., 0.0);   //make the sphere axis vertical
		gluSphere(q, 40.0, 36, 17);
	glPopMatrix();
	glPushMatrix();
		glLightfv(light, GL_POSITION, moonLightPos);
	glPopMatrix();
}
