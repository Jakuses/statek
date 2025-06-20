#include <iostream>
#include "window.h"
#include "drawing.h"
#include "board.h"
#include <Windows.h>
using namespace std;
int main() {
	cout << "test";
	window wnd(800, 600, "Nigabols");
	board b(10.f,10.f,wnd.width - 20.f,wnd.height - 20.f, &wnd);
	while (b.playing)
	{
		float time_start = timeGetTime();
		b.update();
		wnd.Update();
		drawing::Begin();
		b.Draw();
		drawing::End(&wnd);
		float time_end = timeGetTime();
		b.deltaTime = (time_end - time_start)/1000; 
		
	}

}
