

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the greatest common divisor (gcd) of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int x;
    cin >> x;  // Take an integer input x

    // Calculate the number of distinct cyclic permutations of a string of length x
    cout << 360 / gcd(360, x) << endl;

    return 0;
}



Translate the above Python code to Java and end with comment "