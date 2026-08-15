#include <iostream>
#include <graphics.h>
#include <vector>
#include <utility>
#include <cmath>
#include <conio.h>

#define print(x) cout << x << endl;

using namespace std;

const int WIDTH = 640;
const int HEIGHT = 480;
const int cx = WIDTH / 2;
const int cy = HEIGHT / 2;

void translate(vector<pair<int, int>> &points);
void scaling(vector<pair<int, int>> &points);
void rotation(vector<pair<int, int>> &points);
void reflection(vector<pair<int, int>> &points);
void shearing(vector<pair<int, int>> &points);
void print_points(vector<pair<int, int>> &points);

int mapX(int x)
{
    return cx + x;
}

int mapY(int y)
{
    return cy - y;
}

void draw_axes()
{
    setcolor(LIGHTGRAY);
    line(0, cy, WIDTH, cy);
    line(cx, 0, cx, HEIGHT);
}

void draw_shape(vector<pair<int, int>> &points, int color)
{
    if (points.size() < 2)
        return;

    setcolor(color);

    for (size_t i = 1; i < points.size(); i++)
    {
        line(mapX(points[i - 1].first), mapY(points[i - 1].second),
             mapX(points[i].first), mapY(points[i].second));
    }

    line(mapX(points.back().first), mapY(points.back().second),
         mapX(points.front().first), mapY(points.front().second));

    setfillstyle(SOLID_FILL, color);
    for (auto &p : points)
    {
        circle(mapX(p.first), mapY(p.second), 3);
        floodfill(mapX(p.first), mapY(p.second), color);
    }
}

int main()
{
    vector<pair<int, int>> points;

    int total_point;
    cout << "How many points? ";
    cin >> total_point;

    int x;
    int y;
    cout << "Enter x y: " << endl;
    while (total_point--)
    {
        cin >> x >> y;
        points.push_back({x, y});
    }

    initwindow(WIDTH, HEIGHT, "2D Transformation - Original");
    draw_axes();
    draw_shape(points, WHITE);
    getch();
    closegraph();

    translate(points);

    scaling(points);

    rotation(points);

    reflection(points);

    shearing(points);

    return 0;
}

void translate(vector<pair<int, int>> &points)
{
    int tx;
    int ty;
    cout << "Enter Tx: ";
    cin >> tx;
    cout << "Enter Ty: ";
    cin >> ty;
    cout << endl;

    print("Translation: ");
    vector<pair<int, int>> result;
    for (auto &p : points)
    {
        result.push_back({p.first + tx, p.second + ty});
        cout << result.back().first << " " << result.back().second << endl;
    }
    print("");
    print("");

    initwindow(WIDTH, HEIGHT, "2D Transformation - Translation");
    draw_axes();
    draw_shape(points, WHITE);
    draw_shape(result, GREEN);
    getch();
    closegraph();
}

void scaling(vector<pair<int, int>> &points)
{
    int sx;
    int sy;
    cout << "Enter Sx: ";
    cin >> sx;
    cout << "Enter Sy: ";
    cin >> sy;
    cout << endl;

    print("Scaling: ");
    vector<pair<int, int>> result;
    for (auto &p : points)
    {
        result.push_back({p.first * sx, p.second * sy});
        cout << result.back().first << " " << result.back().second << endl;
    }
    print("");
    print("");

    initwindow(WIDTH, HEIGHT, "2D Transformation - Scaling");
    draw_axes();
    draw_shape(points, WHITE);
    draw_shape(result, RED);
    getch();
    closegraph();
}

void rotation(vector<pair<int, int>> &points)
{
    int angle;
    cout << "Enter angle: ";
    cin >> angle;

    float rad = (float)angle * 3.1416 / 180;

    print("Rotation: ");
    vector<pair<int, int>> result;
    for (auto &p : points)
    {
        result.push_back({round(p.first * cos(rad) - p.second * sin(rad)),
                          round(p.first * sin(rad) + p.second * cos(rad))});
        cout << result.back().first << " " << result.back().second << endl;
    }
    print("");
    print("");

    initwindow(WIDTH, HEIGHT, "2D Transformation - Rotation");
    draw_axes();
    draw_shape(points, WHITE);
    draw_shape(result, BLUE);
    getch();
    closegraph();
}

void reflection(vector<pair<int, int>> &points)
{
    print("Reflection on X axis:");
    vector<pair<int, int>> resultX;
    for (auto &p : points)
    {
        resultX.push_back({p.first, -p.second});
        cout << resultX.back().first << " " << resultX.back().second << endl;
    }

    print("Reflection on Y axis:");
    vector<pair<int, int>> resultY;
    for (auto &p : points)
    {
        resultY.push_back({-p.first, p.second});
        cout << resultY.back().first << " " << resultY.back().second << endl;
    }
    print("");
    print("");

    initwindow(WIDTH, HEIGHT, "2D Transformation - Reflection");
    draw_axes();
    draw_shape(points, WHITE);
    draw_shape(resultX, YELLOW);
    draw_shape(resultY, CYAN);
    getch();
    closegraph();
}

void shearing(vector<pair<int, int>> &points)
{
    print("Shearng in X axis:");
    int SHx;
    cout << "Enter Shearing in x [Shx]: ";
    cin >> SHx;
    print("");

    vector<pair<int, int>> resultX;
    for (auto &p : points)
    {
        resultX.push_back({p.first + p.second * SHx, p.second});
        cout << resultX.back().first << " " << resultX.back().second << endl;
    }

    print("Shearng in y axis:");
    int SHy;
    cout << "Enter Shearing in y [Shy]: ";
    cin >> SHy;
    print("");

    vector<pair<int, int>> resultY;
    for (auto &p : points)
    {
        resultY.push_back({p.first, p.first * SHy + p.second});
        cout << resultY.back().first << " " << resultY.back().second << endl;
    }
    print("");

    initwindow(WIDTH, HEIGHT, "2D Transformation - Shearing");
    draw_axes();
    draw_shape(points, WHITE);
    draw_shape(resultX, MAGENTA);
    draw_shape(resultY, BROWN);
    getch();
    closegraph();
}

void print_points(vector<pair<int, int>> &points)
{
    // cout << "x y" << endl;
    for (auto &p : points)
    {
        cout << p.first << " " << p.second << endl;
    }
}
