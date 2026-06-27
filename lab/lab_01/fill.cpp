#include <graphics.h>

using namespace std;

int main()
{
    initwindow(800, 500, "Graphics Window", 100, 200);

    rectangle(100, 100, 200, 200);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(150, 150, WHITE);

    getchar();
    closegraph();

    return 0;
}