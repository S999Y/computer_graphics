#include <graphics.h>
#include <iostream>

using namespace std;

int main()
{
    initwindow(800, 500, "Graphics Window", 100, 200);

    setcolor(RED);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(100, 100, 300, 100);

    getchar();
    closegraph();

    return 0;
}