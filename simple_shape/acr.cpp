#include <graphics.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    char path[] = "";
    initgraph(&gd, &gm, path);
    // initwindow(300,200);

    // acr(x,y,StartingAngle,EndingAngle,Radius);
    //  arc(100,140,20,30,100);
    // for (int i = 0; i <= 360; i++)
    // {
    //     arc(100, 140, 0, 0 + i, 100);
    //     delay(10);
    //     if (i != 360)
    //     {
    //         cleardevice();
    //     }
    // }

    getch();
    closegraph();

    return 0;
}