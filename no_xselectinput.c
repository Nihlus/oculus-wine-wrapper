/* The Oculus service calls XSelectInput on the X window that the game
 * gives it, but Windows games send the HWND instead, which causes the
 * service to fail. Using Wine, we'll remap that value to the actual
 * X Window ID. */

#define _GNU_SOURCE

#include <stdlib.h>
#include <dlfcn.h>

int XSelectInput(void* display, int w, long valuemask) {

	// Grab the original XSelectInput function
	void* (*native_XSelectInput)(void* display, int w, long valuemask);
	native_XSelectInput = dlsym(RTLD_NEXT, "XSelectInput");
	
	if (dlerror != NULL)
	{
		exit(1);
	}
	
	// Remap the HWND to the actual X Window ID with the help of wine
	// ...
	
	
    return 0;
    // return (*native_XSelectInput)(display, remappedID, valuemask);
}
