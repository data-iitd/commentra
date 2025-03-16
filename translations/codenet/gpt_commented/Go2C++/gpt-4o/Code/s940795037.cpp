#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

// Function to read integers from input
vector<int> readIntArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> result;
    int number;
    while (ss >> number) {
        result.push_back(number);
    }
    return result;
}

// Main function where the execution starts
int main() {
    // Read the number of integers to process
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline character after the integer input

    double ans = 0.0;

    // Loop through each integer, calculate the reciprocal, and accumulate the sum
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        ans += 1.0 / tmp; // Calculate the reciprocal and add to the sum
    }

    // Print the harmonic mean of the input integers
    cout << fixed << setprecision(6) << (1.0 / ans) << endl;

    return 0;
}

// <END-OF-CODE>
