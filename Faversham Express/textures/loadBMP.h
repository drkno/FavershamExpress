//=====================================================================
// LoadBMP.h
// Minimal image loader for files in BMP format.
// Assumption:  24 bits per pixel
//
// Author:
// R. Mukundan, Department of Computer Science and Software Engineering
// University of Canterbury, Christchurch, New Zealand.
//
// Modified By:
// Matthew Knox
//=====================================================================

#pragma once

#include <iostream>
#include <fstream>
#include <GL/freeglut.h>

void loadBMP(std::string filename);