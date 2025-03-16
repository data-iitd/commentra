
#####
# Code
#####

# Include necessary headers
#include <bits/stdc++.h>
using namespace std;

// Define constants
const int MOD = 1e9 + 7;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };
const int d8x[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int d8y[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
const int MAX = 1e5;

// Define necessary data structures
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<pii> vpii;
typedef vector<vector<pii>> vvpii;
typedef vector<string> vs;

// Define necessary functions
//...

// Read input number of balls and number of events
int N, M;
cin >> N >> M;

// Initialize list of balls with their weight and position
vector<vector<int>> balls(N, vector<int>(2, 0));
balls[0][1] = 1;

// Process each event
for (int i = 0; i < M; i++) {
    // Read x and y coordinates of the event
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    // Get weight and position of balls at x and y
    int w_x = balls[x][0];
    int r_x = balls[x][1];
    int w_y = balls[y][0];
    int r_y = balls[y][1];

    // Update balls' weights and positions based on the event
    if (w_x >= 1 && r_x >= 1) {
        // Ball x collides with ball y
        balls[x][0]--;
        balls[y][1]++;
    } else if (w_x == 0) {
        // Ball x is stationary and ball y collides with another ball
        balls[x][1]--;
        balls[y][1]++;
    } else {
        // Ball x is moving and collides with ball y
        balls[x][0]--;
        balls[y][0]++;
    }
}

// Calculate answer
int ans = 0;
// Iterate through the list of balls and count the number of moving balls
for (int i = 0; i < N; i++) {
    if (balls[i][1]) {
        ans++;
    }
}

// Print the answer
cout << ans << endl;

