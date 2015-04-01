#include "Carriage.h"


Carriage::Carriage()
{
}

//------- Base of engine, wagons (including wheels) --------------------
void Carriage::base()
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

//--- A rail wagon ---------------------------------------------------
void Carriage::draw()
{
	base();

	glEnable(GL_COLOR_MATERIAL);
	glColor4f(0.48, 0.81, 0.97, 1.0);
	glTranslatef(-9.0, 5.0, -5.0);

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1);
	glVertex3f(18, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(18, 10, 0);
	glTexCoord2f(1, 0);
	glVertex3f(0, 10, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(1, 0);
	glVertex3f(0, 0, 10);
	glTexCoord2f(0, 0);
	glVertex3f(18, 0, 10);
	glTexCoord2f(0, 1);
	glVertex3f(18, 10, 10);
	glTexCoord2f(1, 1);
	glVertex3f(0, 10, 10);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0, 10);
	glTexCoord2f(1, 0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(0, 10, 0);
	glTexCoord2f(0, 1);
	glVertex3f(0, 10, 10);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0, 0);
	glVertex3f(18, 0, 10);
	glTexCoord2f(1, 0);
	glVertex3f(18, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(18, 10, 0);
	glTexCoord2f(0, 1);
	glVertex3f(18, 10, 10);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(0, 10, 0);
	glVertex3f(18, 10, 0);
	glVertex3f(18, 10, 10);
	glVertex3f(0, 10, 10);
	glEnd();


	/*glEnable(GL_TEXTURE_2D);
	glColor4f(0.0, 1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(0.0, 10.0, 0.0);
	glScalef(18.0, 10.0, 10.0);
	glutSolidCube(1.0);
	glPopMatrix();*/

}
