#include <iostream>
#include <algorithm> // Include the algorithm header for the gcd function

using namespace std;

int main() {
    int x;
    cin >> x;

    // Calculate the greatest common divisor using the gcd function from the algorithm library
    int gcd_value = __gcd(360, x);

    // Calculate and print the number of equal parts in a full circle (360 degrees) 
    // that can be formed with the given angle x using the gcd
    cout << 360 / gcd_value << endl;

    return 0;
}
