#include <iostream>

using namespace std;

int G(int a, int b) {
    // Calculate the greatest common divisor (GCD) of a and b using the Euclidean algorithm
    while (a % b!= 0) {
        a = b;
        b = a % b;
    }
    return b;
}

int L(int a, int b) {
    // Calculate the least common multiple (LCM) of a and b using the relationship between GCD and LCM
    return a * b / G(a, b);
}

int main() {
    // Read four integers x, y, a, and b from the input
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    // Calculate the LCM of x and y
    int lcm = L(x, y);

    // Compute the number of integers in the range from a to b that are divisible by lcm
    // and print the result
    cout << b / lcm - (a - 1) / lcm << endl;

    return 0;
}

