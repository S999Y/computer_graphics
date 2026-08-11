#include <iostream>
#include <graphics.h>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

void renderLine(vector<pair<int, int>> &pixelList);

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector<pair<int, int>> points;

    int dx = x2 - x1;
    int dy = y2 - y1;
    int decision_p = 2 * dy - dx;

    // insert first point
    points.push_back({x1, y1});

    while (x1 < x2 || y1 < y2)
    {
        if (decision_p < 0)
        {
            x1 = x1 + 1;
            y1 = y1;
            decision_p = decision_p + 2 * dy;
            points.push_back({x1, y1});
        }
        else
        {
            x1 = x1 + 1;
            y1 = y1 + 1;
            decision_p = decision_p + 2 * dy - 2 * dx;
            points.push_back({x1, y1});
        }
    }

    renderLine(points);

    return 0;
}

void renderLine(vector<pair<int, int>> &pixelList)
{
    initwindow(800, 500, "DDA Line Drawing");

    if (pixelList.size() < 2)
        return;

    for (size_t i = 1; i < pixelList.size(); i++)
    {
        line(pixelList[i - 1].first,
             pixelList[i - 1].second,
             pixelList[i].first,
             pixelList[i].second);
    }

    getch();
    closegraph();
}