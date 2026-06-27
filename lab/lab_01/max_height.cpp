#include <graphics.h>
#include <iostream>

using namespace std;

int main()
{
    initwindow(800, 500, "Graphics Window", 100, 200);

    int maxX = getmaxy();
    cout << maxX << endl;

    getchar();
    closegraph();

    return 0;
}