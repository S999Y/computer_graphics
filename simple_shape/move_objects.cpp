#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

bool collision(int px1, int py1, int px2, int py2,
               int ox1, int oy1, int ox2, int oy2)
{
    return !(px2 < ox1 || // player left of obstacle
             px1 > ox2 || // player right of obstacle
             py2 < oy1 || // player above obstacle
             py1 > oy2);  // player below obstacle
}

int main()
{
    initwindow(900, 600);

    // Player rectangle
    int px1 = 100, py1 = 100;
    int px2 = 150, py2 = 150;

    // Obstacle rectangle
    int ox1 = 300, oy1 = 200;
    int ox2 = 450, oy2 = 350;

    while (true)
    {
        cleardevice();

        // Draw obstacle
        setcolor(RED);
        rectangle(ox1, oy1, ox2, oy2);

        // Draw player
        setcolor(GREEN);
        rectangle(px1, py1, px2, py2);

        if (kbhit())
        {
            int key = getch();

            if (key == 27) // ESC
                break;

            int oldx1 = px1, oldy1 = py1;
            int oldx2 = px2, oldy2 = py2;

            if (key == 0 || key == 224)
            {
                key = getch();

                switch (key)
                {
                case 72: // Up
                    py1 -= 10;
                    py2 -= 10;
                    break;

                case 80: // Down
                    py1 += 10;
                    py2 += 10;
                    break;

                case 75: // Left
                    px1 -= 10;
                    px2 -= 10;
                    break;

                case 77: // Right
                    px1 += 10;
                    px2 += 10;
                    break;
                }

                // Check collision
                if (collision(px1, py1, px2, py2,
                              ox1, oy1, ox2, oy2))
                {
                    // Undo movement
                    // px1 = oldx1;
                    // py1 = oldy1;
                    // px2 = oldx2;
                    // py2 = oldy2;

                    cout << "Game over!" << endl;
                    break;
                }
            }
        }

        delay(20);
    }

    closegraph();
    return 0;
}