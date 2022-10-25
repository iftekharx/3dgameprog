#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{
	switch (msg) 
	{
	case WM_CLOSE:
		PostQuitMessage(10);
		break;

	}
	return DefWindowProc(hWnd, msg, wParam, lParam);


}

int CALLBACK WinMain(
	HINSTANCE hInstance, // creates instance for windows
	HINSTANCE hPrevInstance, // always null
	LPSTR lpCmdLine, // cmdline extra parameters recieved here
	int nCmdShow // how window should be showed : ignore this for now
) 
{
	// register window class
	const auto pClassName = L"h3dbutts";
	WNDCLASSEX wc = {0}; // this is a structure
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;

	RegisterClassEx(&wc);

	//create window instance
	HWND hWnd = CreateWindowEx(
		0, pClassName,
		L"Happy Hard Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr
	);





	
	ShowWindow(hWnd, SW_SHOW);
	
	MSG msg;
	BOOL gResult;
	
	while ((gResult =  GetMessage(&msg, nullptr, 0, 0)) > 0) // nullptr for all windows messsage 0,0 for not 
												// filter messages
	{
		TranslateMessage(&msg);

		DispatchMessage(&msg);

	}

	if (gResult == -1) 
	{
		return -1;
	}
	else {
		return msg.wParam;
	}

	

}

/*
* 1) windows -> class
*			 -> instance, Not C++
* 
* 2) messages
* UINT means unsigned int and auto means 
the value will determine its type
* 
*/