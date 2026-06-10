#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    char path[] = "";

    initgraph(&gd, &gm, path);

    // // Draw a circle
    // circle(200, 200, 100);

    // // Draw a triangle
    // line(400, 100, 300, 300);
    // line(300, 300, 500, 300);
    // line(500, 300, 400, 100);

    for (int i = 0; i < 600; i += 10)
    {
        circle(0 + i, 200, 100);
        delay(100);
        cleardevice();
    }

    getch();
    closegraph();

    return 0;
}