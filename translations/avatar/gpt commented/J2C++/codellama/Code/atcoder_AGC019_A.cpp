#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Creating a Scanner object to read input from the console
    long Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;
    
    // Calculating the minimum price for a single item based on the given prices
    long onePrice = min(min(Q * 4, H * 2), S);
    
    // Checking if the price of one item is less than or equal to half the price of buying in pairs
    if ((double) onePrice <= (double) D / 2) {
        // If true, calculate the total cost for N items at the price of one item
        cout << N * onePrice << endl;
    } else {
        // If false, calculate the total cost using the pair price and the remaining single item price if N is odd
        cout << (N / 2) * D + (N % 2) * onePrice << endl;
    }
    
    return 0;
}

