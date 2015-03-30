#include "Scene.h"
#include "../models/Stage.h"
#include "../models/SceneObject.h"
#include "../models/track/TrainTracks.h"
#include "../models/Train.h"
#include "../models/Tower.h"
#include "../models/TrainStation.h"
#include "../models/track/OuterTrack.h"
#include "../models/track/InnerTrack.h"

Stage* stage;
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
	gluLookAt(-80, 50, 180, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	stage->display();
	
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
	tower = new Tower();

	trackDefinition1 = new OuterTrack();
	train1 = new Train(4, trackDefinition1);
	trainTracks1 = new TrainTracks(trackDefinition1);

	trackDefinition2 = new InnerTrack();
	train2 = new Train(6, trackDefinition2, true);
	trainTracks2 = new TrainTracks(trackDefinition2);

	trainStation = new TrainStation();
}

Scene::~Scene()
{
	delete stage;
	delete trainStation;
	delete tower;
	delete train1;
	delete trainTracks1;
	delete trackDefinition1;
	delete train2;
	delete trainTracks2;
	delete trackDefinition2;
}