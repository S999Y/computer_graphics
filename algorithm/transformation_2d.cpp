#include <iostream>
#include <graphics.h>
#include <vector>
#include <utility>
#include <cmath>

#define print(x) cout << x << endl;

using namespace std;

void translate(vector<pair<int, int>> &points);
void scaling(vector<pair<int, int>> &points);
void rotation(vector<pair<int, int>> &points);
void reflection(vector<pair<int, int>> &points);
void shearing(vector<pair<int, int>> &points);
void print_points(vector<pair<int, int>> &points);

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

    translate(points);
    // print("Translation: ");
    // print_points(points);

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

    pair<int, int> temp;
    print("Translation: ");
    for (auto &p : points)
    {
        temp.first = p.first + tx;
        temp.second = p.second + ty;
        // p = temp;
        cout << temp.first << " " << temp.second << endl;
    }
    print("");
    print("");
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

    pair<int, int> temp;
    for (auto &p : points)
    {
        temp.first = p.first * sx;
        temp.second = p.second * sy;
        cout << temp.first << " " << temp.second << endl;
    }
    print("");
    print("");
}

void rotation(vector<pair<int, int>> &points)
{
    int angle;
    cout << "Enter angle: ";
    cin >> angle;

    float rad = (float)angle * 3.1416 / 180;

    pair<int, int> temp;

    print("Rotation: ");
    for (auto &p : points)
    {
        temp.first = round(p.first * cos(rad) - p.second * sin(rad));
        temp.second = round(p.first * sin(rad) + p.second * cos(rad));
        cout << temp.first << " " << temp.second << endl;
    }
    print("");
    print("");
}

void reflection(vector<pair<int, int>> &points)
{
    print("Reflection on X axis:");
    pair<int, int> temp;

    for (auto &p : points)
    {
        temp.first = p.first;
        temp.second = -p.second;
        cout << temp.first << " " << temp.second << endl;
    }

    print("Reflection on Y axis:");

    for (auto &p : points)
    {
        temp.first = -p.first;
        temp.second = p.second;
        cout << temp.first << " " << temp.second << endl;
    }
    print("");
    print("");
}

void shearing(vector<pair<int, int>> &points)
{
    print("Shearng in X axis:");
    pair<int, int> temp;
    int SHx;
    cout << "Enter Shearing in x [Shx]: ";
    cin >> SHx;
    print("");

    for (auto &p : points)
    {
        temp.first = p.first + p.second * SHx;
        temp.second = p.second;
        cout << temp.first << " " << temp.second << endl;
    }

    print("Shearng in y axis:");
    int SHy;
    cout << "Enter Shearing in y [Shy]: ";
    cin >> SHy;
    print("");

    for (auto &p : points)
    {
        temp.first = p.first;
        temp.second = p.first * SHy + p.second;
        cout << temp.first << " " << temp.second << endl;
    }
    print("");
}

void print_points(vector<pair<int, int>> &points)
{
    // cout << "x y" << endl;
    for (auto &p : points)
    {
        cout << p.first << " " << p.second << endl;
    }
}