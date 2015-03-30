#pragma once

#include <GL/freeglut.h>
#include <vector>
#include "Scene.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define WINDOW_XPOS 50
#define WINDOW_YPOS 50
#define WINDOW_TITLE "Faversham Express"
#define CALLBACK_RATE 10

class OpenGLManager
{
public:
	static void run(int argc, char** argv);

private:
	static Scene* windowScene;
	static void windowDisplayCallback();
	static void displayRefreshCallback(int value);
	static void windowReshapeCallback(GLint newWidth, GLint newHeight);
};

