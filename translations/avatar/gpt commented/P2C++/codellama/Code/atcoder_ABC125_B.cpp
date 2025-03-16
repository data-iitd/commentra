#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    // Read the number of elements
    int N;
    cin >> N;

    // Read the values into a vector and convert them to integers
    vector<int> V;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int value;
    while (ss >> value) {
        V.push_back(value);
    }

    // Read the costs into a vector and convert them to integers
    vector<int> C;
    getline(cin, input);
    stringstream ss2(input);
    int cost;
    while (ss2 >> cost) {
        C.push_back(cost);
    }

    // Initialize a vector to store the profit differences, starting with 0
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
    for (int i = 0; i < profit_differences.size(); i++) {
        ans += profit_differences[i];
    }
    cout << ans << endl;

    return 0;
}

