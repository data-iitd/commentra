#include<iostream>
using namespace std;

int main() {
    // Declare variables for width (W), height (H), circle center coordinates (x, y), and radius (r)
    int W, H, x, y, r;

    // Read input values for width, height, circle center coordinates, and radius
    cin >> W >> H >> x >> y >> r;

    // Check if the circle is out of bounds on any side
    if (x - r < 0 || x + r > W || y - r < 0 || y + r > H) {
        // If the circle exceeds the boundaries, print "No"
        cout << "No" << endl;
    }
    // Check if the circle is completely within the bounds
    else if (x - r >= 0 && x + r <= W && y - r >= 0 && y + r <= H) {
        // If the circle is completely within the boundaries, print "Yes"
        cout << "Yes" << endl;
    }

    // End of the program
    return 0;
}
