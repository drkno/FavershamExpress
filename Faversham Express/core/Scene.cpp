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
TrainStation* trainStation1;
Barrier* railwayBarrier1;

// Train 2 + Tracks 2
Train* train2;
TrainTracks* trainTracks2;
TrackDefinition* trackDefinition2;
Barrier* railwayBarrier2;
TrainStation* trainStation2;

void Scene::display()
{
	drawCamera();

	stage->display();
	skybox->display();
	
	trainStation1->display();
	trainStation2->display();

	trainTracks1->display();
	train1->display();

	trainTracks2->display();
	train2->display();

	//tower->display();

	railwaySignal1->display();
	railwayBarrier1->display();
	railwayBarrier2->display();

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

	railwayBarrier1 = new Barrier(180, 45, 130);
	train1->addNotificationAngle(railwayBarrier1, 90, 0);
	train1->addNotificationAngle(railwayBarrier1, 20, 0);
	train2->addNotificationAngle(railwayBarrier1, 50, 0);
	train2->addNotificationAngle(railwayBarrier1, 120, 0);

	railwayBarrier2 = new Barrier(0, 95, 75);
	train1->addNotificationAngle(railwayBarrier2, 90, 0);
	train1->addNotificationAngle(railwayBarrier2, 20, 0);
	train2->addNotificationAngle(railwayBarrier2, 50, 0);
	train2->addNotificationAngle(railwayBarrier2, 120, 0);

	trainStation1 = new TrainStation(90, -32, 92);
	trainStation2 = new TrainStation(-90, 32, 130);

	cameraIndex = 3;
	changeCamera();
}

void Scene::key(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1': cameraObject->setAngle(1); break;
	case '2': cameraObject->setAngle(2); break;
	case '3': cameraObject->setAngle(3); break;
	case '4': cameraObject->setAngle(4); break;
	case '5': cameraObject->setAngle(5); break;
	}
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
			cameraObject->changeCameraViewAngle(key == GLUT_KEY_LEFT ? -1 : 1);
			break;
		}
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
	delete tower;
	delete train1;
	delete trainTracks1;
	delete trackDefinition1;
	delete trainStation1;
	delete train2;
	delete trainTracks2;
	delete trackDefinition2;
	delete railwaySignal1;
	delete trainStation2;
}