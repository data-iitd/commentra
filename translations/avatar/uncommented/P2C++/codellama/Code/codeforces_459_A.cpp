#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    string given;
    cin >> given;
    string l1[4];
    for (int i = 0; i < 4; i++)
    {
        l1[i] = given.substr(i, 1);
    }
    int x1 = stoi(l1[0]);
    int y1 = stoi(l1[1]);
    int x2 = stoi(l1[2]);
    int y2 = stoi(l1[3]);
    int denominator = x2 - x1;
    int numerator = y2 - y1;
    if (denominator != 0)
    {
        int quotient = numerator / denominator;
        if (numerator == 0)
        {
            int d = int(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
            int x4 = x1;
            int x3 = x2;
            int y3 = y2 + d;
            int y4 = y1 + d;
            cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
        }
        else if (denominator == 0)
        {
            int y4 = y2;
            int y3 = y1;
            int d = int(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
            int x4 = x1 + d;
            int x3 = x2 + d;
            cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
        }
        else if (quotient == 1)
        {
            int x4 = x2;
            int x3 = x1;
            int y4 = y1;
            int y3 = y2;
            cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
        }
        else if (quotient == -1)
        {
            int x4 = x1;
            int x3 = x2;
            int y4 = y2;
            int y3 = y1;
            cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}



