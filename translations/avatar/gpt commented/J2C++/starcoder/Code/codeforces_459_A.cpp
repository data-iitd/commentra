#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create a Scanner object to read input from the standard input
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(ios::badbit);
    istream_iterator<int> in(cin);
    istream_iterator<int> end;
    ostream_iterator<int> out(cout);
    ostream_iterator<int> end2;
    int x1, y1, x2, y2;
    // Read the coordinates of the two points (x1, y1) and (x2, y2)
    while (in!= end) {
        x1 = *in++;
        y1 = *in++;
        x2 = *in++;
        y2 = *in++;
        // Check if the two points are vertically aligned (same x-coordinate)
        if (x1 == x2) {
            // Calculate the vertical distance between the two points
            int dif = abs(y1 - y2);
            // Output the coordinates of the rectangle formed by the two points
            *out++ = x1 + dif;
            *out++ = y1;
            *out++ = x1 + dif;
            *out++ = y2;
        }
        // Check if the two points are horizontally aligned (same y-coordinate)
        else if (y1 == y2) {
            // Calculate the horizontal distance between the two points
            int dif = abs(x1 - x2);
            // Output the coordinates of the rectangle formed by the two points
            *out++ = x1;
            *out++ = y1 + dif;
            *out++ = x2;
            *out++ = y1 + dif;
        }
        // Check if the two points form a square (equal distance in both x and y)
        else if (abs(x1 - x2) == abs(y1 - y2)) {
            // Output the coordinates of the rectangle formed by swapping y-coordinates
            *out++ = x1;
            *out++ = y2;
            *out++ = x2;
            *out++ = y1;
        }
        // If none of the above conditions are met, output -1 indicating no rectangle can be formed
        else {
            *out++ = -1;
        }
    }
    // Close the output stream
    cout << flush;
    return 0;
}

