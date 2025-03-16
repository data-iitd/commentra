#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>

using namespace std;

// Function to read an integer from input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers from input
void readInts(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

int main() {
    // Read input values for costs of different types of drinks
    long long q, h, s, d;
    cin >> q >> h >> s >> d;

    // Read the number of drinks to be purchased
    int n = readInt();

    // Calculate the best price for 1 liter of drink
    long long best1L = min({q * 4, h * 2, s});

    // Calculate the best price for 2 liters of drink
    long long best2L = min(d, best1L * 2);

    // Calculate and print the total cost based on whether n is even or odd
    if (n % 2 == 0) {
        cout << best2L * (n / 2) << endl;  // Total cost for even number of drinks
    } else {
        cout << best2L * (n / 2) + best1L << endl;  // Total cost for odd number of drinks
    }

    return 0;
}

// <END-OF-CODE>
