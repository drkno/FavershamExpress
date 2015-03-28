#include "Startup.h"

Scene* Startup::windowScene = NULL;

void Startup::run(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(WINDOW_XPOS, WINDOW_YPOS);
	glutCreateWindow(WINDOW_TITLE);
	windowScene = new Scene();
	glutDisplayFunc(windowDisplayCallback);
	glutMainLoop();
}

void Startup::windowDisplayCallback()
{
	windowScene->display();
}
