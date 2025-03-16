#include <iostream>
#include <algorithm>  // Include the algorithm header for the gcd function

using namespace std;

int main() {
    int x;
    cin >> x;

    // Calculate the greatest common divisor (gcd) of 360 and x
    int gcd_result = __gcd(360, x);

    // Calculate the number of distinct cyclic permutations of a string of length x
    cout << 360 / gcd_result << endl;

    return 0;
}

