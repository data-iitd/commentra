#include <iostream>
#include <vector>
using namespace std;

// Define constants for infinity and modulo
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
    // Read the number of balls (N) and the number of operations (M)
    int N, M;
    cin >> N >> M;

    // Initialize a vector to represent the state of each ball (weight and radius)
    vector<pair<int, int>> balls(N, {1, 0});
    balls[0] = {0, 1};  // Set the first ball's state

    // Process each operation
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;  // Read the indices of the balls to operate on
        x--; y--;  // Convert to zero-based index

        int w_x = balls[x].first;  // Get the weight of ball x
        int r_x = balls[x].second;  // Get the radius of ball x
        int w_y = balls[y].first;  // Get the weight of ball y
        int r_y = balls[y].second;  // Get the radius of ball y

        // Update the states of the balls based on their weights and radii
        if (w_x >= 1 && r_x >= 1) {
            balls[x].first--;  // Decrease weight of ball x
            balls[y].second++;  // Increase radius of ball y
        } else if (w_x == 0) {
            balls[x].second--;  // Decrease radius of ball x
            balls[y].second++;  // Increase radius of ball y
        } else {
            balls[x].first--;  // Decrease weight of ball x
            balls[y].first++;  // Increase weight of ball y
        }
    }

    // Calculate the number of balls with a non-zero radius
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (balls[i].second > 0) {  // Check if the radius of the ball is non-zero
            ans++;  // Increment the count of balls with non-zero radius
        }
    }

    // Print the final count of balls with non-zero radius
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
