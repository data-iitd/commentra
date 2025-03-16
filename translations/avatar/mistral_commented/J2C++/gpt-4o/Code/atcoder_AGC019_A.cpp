#include <iostream> // Including the iostream library for input and output
#include <algorithm> // Including the algorithm library for the min function

using namespace std; // Using the standard namespace

int main() { // Defining the main function
    long long Q, H, S, D, N; // Declaring variables to hold the input values

    cin >> Q >> H >> S >> D >> N; // Reading the input values from standard input

    long long onePrice = min(min(Q * 4, H * 2), S); // Calculating the minimum price per item among Q*4, H*2, and S

    if (static_cast<double>(onePrice) <= static_cast<double>(D) / 2) { // Checking if the minimum price per item is less than or equal to half of the deposit amount
        cout << N * onePrice << endl; // If true, printing the result as the product of N and the minimum price per item
    } else { // If false, the following block is executed
        cout << (N / 2) * D + (N % 2) * onePrice << endl; // Calculating and printing the result as the sum of half of N multiplied by the deposit amount and the remaining N (if any) multiplied by the minimum price per item
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
