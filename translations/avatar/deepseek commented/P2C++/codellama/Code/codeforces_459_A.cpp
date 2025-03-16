
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Step 1: Take input from the user and split it into a list of integers
    string given;
    cin >> given;
    string l1[4];
    int x1, y1, x2, y2;
    for (int i = 0; i < 4; i++)
    {
        l1[i] = given.substr(i * 2, 2);
    }
    x1 = stoi(l1[0]);
    y1 = stoi(l1[1]);
    x2 = stoi(l1[2]);
    y2 = stoi(l1[3]);

    // Step 2: Assign the values to variables x1, y1, x2, and y2
    int x1 = stoi(l1[0]);
    int y1 = stoi(l1[1]);
    int x2 = stoi(l1[2]);
    int y2 = stoi(l1[3]);

    // Step 3: Check if the denominator is not zero to calculate the quotient
    int denominator = x2 - x1;
    int numerator = y2 - y1;
    if (denominator != 0)
    {
        float quotient = numerator / denominator;

        // Step 4: If the numerator is zero, calculate the distance and print the coordinates of two points
        if (numerator == 0)
        {
            int d = int(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
            int x4 = x1;
            int x3 = x2;
            int y3 = y2 + d;
            int y4 = y1 + d;
            cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
        }

        // Step 5: If the denominator is zero, print the coordinates of two points based on the distance calculated
        else if (denominator == 0)
        {
            int y4 = y2;
            int y3 = y1;
            int d = int(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
            int x4 = x1 + d;
            int x3 = x2 + d;
            cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
        }

        // Step 6: If the quotient is 1 or -1, swap the coordinates and print them
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

        // Step 7: If none of the above conditions are met, print -1
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}

