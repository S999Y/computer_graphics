#include <iostream>
#include <graphics.h>
#include <iomanip>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

void dda_line(float x1, float y1, float x2, float y2, vector<pair<float, float>> &points);
float absolute(float a);
void print_pointf(vector<pair<float, float>> &points);
void round_points(vector<pair<float, float>> &points, vector<pair<int, int>> &round_points);
void points_int(vector<pair<int, int>> &points);
void draw_dda_line(vector<pair<int, int>> &points);

int main()
{
    vector<pair<float, float>> points;
    vector<pair<int, int>> rounded_points;

    float x1, y1, x2, y2;

    cout << "===== DDA Line Drawing Algorithm =====\n";
    cout << "Enter the starting point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter the ending point (x2 y2): ";
    cin >> x2 >> y2;

    cout << setprecision(3);
    dda_line(x1, y1, x2, y2, points);
    // print_pointf(points);
    round_points(points, rounded_points);
    // points_int(rounded_points);
    cout << "Total points: " << rounded_points.size() << endl;

    draw_dda_line(rounded_points);

    return 0;
}

void dda_line(float x1, float y1, float x2, float y2, vector<pair<float, float>> &points)
{
    // cout << '\n'
    //      << x1 << " " << y1 << endl;

    points.push_back({x1, y1});

    float m = (y2 - y1) / (x2 - x1);

    float dx = x2 - x1;
    float dy = y2 - y1;

    if (absolute(dx) >= absolute(dy))
    {

        while (x1 < x2)
        {
            dx = 1;
            x1 = x1 + dx;
            y1 = y1 + m;
            // cout << x1 << " " << y1 << endl;
            points.push_back({x1, y1});
        }
    }
    else
    {
        while (y1 < y2)
        {
            dy = 1;
            x1 = x1 + 1 / m;
            y1 = y1 + dy;
            // cout << x1 << " " << y1 << endl;
            points.push_back({x1, y1});
        }
    }
}

float absolute(float a)
{
    if (a >= 0)
    {
        return a;
    }
    else
    {
        return -a;
    }
}

void print_pointf(vector<pair<float, float>> &points)
{
    cout << "\n float points: \n";
    for (auto &a : points)
    {
        cout << a.first << " " << a.second << endl;
    }
}

void points_int(vector<pair<int, int>> &points)
{
    cout << "\n rounded int points: \n";

    for (auto &a : points)
    {
        cout << a.first << " " << a.second << endl;
    }
}

void round_points(vector<pair<float, float>> &points, vector<pair<int, int>> &round_points)
{
    for (auto &a : points)
    {
        round_points.push_back({round(a.first), round(a.second)});
    }
}

void draw_dda_line(vector<pair<int, int>> &points)
{
    initwindow(800, 500, "DDA Line Drawing Algorithm");

    int len = points.size();

    int index = 2;
    line(points[0].first, points[0].second, points[1].first, points[1].second);
    while (index < len)
    {
        line(points[index - 1].first, points[index - 1].second, points[index].first, points[index].second);
        index++;
    }

    getch();
    closegraph();
}