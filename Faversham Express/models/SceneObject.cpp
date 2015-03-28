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