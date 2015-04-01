//======================================================================
// LoadRAW.h
// Image loader for files in RAW format.
// Assumption:  Colour image in RGB format (24 bpp) in interleaved order.
// Note: RAW format stores an image in top to bottom order, and will
//       appear vertically flipped.
// Author:
// R. Mukundan, Department of Computer Science and Software Engineering
// University of Canterbury, Christchurch, New Zealand.
//======================================================================

#pragma once

#include <iostream>
#include <fstream>
#include <GL/freeglut.h>

void loadRAW(std::string filename, int width, int height);
