#include <windows.h>

/*A callback is any executable code that is passed as
an argument to other code, which is expected to call
back (execute) the argument at a given time
*/
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, // id for application passed by os
	HINSTANCE hPrevInst,  //
	LPSTR args,  // characters in cmdline
	int ncmdshow) // commandline stuff)
{

	//                  msg			title
	//MessageBox(NULL, "HELLO", "My first GUI", MB_OK);


	WNDCLASSW wc = {0};

	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if(!RegisterClassW(&wc))// pass by reference

    {
        return -1;
    }

    CreateWindowW(L"myWindowClass",
                  L"My Window",
                  WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  100, 100, 500, 500, NULL, NULL,
                  NULL, NULL);

    MSG msg = {0}; // struct

    // Message Loop
    while( GetMessage(&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    };

	return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg,
                                 WPARAM wp, LPARAM lp)
{

    switch(msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }


}
