#include "Scene.h"
#include "../models/Stage.h"
#include "../models/track/TrainTracks.h"
#include "../models/Train.h"
#include "../models/Tower.h"
#include "../models/TrainStation.h"
#include "../models/track/OuterTrack.h"
#include "../models/track/InnerTrack.h"
#include "../models/Skybox.h"

Stage* stage;
Skybox* skybox;
Tower* tower;

// Train 1 + Tracks 1
Train* train1;
TrainTracks* trainTracks1;
TrackDefinition* trackDefinition1;

// Train 2 + Tracks 2
Train* train2;
TrainTracks* trainTracks2;
TrackDefinition* trackDefinition2;

TrainStation* trainStation;

void Scene::display()
{
	drawCamera();

	stage->display();
	skybox->display();
	
	trainStation->display();

	trainTracks1->display();
	train1->display();

	trainTracks2->display();
	train2->display();

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
	skybox = new Skybox();
	tower = new Tower();

	trackDefinition1 = new OuterTrack();
	train1 = new Train(4, trackDefinition1);
	trainTracks1 = new TrainTracks(trackDefinition1);

	trackDefinition2 = new InnerTrack();
	train2 = new Train(6, trackDefinition2, true);
	trainTracks2 = new TrainTracks(trackDefinition2);

	trainStation = new TrainStation();

	changeCamera();
}

void Scene::special(int key, int x, int y)
{
	switch (key)
	{
	case -1:
	case GLUT_KEY_LEFT: {cameraIndex++; break; }
	case GLUT_KEY_RIGHT: {cameraIndex--; break; }
	}
	changeCamera();
}

void Scene::changeCamera()
{
	if (cameraIndex >= 3) cameraIndex = 0;
	if (cameraIndex < 0) cameraIndex = 2;
	switch (cameraIndex)
	{
	case 0: cameraObject = stage; break;
	case 1: cameraObject = train1; break;
	case 2: cameraObject = train2; break;
	}
}

void Scene::drawCamera()
{
	cameraObject->drawCamera();
}

Scene::~Scene()
{
	delete stage;
	delete skybox;
	delete trainStation;
	delete tower;
	delete train1;
	delete trainTracks1;
	delete trackDefinition1;
	delete train2;
	delete trainTracks2;
	delete trackDefinition2;
}