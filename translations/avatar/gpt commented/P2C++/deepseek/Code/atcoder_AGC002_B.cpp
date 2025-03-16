#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

// Function to read a line of input and strip whitespace
string input() {
    string line;
    getline(cin, line);
    return line;
}

// Function to read an integer from input
int INT() {
    return stoi(input());
}

// Function to read a list of integers from input
vector<int> LIST() {
    string line = input();
    vector<int> numbers;
    string num;
    for (char ch : line) {
        if (ch == ' ') {
            numbers.push_back(stoi(num));
            num.clear();
        } else {
            num += ch;
        }
    }
    if (!num.empty()) {
        numbers.push_back(stoi(num));
    }
    return numbers;
}

int main() {
    // Read the number of balls (N) and the number of operations (M)
    vector<int> NM = LIST();
    int N = NM[0];
    int M = NM[1];

    // Initialize a vector to represent the state of each ball (weight and radius)
    vector<vector<int>> balls(N, vector<int>(2, 0));
    balls[0] = {0, 1};  // Set the first ball's state

    // Process each operation
    for (int i = 0; i < M; ++i) {
        vector<int> operation = LIST();
        int x = operation[0] - 1;
        int y = operation[1] - 1;

        // Get the state of ball x
        int w_x = balls[x][0];
        int r_x = balls[x][1];

        // Get the state of ball y
        int w_y = balls[y][0];
        int r_y = balls[y][1];

        // Update the states of the balls based on their weights and radii
        if (w_x > 0 && r_x > 0) {
            balls[x][0]--;  // Decrease weight of ball x
            balls[y][1]++;  // Increase radius of ball y
        } else if (w_x == 0) {
            balls[x][1]--;  // Decrease radius of ball x
            balls[y][1]++;  // Increase radius of ball y
        } else {
            balls[x][0]--;  // Decrease weight of ball x
            balls[y][0]++;  // Increase weight of ball y
        }
    }

    // Calculate the number of balls with a non-zero radius
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (balls[i][1] > 0) {  // Check if the radius of the ball is non-zero
            ans++;  // Increment the count of balls with non-zero radius
        }
    }

    // Print the final count of balls with non-zero radius
    cout << ans << endl;

    return 0;
}
