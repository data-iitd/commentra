#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

const double inf = 1e12; // Constants should be defined with clear names and values

int main() {
    // Initialize variables and read input
    int n;
    cin >> n;

    vector<int> arrA(n); // Create a vector of size n to store input
    for (int i = 0; i < n; i++) {
        cin >> arrA[i]; // Read each element of the vector
    }

    vector<int> cumSumA(n + 1, 0); // Create a vector of size n+1 to store cumulative sum
    // Initialize the first element of cumulative sum vector

    // Iterate through the vector and calculate cumulative sum
    for (int i = 0; i < n; i++) {
        cumSumA[i + 1] = cumSumA[i] + arrA[i];
    }

    // Initialize variable to store the answer
    double ans = inf; // Initialize with a large value

    // Iterate through the vector to find the answer
    for (int i = 1; i < n; i++) {
        double temp = double(cumSumA[n]) - double(cumSumA[i]) * 2; // Calculate the difference
        if (fabs(temp) < ans) { // If the difference is smaller than the current answer
            ans = temp; // Update the answer
        }
    }

    // Print the answer
    cout << static_cast<int>(ans) << endl;

    // End of the code
    return 0;
}
