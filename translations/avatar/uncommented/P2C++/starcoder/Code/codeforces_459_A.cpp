#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int x1, y1, x2, y2, d, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    d = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    if (x2-x1 == 0)
    {
        x3 = x1;
        x4 = x2;
        y3 = y2 + d;
        y4 = y1 + d;
    }
    else if (y2-y1 == 0)
    {
        x3 = x1 + d;
        x4 = x2 + d;
        y3 = y1;
        y4 = y2;
    }
    else if (x2-x1 == y2-y1)
    {
        x3 = x1;
        x4 = x2;
        y3 = y1;
        y4 = y2;
    }
    else if (x2-x1 == -y2+y1)
    {
        x3 = x1;
        x4 = x2;
        y3 = y2;
        y4 = y1;
    }
    else if (x2-x1 == y2+y1)
    {
        x3 = x1;
        x4 = x2;
        y3 = y1;
        y4 = y2;
    }
    else if (x2-x1 == -y2-y1)
    {
        x3 = x1;
        x4 = x2;
        y3 = y2;
        y4 = y1;
    }
    else
    {
        x3 = x1;
        x4 = x2;
        y3 = y1;
        y4 = y2;
    }
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    return 0;
}
