#include <graphics.h>
#include <iostream>

using namespace std;

int main()
{
    initwindow(800, 500, "Graphics Window", 100, 200);

    int mxc = getmaxcolor();
    cout << mxc << endl;

    getchar();
    closegraph();

    return 0;
}