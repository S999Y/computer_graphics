#include <graphics.h>

#include <conio.h>

using namespace std;

void pages();
void traffic_light(int x_pos, int y_pos, int state);
void fill_color(int x_pos, int y_pos, int fill_color, int border_color);
void road(int x_pos, int y_pos, int len);
void zebra_crossing(int x_pos);
void car(int x, int y, int dir);
void bicycle(int x, int y, int dir);
void human(int x, int y);

struct Vehicle
{
    float x;
    float speed;
    int dir;
    int span;
    int y;
    bool isBike;
};

int main()
{
    initwindow(1200, 700, "Traffic Simulation");

    pages();

    getchar();
    closegraph();

    return 0;
}

void pages()
{
    const int GREEN_DUR = 350;
    const int YELLOW_DUR = 150;
    const int RED_DUR = 320;
    const int CYCLE = GREEN_DUR + YELLOW_DUR + RED_DUR;
    const int NUM_CYCLES = 3;

    // stop lines just before/after the crossing (crossing spans x 720-860)
    const int STOP_R = 700; // right-moving traffic halts here
    const int STOP_L = 880; // left-moving traffic halts here

    // vehicles (x, speed, dir, span, y, isBike)
    Vehicle vehicles[] = {
        {80, 5.0f, 1, 80, 550, false},
        {420, 4.3f, 1, 80, 550, false},
        {760, 4.8f, 1, 80, 550, false},
        {500, 4.5f, -1, 80, 430, false},
        {280, 2.5f, 1, 20, 562, true},
        {700, 2.2f, -1, 20, 430, true},
    };

    // pedestrian positions (persistent, so they shuttle across each red)
    float pBottomY = 620;
    float pTopY = 340;
    int tgtB = 620; // destination side for each red light
    int tgtT = 340;
    const int CROSS_X = 740;

    int page = 0;

    for (int i = 0; i < CYCLE * NUM_CYCLES; i++)
    {
        setactivepage(page);
        cleardevice();

        int t = i % CYCLE;
        int state;
        if (t < GREEN_DUR)
            state = GREEN;
        else if (t < GREEN_DUR + YELLOW_DUR)
            state = YELLOW;
        else
            state = RED;

        // speed factor: green = fast, yellow = gradually slow, red = stop
        float factor;
        if (state == GREEN)
            factor = 1.0f;
        else if (state == YELLOW)
            factor = 1.0f - (float)(t - GREEN_DUR) / YELLOW_DUR;
        else
            factor = 0.0f;

        // scene
        road(10, 400, 1200);
        zebra_crossing(720);
        traffic_light(880, 40, state);

        // vehicles
        for (int v = 0; v < 6; v++)
        {
            if (vehicles[v].isBike)
                bicycle((int)vehicles[v].x, vehicles[v].y, vehicles[v].dir);
            else
                car((int)vehicles[v].x, vehicles[v].y, vehicles[v].dir);
        }

        // pedestrians: cross the zebra crossing every time the light is red.
        // one uses the left side of the crossing, the other the right side,
        // so they never walk over each other. each red light sends them to
        // the opposite side of the road.
        if (state == RED)
        {
            int rt = t - (GREEN_DUR + YELLOW_DUR);
            if (rt == 16)
            {
                // destination is the far side of the road
                tgtB = (pBottomY > 480) ? 340 : 620;
                tgtT = (pTopY < 480) ? 620 : 340;
            }
            if (rt > 15)
            {
                float step = 280.0f / (RED_DUR - 16);
                if (tgtB < pBottomY)
                    pBottomY = max(pBottomY - step, (float)tgtB);
                else
                    pBottomY = min(pBottomY + step, (float)tgtB);

                if (tgtT > pTopY)
                    pTopY = min(pTopY + step, (float)tgtT);
                else
                    pTopY = max(pTopY - step, (float)tgtT);
            }
        }
        human(CROSS_X - 10, (int)pBottomY);
        human(CROSS_X + 60, (int)pTopY);

        setvisualpage(page);
        page = 1 - page; // Switch between page 0 and 1

        // update vehicle positions (halt at the stop line when light is not green)
        for (int v = 0; v < 6; v++)
        {
            float front = vehicles[v].x + vehicles[v].dir * vehicles[v].span;
            float move = vehicles[v].speed * factor * vehicles[v].dir;
            float newFront = front + move;

            if (state != GREEN)
            {
                if (vehicles[v].dir == 1 && front <= STOP_R && newFront > STOP_R)
                    newFront = STOP_R;
                else if (vehicles[v].dir == -1 && front >= STOP_L && newFront < STOP_L)
                    newFront = STOP_L;
            }

            vehicles[v].x = newFront - vehicles[v].dir * vehicles[v].span;

            if (vehicles[v].x > 1250)
                vehicles[v].x -= 1300;
            if (vehicles[v].x < -100)
                vehicles[v].x += 1300;
        }

        delay(10);
    }
}

void traffic_light(int x_pos, int y_pos, int state)
{
    int width = 100;
    int height = 200;
    int gap = 10;
    int lamp_height = 140;

    // main light box
    rectangle(x_pos, y_pos, x_pos + width, y_pos + height);

    // red light circle
    circle(x_pos + width / 2, (y_pos + height / 4) - gap, 25);
    fill_color(x_pos + width / 2, (y_pos + height / 4) - gap,
               (state == RED) ? RED : DARKGRAY, WHITE);

    // yellow light circle
    circle(x_pos + width / 2, y_pos + 2 * height / 4, 25);
    fill_color(x_pos + width / 2, y_pos + 2 * height / 4,
               (state == YELLOW) ? YELLOW : DARKGRAY, WHITE);

    // green light circle
    circle(x_pos + width / 2, (y_pos + 3 * height / 4) + gap, 25);
    fill_color(x_pos + width / 2, (y_pos + 3 * height / 4) + gap,
               (state == GREEN) ? GREEN : DARKGRAY, WHITE);

    // beam
    rectangle(x_pos + (width / 2) - (gap / 2), y_pos + height,
              x_pos + (width / 2) + 10, y_pos + height + lamp_height);
    rectangle(x_pos + (width / 2) - 3 * gap, y_pos + height + lamp_height,
              x_pos + (width / 2) + 3 * gap, y_pos + height + lamp_height + gap);
    rectangle(x_pos + (width / 2) - 5 * gap, y_pos + height + lamp_height + gap,
              x_pos + (width / 2) + 5 * gap, y_pos + height + lamp_height + 2 * gap);
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

void zebra_crossing(int x_pos)
{
    int stripe_len = 140;
    int stripe_thick = 14;
    int stripe_gap = 44;

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    for (int i = 0; i < 5; i++)
    {
        bar(x_pos,
            404 + i * stripe_gap,
            x_pos + stripe_len,
            404 + i * stripe_gap + stripe_thick);
    }
}

void car(int x, int y, int dir)
{
    int body[8] = {x, y, x + 80 * dir, y, x + 80 * dir, y + 20, x, y + 20};
    int roof[8] = {x + 15 * dir, y, x + 30 * dir, y - 15,
                   x + 50 * dir, y - 15, x + 65 * dir, y};

    // Filled body so the zebra stripes don't show through
    setfillstyle(SOLID_FILL, RED);
    fillpoly(4, body);
    fillpoly(4, roof);

    // Outline
    setcolor(RED);
    rectangle(x, y, x + 80 * dir, y + 20);
    line(x + 15 * dir, y, x + 30 * dir, y - 15);
    line(x + 30 * dir, y - 15, x + 50 * dir, y - 15);
    line(x + 50 * dir, y - 15, x + 65 * dir, y);

    // Wheels (filled so road markings don't show through)
    setfillstyle(SOLID_FILL, DARKGRAY);
    setcolor(DARKGRAY);
    fillellipse(x + 20 * dir, y + 20, 8, 8);
    fillellipse(x + 60 * dir, y + 20, 8, 8);
}

void bicycle(int x, int y, int dir)
{
    // Wheels
    circle(x, y, 6);
    circle(x + 20 * dir, y, 6);

    // Frame
    line(x, y - 6, x + 20 * dir, y - 18);

    // Seat
    line(x + 4 * dir, y - 18, x + 20 * dir, y - 18);
    line(x + 4 * dir, y - 18, x + 4 * dir, y - 26);

    // Handlebar
    line(x + 20 * dir, y - 18, x + 20 * dir, y - 12);
    line(x + 16 * dir, y - 12, x + 24 * dir, y - 12);
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
