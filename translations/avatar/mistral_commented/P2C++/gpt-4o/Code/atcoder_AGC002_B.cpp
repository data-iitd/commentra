#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits>

using namespace std;

// Define constants
const long long INF = numeric_limits<long long>::max();
const long long mod = 1e9 + 7;

// Function to read input
template <typename T>
void read(T &x) {
    cin >> x;
}

int main() {
    // Read input number of balls and number of events
    int N, M;
    read(N);
    read(M);

    // Initialize list of balls with their weight and position
    vector<pair<int, int>> balls(N, {1, 0});
    balls[0] = {0, 1};

    // Process each event
    for (int i = 0; i < M; ++i) {
        // Read x and y coordinates of the event
        int x, y;
        read(x);
        read(y);

        // Get weight and position of balls at x and y
        int w_x = balls[x - 1].first;
        int r_x = balls[x - 1].second;
        int w_y = balls[y - 1].first;
        int r_y = balls[y - 1].second;

        // Update balls' weights and positions based on the event
        if (w_x >= 1 && r_x >= 1) {
            // Ball x collides with ball y
            balls[x - 1].first -= 1;
            balls[y - 1].second += 1;
        } else if (w_x == 0) {
            // Ball x is stationary and ball y collides with another ball
            balls[x - 1].second -= 1;
            balls[y - 1].second += 1;
        } else {
            // Ball x is moving and collides with ball y
            balls[x - 1].first -= 1;
            balls[y - 1].first += 1;
        }
    }

    // Calculate answer
    int ans = 0;
    // Iterate through the list of balls and count the number of moving balls
    for (int i = 0; i < N; ++i) {
        if (balls[i].second) {
            ans += 1;
        }
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
