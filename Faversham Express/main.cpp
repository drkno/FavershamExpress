#include <iostream>
#include "Startup.h"

#define DEBUG

#ifdef DEBUG
#include <iostream>
using namespace std;
#if defined _WIN32
#define sleep(x) Sleep(1000*x)
#endif
#endif

// Main entry point for the application
int main(int argc, char* argv[]) {

	// debugging enabled warning
	#ifdef DEBUG
		cout << "DEBUGGING ENABLED." << endl << "Disable this for release builds." << endl;
		cout << "This message will be dismissed after 3 seconds." << endl;
		sleep(3);
	#endif
	
	// Start the GUI.
	// Note: this should never, ever, ever be called multiple times...
	Startup::run(argc, argv);
	return 0;
}