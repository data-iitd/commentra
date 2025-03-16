#include <iostream>
using namespace std;

// Function to calculate the greatest common divisor (GCD) using the Euclidean algorithm
int G(int a, int b) {
    while (a % b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return b;
}

// Function to calculate the least common multiple (LCM) using the relationship between GCD and LCM
int L(int a, int b) {
    return a * b / G(a, b);
}

int main() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    // Calculate the LCM of x and y
    int lcm = L(x, y);

    // Compute the number of integers in the range from a to b that are divisible by lcm
    // and print the result
    cout << b / lcm - (a - 1) / lcm << endl;

    return 0;
}
