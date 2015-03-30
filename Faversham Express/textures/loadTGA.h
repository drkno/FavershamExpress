//=====================================================================
// LoadTGA.h
// Image loader for files in TGA format.
// Assumption:  Uncompressed data.
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

void loadTGA(std::string filename);
