#ifndef STATIC_LINK
#define IMPLEMENT_API
#endif

#if defined(HX_WINDOWS) || defined(HX_MACOS) || defined(HX_LINUX)
#define NEKO_COMPATIBLE
#endif

#if defined(HX_WINDOWS)
#include <windows.h>
#include <dwmapi.h>

#pragma comment(lib, "Dwmapi")
#endif


#include <hx/CFFI.h>
#include <hx/CFFIPrime.h>


#if defined(HX_WINDOWS)

#define DWMWA_WINDOW_CORNER_PREFERENCE 33

typedef enum DWM_WINDOW_CORNER_PREFERENCE {
    DWMWCP_DEFAULT    = 0,
    DWMWCP_DONOTROUND = 1,
    DWMWCP_ROUND      = 2,
    DWMWCP_ROUNDSMALL = 3
} DWM_WINDOW_CORNER_PREFERENCE;

static value windowcornerNDLL_set_corner (int corner) {
	HWND hWnd = GetActiveWindow();
	
	if (hWnd)
    {
        DWM_WINDOW_CORNER_PREFERENCE preference = (DWM_WINDOW_CORNER_PREFERENCE)corner;

        DwmSetWindowAttribute(
            hWnd,
            DWMWA_WINDOW_CORNER_PREFERENCE,
            &preference,
            sizeof(preference)
        );
    }

    return alloc_int(corner);
}
DEFINE_PRIME1 (windowcornerNDLL_set_corner);

#endif

extern "C" void windowcornerNDLL_main () {
	
	val_int(0); // Fix Neko init
	
}
DEFINE_ENTRY_POINT (windowcornerNDLL_main);



extern "C" int windowcornerNDLL_register_prims () { return 0; }