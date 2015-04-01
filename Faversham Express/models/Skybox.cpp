#include "Skybox.h"

Skybox::Skybox()
{
	loadGLTextures();
}

void Skybox::loadGLTextures()				// Load bitmaps And Convert To Textures
{
	// *** left ***
	texId[0] = loadTexture("./textures/leftn.tga", GL_REPLACE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	// *** front ***
	texId[1] = loadTexture("./textures/frontn.tga", GL_REPLACE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	// *** right ***
	texId[2] = loadTexture("./textures/rightn.tga", GL_REPLACE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	// *** back***
	texId[3] = loadTexture("./textures/backn.tga", GL_REPLACE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	// *** top ***
	texId[4] = loadTexture("./textures/topn.tga", GL_REPLACE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}

void Skybox::draw()
{
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	////////////////////// LEFT WALL ///////////////////////
	glBindTexture(GL_TEXTURE_2D, texId[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-400, -200, 400);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-400, -200, -400);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-400, 200., -400);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-400, 200, 400);
	glEnd();

	////////////////////// FRONT WALL ///////////////////////
	glBindTexture(GL_TEXTURE_2D, texId[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-400, -200, -400);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(400, -200, -400);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(400, 200, -400);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-400, 200, -400);
	glEnd();

	////////////////////// RIGHT WALL ///////////////////////
	glBindTexture(GL_TEXTURE_2D, texId[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(400, -200, -400);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(400, -200, 400);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(400, 200, 400);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(400, 200, -400);
	glEnd();


	////////////////////// REAR WALL ////////////////////////
	glBindTexture(GL_TEXTURE_2D, texId[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(400, -200, 400);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-400, -200, 400);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-400, 200, 400);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(400, 200, 400);
	glEnd();

	/////////////////////// TOP //////////////////////////
	glBindTexture(GL_TEXTURE_2D, texId[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-400, 200, -400);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(400, 200, -400);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(400, 200, 400);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-400, 200, 400);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
}