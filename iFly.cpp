#include "stdafx.h"


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	XInitXCGUI();

	LoginWin login;
	if (!login.Create())
	{
		XRunXCGUI();
	}
	return 0;
}