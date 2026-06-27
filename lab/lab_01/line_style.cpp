#include <graphics.h>

using namespace std;

int main()
{
    initwindow(800, 500, "Graphics Window", 100, 200);

    setlinestyle(DASHED_LINE, 0, THICK_WIDTH);
    line(100, 100, 300, 100);

    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(100, 110, 300, 110);

    getchar();
    closegraph();

    return 0;
}