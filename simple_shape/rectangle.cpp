#include <graphics.h>

using namespace std;

int main()
{
    initwindow(900, 600);

    // arc(300, 300, 0, 90, 150);
    setcolor(GREEN);
    rectangle(40, 100, 440, 300);

    setfillstyle(SOLID_FILL, RED);
    floodfill(50, 100, GREEN);

    getch();
}