#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <limits.h>
#include <string>
#include <sstream>

using namespace std;

#define INF INT_MAX
#define MOD 1000000007
#define PI 3.14159265358979323846
#define MAX_N 100000
#define MAX_M 100000

// Function to read integers from input
int readInt() {
    int n;
    cin >> n;
    return n;
}

// Function to read a pair of integers from input
pair<int, int> readPair() {
    int x, y;
    cin >> x >> y;
    return {x, y};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read number of balls and number of events
    int N = readInt();
    int M = readInt();

    // Initialize vector of balls with their weight and position
    vector<pair<int, int>> balls(N, {1, 0});
    balls[0] = {0, 1};

    // Process each event
    for (int i = 0; i < M; ++i) {
        // Read x and y coordinates of the event
        auto [x, y] = readPair();

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
    // Iterate through the vector of balls and count the number of moving balls
    for (int i = 0; i < N; ++i) {
        if (balls[i].second) {
            ans += 1;
        }
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}
