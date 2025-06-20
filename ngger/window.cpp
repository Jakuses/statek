#include "window.h"
#include "asteroid.h"
#include <iostream>

LRESULT Wndproc(
	HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
) {
	window* wnd = (window*)GetWindowLongPtrW(hWnd, GWLP_USERDATA);
	switch (uMsg) {
	case WM_KEYDOWN:
		wnd->keys[wParam] = 1; 
		break;
	case WM_KEYUP:
		wnd->keys[wParam] = 0;
		break;
	case WM_LBUTTONDOWN:
		wnd->keys[0] = 1;
		break;
	case WM_LBUTTONUP:
		wnd->keys[0] = 0;
		break;
	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		for (auto& txt : wnd->texttoDraw) {
			SetTextColor(hdc, RGB(txt.r, txt.g, txt.b));
			SetBkMode(hdc, TRANSPARENT);
			HFONT hFont = CreateFont(
				txt.h,
				0,
				0,
				0,
				FW_EXTRALIGHT,
				FALSE,
				FALSE,
				FALSE,
				DEFAULT_CHARSET,
				OUT_OUTLINE_PRECIS,
				CLIP_DEFAULT_PRECIS,
				CLEARTYPE_QUALITY,
				VARIABLE_PITCH,
				L"Arial"
			);
			HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
			std::wstring text1 = L"dupa";
			TextOut(hdc, txt.x, txt.y, text1.c_str(), text1.length());
			RECT textRect = { 10, 100, 380, 200 }; // Lewo, Góra, Prawo, Dół
			std::wstring text2 = L"To jest tekst narysowany funkcja DrawText. Mozna go wycentrowac.";

			// Rysujemy tekst wyśrodkowany w prostokącie
			DrawText(hdc, text2.c_str(), -1, &textRect, DT_CENTER | DT_VCENTER | DT_WORDBREAK);
			SelectObject(hdc, hOldFont);
			DeleteObject(hFont);
			EndPaint(hWnd, &ps);
			break;
		}
	}
	}
	return DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

void window::createWindowclass()
{
	WNDCLASS wndClass;
	wndClass.style = 0;
	wndClass.lpfnWndProc = &Wndproc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = NULL;
	wndClass.hIcon = NULL;
	wndClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = L"WINDOW";
	

	this->wndclass = (ATOM)RegisterClass(&wndClass);

}

void window::createWindow()
{
	HWND hwnd = CreateWindowEx(
		0,
		(LPCWSTR)this->wndclass,
		(LPWSTR)this->title,
		WS_TILEDWINDOW,
		100, 100,
		this->width, this->height,
		NULL, NULL, NULL, NULL
	);

	 

	if (!hwnd)return;
	this->ptr = hwnd;
	SetWindowLongPtrW(this->ptr, GWLP_USERDATA, (LONG_PTR)this);
	ShowWindow(this->ptr,SW_NORMAL);
	UpdateWindow(this->ptr);
}

void window::HandleEvents()
{
	MSG msg;
	if (PeekMessageA(&msg, 0, 0, 0, 1)) {
		TranslateMessage(&msg);
		DispatchMessageA(&msg);

	}
	else {
		
	}
	
}

window::window(int width, int height, const char* title):width(width),height(height),title((char*) title)
{
	if (this->wndclass == NULL) {
		createWindowclass();
	}
	this->createWindow();
	this->InitGL();
}

void window::Update()
{
	this->HandleEvents();
}
void window::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	SwapBuffers(this->hdc);
	glFlush();

}
void window::AddTextToDraw(text txt)
{
	this->texttoDraw.push_back(txt);
	redraw = true;
}
void window::InitGL()
{
	if (this->ptr == NULL)return;

	PIXELFORMATDESCRIPTOR pfd = {};
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.iLayerType = PFD_MAIN_PLANE;

	HDC hdc = GetDC(this->ptr);
	this->hdc = hdc;
	int pixelFormat = ChoosePixelFormat(hdc, &pfd);
	if (!SetPixelFormat(hdc, pixelFormat, &pfd)) {
		MessageBox(NULL, L"Failed to set pixel format", L"Error", MB_OK);
		return;
	}

	HGLRC hglrc = wglCreateContext(hdc);


	if (!hglrc || !wglMakeCurrent(hdc, hglrc))
	{
		int x = 2137;
		MessageBox(NULL, L"Failed to initialize OpenGL context", L"Error", MB_OK);
	}

	RECT rcCli;
	GetClientRect(WindowFromDC(hdc), &rcCli);
	this->width = rcCli.right;
	this->height = rcCli.bottom;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	gluOrtho2D(0, this->width, this->height, 0);
	

}