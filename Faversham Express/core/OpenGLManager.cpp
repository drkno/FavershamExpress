#include "OpenGLManager.h"

Scene* OpenGLManager::windowScene = NULL;

void OpenGLManager::run(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(WINDOW_XPOS, WINDOW_YPOS);
	glutCreateWindow(WINDOW_TITLE);
	windowScene = new Scene();
	glutDisplayFunc(windowDisplayCallback);
	glutTimerFunc(CALLBACK_RATE, displayRefreshCallback, 0);
	glutReshapeFunc(windowReshapeCallback);
	glutMainLoop();
	windowScene->~Scene();
}

void OpenGLManager::windowDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	windowScene->display();
	glutSwapBuffers();
}

void OpenGLManager::displayRefreshCallback(int value)
{
	glutPostRedisplay();
	glutTimerFunc(CALLBACK_RATE, displayRefreshCallback, ++value);
}

void OpenGLManager::windowReshapeCallback(GLint newWidth, GLint newHeight)
{
	glViewport(0, 0, newWidth, newHeight);
}