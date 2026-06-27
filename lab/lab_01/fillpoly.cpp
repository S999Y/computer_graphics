#include <graphics.h>
#include <iostream>

using namespace std;

int main()
{
    initwindow(800, 500, "Graphics Window", 100, 200);

    int poly[] = {100, 100, 200, 100, 150, 200};
    fillpoly(3, poly);

    getchar();
    closegraph();

    return 0;
}