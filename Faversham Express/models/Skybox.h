#pragma once

#include "SceneObject.h"

#define GL_CLAMP_TO_EDGE 0x812F   //To get rid of seams between textures

class Skybox : public SceneObject
{
public:
	Skybox();
private:
	GLuint texId[6];

	void loadGLTextures();
	void draw();
};

