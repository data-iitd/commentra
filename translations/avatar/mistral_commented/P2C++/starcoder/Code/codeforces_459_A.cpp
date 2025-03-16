#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;

    int denominator = x2 - x1;
    int numerator = y2 - y1;

    if (denominator == 0)
    {
        int d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        x4 = x1;
        x3 = x2;
        y3 = y2 + d;
        y4 = y1 + d;
        cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    }
    else if (denominator!= 0)
    {
        double quotient = (double)numerator / denominator;
        if (quotient == 1 || quotient == -1)
        {
            if (quotient == 1)
            {
                x4 = x2;
                x3 = x1;
                y3 = y1;
                y4 = y2;
            }
            else
            {
                x4 = x1;
                x3 = x2;
                y3 = y2;
                y4 = y1;
            }
            cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
}

