#pragma once

#include <GL/freeglut.h>
#include "Scene.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define WINDOW_XPOS 50
#define WINDOW_YPOS 50
#define WINDOW_TITLE "Faversham Express"

class Startup
{
public:
	static void run(int argc, char** argv);

private:
	static Scene* windowScene;
	static void windowDisplayCallback();
};

