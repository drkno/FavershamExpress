#include <iostream>
#include "core/OpenGLManager.h"

#ifdef DEBUG
#if defined _WIN32
#define sleep(x) Sleep(1000*x)
#else
#include <unistd.h>
#endif
#endif

// Main entry point for the application
int main(int argc, char* argv[]) {

	// debugging enabled warning
	#ifdef DEBUG
		std::cout << "DEBUGGING ENABLED." << std::endl << "Disable this for release builds." << std::endl;
		std::cout << "This message will be dismissed after 3 seconds." << std::endl;
		sleep(3);
	#endif
	
	// Start the GUI.
	// Note: this should never, ever, ever be called multiple times...
	OpenGLManager::run(argc, argv);

	std::cout << "Shutting down..." << std::endl;
	return 0;
}