#include <iostream> // Including the iostream library for input and output
#include <algorithm> // Including algorithm for using min function

using namespace std;

int main() {
    // Reading the prices of different quantities of the item
    long long Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N; // Input prices and number of items

    // Calculating the minimum price for a single item based on the given prices
    long long onePrice = min({Q * 4, H * 2, S});

    // Checking if the price of one item is less than or equal to half the price of buying in pairs
    if (static_cast<double>(onePrice) <= static_cast<double>(D) / 2) {
        // If true, calculate the total cost for N items at the price of one item
        cout << N * onePrice << endl;
    } else {
        // If false, calculate the total cost using the pair price and the remaining single item price if N is odd
        cout << (N / 2) * D + (N % 2) * onePrice << endl;
    }

    return 0;
}

// <END-OF-CODE>
