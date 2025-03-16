#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    # Declare variables to hold the coordinates of two points
    x1, x2, y1, y2 = 0, 0, 0, 0
    
    # Input the coordinates of the two points from the user
    cin >> x1 >> y1 >> x2 >> y2
    
    # Calculate the differences in x and y coordinates
    dx = x2 - x1 # Difference in x-coordinates
    dy = y2 - y1 # Difference in y-coordinates
    
    # Calculate the coordinates of the two new points that form a rectangle
    x3 = x2 - dy # x-coordinate of the third point
    y3 = y2 + dx # y-coordinate of the third point
    x4 = x1 - dy # x-coordinate of the fourth point
    y4 = y1 + dx # y-coordinate of the fourth point
    
    # Output the coordinates of the two new points
    cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << endl
    
    return 0 # Indicate that the program ended successfully
}
