#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    // Create input and output streams
    int n;
    cin >> n;

    // Calculate the square of n
    int square = n * n;

    // Initialize vectors to hold odd and even numbers
    vector<int> odd;
    vector<int> even;

    // Populate the odd and even vectors with numbers from 1 to square
    for (int i = 1; i <= square; i++) {
        if (i % 2 == 0) {
            even.push_back(i); // Add to even list if the number is even
        } else {
            odd.push_back(i); // Add to odd list if the number is odd
        }
    }

    // Calculate the number of loops and the division for pairing
    int loop = square / n;
    int div = loop / 2;

    // Debug output to check the value of div
    cerr << div << endl; // Using cerr for debug output

    // Loop through the number of rows to print the pairs
    for (int i = 1; i <= loop; i++) {
        // For each row, print div pairs of numbers
        for (int j = 0; j < div; j++) {
            // Alternate between odd and even pairs based on the row number
            if (i % 2 == 1) {
                // For odd rows, print an odd number and the last even number
                cout << odd.front() << " " << even.back() << " ";
                odd.erase(odd.begin()); // Remove the first odd number
                even.pop_back(); // Remove the last even number
            } else {
                // For even rows, print an even number and the last odd number
                cout << even.front() << " " << odd.back() << " ";
                even.erase(even.begin()); // Remove the first even number
                odd.pop_back(); // Remove the last odd number
            }
        }
        // Move to the next line after printing pairs for the current row
        cout << endl;
    }

    return 0;
}

// <END-OF-CODE>
