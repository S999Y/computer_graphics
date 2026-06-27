#include <graphics.h>

using namespace std;

int main()
{
    initwindow(800, 500, "Graphics Window", 100, 200);

    moveto(100, 150);
    lineto(300, 150);

    getchar();
    closegraph();

    return 0;
}