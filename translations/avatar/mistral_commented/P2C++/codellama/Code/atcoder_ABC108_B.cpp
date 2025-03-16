#include <iostream>
using namespace std;

int main()
{
    // Take input from the user and split it using a space as the delimiter
    string p;
    cin >> p;
    string x1, y1, x2, y2;
    int i = 0;
    while (p[i] != ' ')
    {
        x1 += p[i];
        i++;
    }
    i++;
    while (p[i] != ' ')
    {
        y1 += p[i];
        i++;
    }
    i++;
    while (p[i] != ' ')
    {
        x2 += p[i];
        i++;
    }
    i++;
    while (p[i] != '\n')
    {
        y2 += p[i];
        i++;
    }

    // Extract the first four elements of the list p and convert them to integers
    int x1_int = stoi(x1);
    int y1_int = stoi(y1);
    int x2_int = stoi(x2);
    int y2_int = stoi(y2);

    // Calculate the differences between the coordinates
    int DIF1 = x2_int - x1_int;
    int DIF2 = y2_int - y1_int;

    // Calculate the coordinates of the other two points based on the given coordinates and the differences
    int x3 = x2_int - DIF2;
    int y3 = y2_int + DIF1;
    int x4 = x1_int - DIF2;
    int y4 = y1_int + DIF1;

    // Print the calculated coordinates in the format x3 x4 y3 y4
    cout << x3 << " " << x4 << " " << y3 << " " << y4 << endl;

    return 0;
}

