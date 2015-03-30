#include "SceneObject.h"

GLUquadric* SceneObject::q;

void SceneObject::display()
{
	glPushMatrix();
	draw();
	glPopMatrix();
}

void SceneObject::draw()
{
	throw "This class is abstract and should be overridden.";
}

void SceneObject::setQuad(GLUquadric* quad)
{
	q = quad;
}

GLUquadric* SceneObject::getQuad()
{
	return q;
}

//--------Loads a bitmap texture------------------------------------------
GLuint SceneObject::loadTexture(std::string texture, GLint param)
{
	GLuint textureId;
	glGenTextures(1, &textureId); 				// Create a Texture object
	glBindTexture(GL_TEXTURE_2D, textureId);		//Use this texture
	loadBMP(texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	//Set texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, param);
	return textureId;
}