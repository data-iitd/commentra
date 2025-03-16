
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4, d;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x2 - x1 == 0)
    {
        d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        x4 = x1;
        x3 = x2;
        y3 = y2 + d;
        y4 = y1 + d;
    }
    else if (y2 - y1 == 0)
    {
        d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        y4 = y2;
        y3 = y1;
        x4 = x1 + d;
        x3 = x2 + d;
    }
    else
    {
        double quotient = (y2 - y1) / (x2 - x1);
        if (quotient == 1)
        {
            x4 = x2;
            x3 = x1;
            y4 = y1;
            y3 = y2;
        }
        else if (quotient == -1)
        {
            x4 = x1;
            x3 = x2;
            y4 = y2;
            y3 = y1;
        }
        else
        {
            d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            x4 = x1 + d;
            x3 = x2 + d;
            y4 = y2 + d;
            y3 = y1 + d;
        }
    }
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    return 0;
}

