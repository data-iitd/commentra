
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Take input from the user and split it into a list of strings
    string given;
    cin >> given;
    string l1[4];
    int i = 0;
    for (int j = 0; j < given.length(); j++)
    {
        if (given[j] == ' ')
        {
            i++;
        }
        else
        {
            l1[i] += given[j];
        }
    }

    // Convert the list of strings into a list of integers
    int l2[4];
    for (int i = 0; i < 4; i++)
    {
        l2[i] = stoi(l1[i]);
    }

    // Assign the first four integers to coordinates (x1, y1) and (x2, y2)
    int x1 = l2[0];
    int y1 = l2[1];
    int x2 = l2[2];
    int y2 = l2[3];

    // Calculate the denominator and numerator for slope calculation
    int denominator = x2 - x1;
    int numerator = y2 - y1;

    // Check if the line is not vertical
    if (denominator != 0)
    {
        float quotient = (float)numerator / denominator; // Calculate the slope of the line

        // Check if the line is horizontal
        if (numerator == 0)
        {
            // Calculate the distance between the two points
            int d = (int)sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            // Set new coordinates for the points shifted vertically
            int x4 = x1;
            int x3 = x2;
            int y3 = y2 + d;
            int y4 = y1 + d;
            // Print the new coordinates
            cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
        }

        // Check if the line is vertical
        else if (denominator == 0)
        {
            // Set y-coordinates to the original y-values
            int y4 = y2;
            int y3 = y1;
            // Calculate the distance between the two points
            int d = (int)sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            // Set new coordinates for the points shifted horizontally
            int x4 = x1 + d;
            int x3 = x2 + d;
            // Print the new coordinates
            cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
        }

        // Check if the slope is 1 (45 degrees)
        else if (quotient == 1)
        {
            // Set new coordinates for the points
            int x4 = x2;
            int x3 = x1;
            int y4 = y1;
            int y3 = y2;
            // Print the new coordinates
            cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
        }

        // Check if the slope is -1 (-45 degrees)
        else if (quotient == -1)
        {
            // Set new coordinates for the points
            int x4 = x1;
            int x3 = x2;
            int y4 = y2;
            int y3 = y1;
            // Print the new coordinates
            cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
        }

        // If none of the conditions are met, print -1
        else
        {
            cout << "-1" << endl;
        }
    }

    return 0;
}

