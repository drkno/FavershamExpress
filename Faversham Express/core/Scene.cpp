#include "Scene.h"
#include "../models/Stage.h"

GLUquadric *q;
Stage* stage;

void Scene::display()
{
	gluLookAt(-80, 50, 180, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	stage->display();
}

Scene::Scene()
{
	q = gluNewQuadric();
	glEnable(GL_LIGHTING);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	gluQuadricDrawStyle(q, GLU_FILL);
	glClearColor(BACKGROUND_COLOUR);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(PERSPECTIVE_PROJECTION);

	stage = new Stage();
}