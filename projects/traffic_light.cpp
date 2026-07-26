#include <graphics.h>

#include <conio.h>

using namespace std;

void visual();
void pages();
void light_post(int x_pos, int y_pos);
void fill_color(int x_pos, int y_pos, int fill_color, int border_color);
void road(int x_pos, int y_pos, int len);
void car(int x, int y);
void human(int x, int y);

int main()
{
    initwindow(1200, 700, "Traffic Light");

    // visual();
    pages();

    getchar();
    closegraph();

    return 0;
}

void visual()
{
    for (int i = 0; i < 1000; i++)
    {
        cleardevice();

        // light
        light_post(900, 50);

        // road
        road(10, 400, 1200);

        // car
        car(20 + i, 550);

        // human
        human(600, 550);

        // delay
        delay(10);
    }
}

void pages()
{
    int page = 0;

    for (int i = 0; i < 1000; i++)
    {
        setactivepage(page);
        cleardevice();

        // light signal
        light_post(900, 50);

        // road
        road(10, 400, 1200);

        // car
        car(20 + i, 550);

        // human
        int y;
        if (i <= 500)
        {
            y = 340 + i / 2;
        }
        human(600, y);

        setvisualpage(page);
        page = 1 - page; // Switch between page 0 and 1

        delay(10);
    }
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

    // Top line
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(x_pos, y_pos, x_pos + len, y_pos);

    // Middle dashed line
    int dash = 30;
    int space = 20;

    for (int i = x_pos; i < x_pos + len; i += dash + space)
    {
        line(i, y_pos + gap,
             min(i + dash, x_pos + len),
             y_pos + gap);
    }

    // Bottom line
    line(x_pos, y_pos + 2 * gap, x_pos + len, y_pos + 2 * gap);
}

void car(int x, int y)
{
    // Body
    rectangle(x, y, x + 80, y + 20);

    // Roof
    line(x + 15, y, x + 30, y - 15);
    line(x + 30, y - 15, x + 50, y - 15);
    line(x + 50, y - 15, x + 65, y);

    // Wheels
    circle(x + 20, y + 20, 8);
    circle(x + 60, y + 20, 8);
}

void human(int x, int y)
{
    // Head
    circle(x, y, 10);

    // Body
    line(x, y + 10, x, y + 40);

    // Arms
    line(x - 15, y + 25, x + 15, y + 25);

    // Legs
    line(x, y + 40, x - 10, y + 60);
    line(x, y + 40, x + 10, y + 60);
}

void movement()
{
}