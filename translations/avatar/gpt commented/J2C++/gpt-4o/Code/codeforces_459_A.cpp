#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Read the coordinates of the two points (x1, y1) and (x2, y2)
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // Check if the two points are vertically aligned (same x-coordinate)
    if (x1 == x2) {
        // Calculate the vertical distance between the two points
        int dif = abs(y1 - y2);
        // Output the coordinates of the rectangle formed by the two points
        cout << (x1 + dif) << " " << y1 << " " << (x1 + dif) << " " << y2 << endl;
    }
    // Check if the two points are horizontally aligned (same y-coordinate)
    else if (y1 == y2) {
        // Calculate the horizontal distance between the two points
        int dif = abs(x1 - x2);
        // Output the coordinates of the rectangle formed by the two points
        cout << x1 << " " << (y1 + dif) << " " << x2 << " " << (y2 + dif) << endl;
    }
    // Check if the two points form a square (equal distance in both x and y)
    else if (abs(x1 - x2) == abs(y1 - y2)) {
        // Output the coordinates of the rectangle formed by swapping y-coordinates
        cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
    }
    // If none of the above conditions are met, output -1 indicating no rectangle can be formed
    else {
        cout << -1 << endl;
    }

    return 0;
}

// <END-OF-CODE>
