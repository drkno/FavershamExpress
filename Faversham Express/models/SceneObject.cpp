#include "SceneObject.h"

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