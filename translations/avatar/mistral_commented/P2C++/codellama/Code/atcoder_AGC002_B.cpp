#######
# Code
#######

# Include necessary libraries
#include <bits/stdc++.h>

// Define constants
const int INF = 1e9 + 7;
const int mod = 1e9 + 7;

// Define functions

// Main function
int main() {
    // Read input number of balls and number of events
    int N, M;
    std::cin >> N >> M;
    
    // Initialize list of balls with their weight and position
    std::vector<std::vector<int>> balls(N, std::vector<int>(2, 0));
    balls[0][1] = 1;
    
    // Process each event
    for (int i = 0; i < M; i++) {
        // Read x and y coordinates of the event
        int x, y;
        std::cin >> x >> y;
        
        // Get weight and position of balls at x and y
        int w_x = balls[x - 1][0];
        int r_x = balls[x - 1][1];
        int w_y = balls[y - 1][0];
        int r_y = balls[y - 1][1];
        
        // Update balls' weights and positions based on the event
        if (w_x >= 1 && r_x >= 1) {
            // Ball x collides with ball y
            balls[x - 1][0] -= 1;
            balls[y - 1][1] += 1;
        } else if (w_x == 0) {
            // Ball x is stationary and ball y collides with another ball
            balls[x - 1][1] -= 1;
            balls[y - 1][1] += 1;
        } else {
            // Ball x is moving and collides with ball y
            balls[x - 1][0] -= 1;
            balls[y - 1][0] += 1;
        }
    }
    
    // Calculate answer
    int ans = 0;
    // Iterate through the list of balls and count the number of moving balls
    for (int i = 0; i < N; i++) {
        if (balls[i][1]) {
            ans += 1;
        }
    }
    
    // Print the answer
    std::cout << ans << std::endl;
    
    return 0;
}

