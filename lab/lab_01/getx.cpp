#include <graphics.h>
#include <cstdio>

using namespace std;

int main()
{
    initwindow(800, 500, "Graphics Window", 100, 200);

    moveto(100, 150);
    int x = getx();

    char str[20];
    sprintf(str, "%d", x);

    outtextxy(100, 100, str);

    getchar();
    closegraph();

    return 0;
}