
#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    # Define variables to store input coordinates
    x1, x2, y1, y2 = 0, 0, 0, 0

    # Read input coordinates from standard input
    cin >> x1 >> y1 >> x2 >> y2

    # Calculate differences between final and initial coordinates
    dx = x2 - x1
    dy = y2 - y1

    # Calculate coordinates of points to the left and above, and right and below the final point
    x3 = x2 - dy
    y3 = y2 + dx
    x4 = x1 - dy
    y4 = y1 + dx

    # Print the calculated coordinates to the standard output
    cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << endl

    # End the program with a return statement of 0
    return 0
}

