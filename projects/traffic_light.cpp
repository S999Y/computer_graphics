#include <graphics.h>
#include <conio.h>

using namespace std;

void light_post(int x_pos, int y_pos);
void fill_color(int x_pos, int y_pos, int fill_color, int border_color);
void road(int x_pos, int y_pos, int len);

int main()
{
    initwindow(1200, 800, "Traffic Light");

    // light
    light_post(900, 50);

    // road
    road(10, 500, 1000);

    getchar();
    closegraph();

    return 0;
}

void light_post(int x_pos, int y_pos)
{
    int ratio = 1;
    int height = 200;
    int width = 100;
    int gap = 10;
    int lamp_height = 120;

    // main light box
    rectangle(x_pos, y_pos, x_pos + width, y_pos + height);

    // red light circle
    circle(x_pos + width / 2, (y_pos + height / 4) - gap, 25);
    fill_color(x_pos + width / 2, (y_pos + height / 4) - gap, RED, WHITE);

    // yellow light circle
    circle(x_pos + width / 2, y_pos + 2 * height / 4, 25);
    fill_color(x_pos + width / 2, y_pos + 2 * height / 4, YELLOW, WHITE);

    // green light circle
    circle(x_pos + width / 2, (y_pos + 3 * height / 4) + gap, 25);
    fill_color(x_pos + width / 2, (y_pos + 3 * height / 4) + gap, GREEN, WHITE);

    // beam
    rectangle(x_pos + (width / 2) - (gap / 2), y_pos + height, x_pos + (width / 2) + 10, y_pos + height + lamp_height);
    rectangle(x_pos + (width / 2) - 3 * gap, y_pos + height + lamp_height, x_pos + (width / 2) + 3 * gap, y_pos + height + lamp_height + gap);
    rectangle(x_pos + (width / 2) - 5 * gap, y_pos + height + lamp_height + gap, x_pos + (width / 2) + 5 * gap, y_pos + height + lamp_height + 2 * gap);
}

void fill_color(int x_pos, int y_pos, int fill_color, int border_color)
{
    setfillstyle(SOLID_FILL, fill_color);
    floodfill(x_pos, y_pos, border_color);
}

void road(int x_pos, int y_pos, int len)
{
    int gap = 100;

    // line
    line(x_pos, y_pos, x_pos + len, y_pos);
    line(x_pos, y_pos + gap, x_pos + len, y_pos + gap);
    line(x_pos, y_pos + 2 * gap, x_pos + len, y_pos + 2 * gap);
}