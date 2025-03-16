#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;

// Function to compute the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
    // Base case: if 'a' is 0, return 'b' as the GCD
    if (a == 0) return b;
    // Recursive case: call gcd with 'b' modulo 'a' and 'a'
    return gcd(b % a, a);
}

int main() {
    int R; // Variable to store the input rating
    cin >> R; // Read the rating from standard input

    // Determine the category based on the rating value
    if (R < 1200) 
        cout << "ABC" << endl; // Output "ABC" for ratings less than 1200
    else if (R >= 2800) 
        cout << "AGC" << endl; // Output "AGC" for ratings 2800 and above
    else 
        cout << "ARC" << endl; // Output "ARC" for ratings between 1200 and 2800
}
