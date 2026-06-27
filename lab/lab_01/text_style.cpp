#include <graphics.h>

using namespace std;

int main()
{
    initwindow(800, 500, "Graphics Window", 100, 200);

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 18);
    outtextxy(150, 100, "Hello, John...");

    getchar();
    closegraph();

    return 0;
}