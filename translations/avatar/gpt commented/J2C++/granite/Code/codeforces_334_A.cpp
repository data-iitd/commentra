
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a Scanner object for input and a PrintWriter for output
    // Read an integer n from input
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
            // Add to even vector if the number is even
            even.push_back(i);
        } else {
            // Add to odd vector if the number is odd
            odd.push_back(i);
        }
    }

    // Calculate the number of loops and the division for pairing
    int loop = square / n;
    int div = loop / 2;

    // Debug output to check the value of div
    cout << div << endl;

    // Loop through the number of rows to print the pairs
    for (int i = 1; i <= loop; i++) {
        // For each row, print div pairs of numbers
        for (int j = 0; j < div; j++) {
            // Alternate between odd and even pairs based on the row number
            if (i % 2 == 1) {
                // For odd rows, print an odd number and the last even number
                cout << odd.front() << " " << even.back() << " ";
                // Remove the printed numbers from the vectors
                odd.erase(odd.begin());
                even.pop_back();
            } else {
                // For even rows, print an even number and the last odd number
                cout << even.front() << " " << odd.back() << " ";
                // Remove the printed numbers from the vectors
                even.erase(even.begin());
                odd.pop_back();
            }
        }
        // Move to the next line after printing pairs for the current row
        cout << endl;
    }

    return 0;
}
