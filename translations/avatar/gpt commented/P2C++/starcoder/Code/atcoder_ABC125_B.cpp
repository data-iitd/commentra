#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read the number of elements
    int N;
    cin >> N;

    // Read the values into a list and convert them to integers
    vector<int> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    // Read the costs into a list and convert them to integers
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    // Initialize a list to store the profit differences, starting with 0
    vector<int> profit_differences = {0};

    // Initialize a variable to hold the total profit
    int ans = 0;

    // Initialize variables to hold current value and cost
    int X = 0;
    int Y = 0;

    // Iterate through each item
    for (int i = 0; i < N; i++) {
        // Check if the value is greater than the cost
        if (V[i] - C[i] > 0) {
            // Assign the current value and cost to X and Y
            X = V[i];
            Y = C[i];
            // Calculate the profit and append it to the profit differences list
            profit_differences.push_back(X - Y);
        }
    }

    // Calculate and print the total profit by summing the profit differences
    cout << accumulate(profit_differences.begin(), profit_differences.end(), 0) << endl;

    return 0;
}

