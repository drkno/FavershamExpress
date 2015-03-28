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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	windowScene->display();
	glutSwapBuffers();
}
