#include "Scene.h"
#include "../models/Stage.h"
#include "../models/track/TrainTracks.h"
#include "../models/Train.h"
#include "../models/Tower.h"
#include "../models/TrainStation.h"
#include "../models/track/OuterTrack.h"
#include "../models/track/InnerTrack.h"
#include "../models/Skybox.h"
#include "../models/RailwaySignal.h"
#include "../models/Barrier.h"

Stage* stage;
Skybox* skybox;
Tower* tower;

// Train 1 + Tracks 1
Train* train1;
TrainTracks* trainTracks1;
TrackDefinition* trackDefinition1;
RailwaySignal* railwaySignal1;

// Train 2 + Tracks 2
Train* train2;
TrainTracks* trainTracks2;
TrackDefinition* trackDefinition2;
Barrier* railwayBarrier;

TrainStation* trainStation;

void Scene::display()
{
	static int toggleBarrierIterator = 0;
	if (toggleBarrierIterator == 100)
	{
		railwayBarrier->toggleBarrier();
		toggleBarrierIterator = -1;
	}
	toggleBarrierIterator++;

	drawCamera();

	stage->display();
	skybox->display();
	
	trainStation->display();

	trainTracks1->display();
	train1->display();

	trainTracks2->display();
	train2->display();

	tower->display();

	railwaySignal1->display();
	railwayBarrier->display();

	glFlush();
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
	train1 = new Train(4, trackDefinition1, GL_LIGHT1);
	trainTracks1 = new TrainTracks(trackDefinition1);
	railwaySignal1 = new RailwaySignal(-135, 0, -30);

	trackDefinition2 = new InnerTrack();
	train2 = new Train(6, trackDefinition2, GL_LIGHT2, true);
	trainTracks2 = new TrainTracks(trackDefinition2);
	railwayBarrier = new Barrier(0, 30, -135);
	railwayBarrier->toggleBarrier();

	trainStation = new TrainStation();

	cameraIndex = 3;
	changeCamera();
}

void Scene::special(int key, int x, int y)
{
	switch (key)
	{
	case -1:
	case GLUT_KEY_UP:	cameraIndex++; break;
	case GLUT_KEY_DOWN:	cameraIndex--; break;
	case GLUT_KEY_LEFT:
	case GLUT_KEY_RIGHT:
		{
			cameraIndex = 0;
			stage->changeCameraViewAngle(key == GLUT_KEY_LEFT ? -1 : 1);
			break;
		}
	}
	changeCamera();
}

void Scene::changeCamera()
{
	if (cameraIndex >= 7) cameraIndex = 0;
	if (cameraIndex < 0) cameraIndex = 6;
	switch (cameraIndex)
	{
	case 0: cameraObject = stage; stage->setAngle(-1); break;
	case 1: cameraObject = stage; stage->setAngle(0); break;
	case 2: cameraObject = stage; stage->setAngle(1); break;
	case 3: cameraObject = stage; stage->setAngle(2); break;
	case 4: cameraObject = stage; stage->setAngle(3); break;
	case 5: cameraObject = train1; break;
	case 6: cameraObject = train2; break;
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
	delete railwaySignal1;
}