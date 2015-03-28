#include "Scene.h"
#include "../models/Stage.h"
#include "../models/SceneObject.h"
#include "../models/TrainTracks.h"
#include "../models/Train.h"
#include "../models/Tower.h"

Stage* stage;
Tower* tower;
TrainTracks* trainTracks;
Train* train1;

void Scene::display()
{
	gluLookAt(-80, 50, 180, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	stage->display();
	trainTracks->display();
	train1->display();

	tower->display();
}

Scene::Scene()
{
	SceneObject::setQuad(gluNewQuadric());
	glEnable(GL_LIGHTING);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	gluQuadricDrawStyle(SceneObject::getQuad(), GLU_FILL);
	glClearColor(BACKGROUND_COLOUR);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(PERSPECTIVE_PROJECTION);

	stage = new Stage();
	tower = new Tower();
	trainTracks = new TrainTracks();
	train1 = new Train(4);
}