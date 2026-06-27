#include <graphics.h>
#include <iostream>

using namespace std;

int main()
{
    initwindow(800, 500, "Graphics Window", 100, 200);

    moveto(100, 150);
    int y = gety();
    cout << y << endl;

    getchar();
    closegraph();

    return 0;
}