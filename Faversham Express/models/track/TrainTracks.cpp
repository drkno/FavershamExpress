#include "TrainTracks.h"

TrainTracks::TrainTracks(TrackDefinition* trackdef)
{
	trackDefinition = trackdef;
	txId = loadTexture("./textures/rails.bmp", GL_DIFFUSE);
}

//-------- Tracks  ----------------------------------------------------
void TrainTracks::draw()
{
	glColor4f(0.51, 0.45, 0.38, 1.0);
	track(5);   //Inner track has radius 115 units
	track(-5);   //Outer track has radius 125 units
	textureRectangles(-5);
}

//------- Rail Track ----------------------------------------------------
// A single circular track of specified radius
void TrainTracks::track(float radius)
{
	float x1, z1, x2, z2, x3, z3, x4, z4;  //four points of a quad
	float nx1, nx2, nx3, nx4, nz1, nz2, nz3, nz4; // normals

	glBegin(GL_QUADS);
	for (int i = 0; i < 360; i += 5)    //5 deg intervals
	{
		x1 = trackDefinition->getX(i, radius - 0.5); z1 = trackDefinition->getZ(i, radius - 0.5);
		x2 = trackDefinition->getX(i, radius + 0.5); z2 = trackDefinition->getZ(i, radius + 0.5);
		x3 = trackDefinition->getX(i + 5, radius + 0.5); z3 = trackDefinition->getZ(i + 5, radius + 0.5);
		x4 = trackDefinition->getX(i + 5, radius - 0.5); z4 = trackDefinition->getZ(i + 5, radius - 0.5);

		nx1 = trackDefinition->getNormalX(x1, radius - 0.5); nz1 = trackDefinition->getNormalZ(z1, radius - 0.5);
		nx2 = trackDefinition->getNormalX(x2, radius + 0.5); nz2 = trackDefinition->getNormalZ(z2, radius + 0.5);
		nx3 = trackDefinition->getNormalX(x3, radius + 0.5); nz3 = trackDefinition->getNormalZ(z3, radius + 0.5);
		nx4 = trackDefinition->getNormalX(x4, radius - 0.5); nz4 = trackDefinition->getNormalZ(z4, radius - 0.5);

		glNormal3f(0., 1., 0.);       //Quad 1 facing up
		glVertex3f(x1, 1.0, z1);
		glVertex3f(x2, 1.0, z2);
		glVertex3f(x3, 1.0, z3);
		glVertex3f(x4, 1.0, z4);

		glNormal3f(-nx1, 0.0, -nz1);   //Quad 2 facing inward
		glVertex3f(x1, 0.0, z1);
		glVertex3f(x1, 1.0, z1);
		glNormal3f(-nx4, 0.0, -nz4);
		glVertex3f(x4, 1.0, z4);
		glVertex3f(x4, 0.0, z4);

		glNormal3f(nx2, 0.0, nz2);   //Quad 3 facing outward
		glVertex3f(x2, 1.0, z2);
		glVertex3f(x2, 0.0, z2);
		glNormal3f(nx3, 0.0, nz3);
		glVertex3f(x3, 0.0, z3);
		glVertex3f(x3, 1.0, z3);
	}
	glEnd();
}

void TrainTracks::textureRectangles(float radius)
{
	float x1, z1, x2, z2, x3, z3, x4, z4;  //four points of a quad

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txId);
	glBegin(GL_QUADS);
	for (int i = 0; i < 360; i += 5)    //5 deg intervals
	{
		x1 = trackDefinition->getX(i, radius - 4); z1 = trackDefinition->getZ(i, radius - 4);
		x2 = trackDefinition->getX(i + 5, radius - 4); z2 = trackDefinition->getZ(i + 5, radius - 4);
		x3 = trackDefinition->getX(i, radius + 14); z3 = trackDefinition->getZ(i, radius + 14);
		x4 = trackDefinition->getX(i + 5, radius + 14); z4 = trackDefinition->getZ(i + 5, radius + 14);

		glNormal3f(0., 1., 0.);

		glTexCoord2f(0, 1);
		glVertex3f(x1, 0.01, z1);
		glTexCoord2f(0.25, 1);
		glVertex3f(x2, 0.01, z2);
		glTexCoord2f(0.25, 0);
		glVertex3f(x4, 0.01, z4);
		glTexCoord2f(0, 0);
		glVertex3f(x3, 0.01, z3);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}