#include <iostream>
#include <vector>
#define N 4

// Define a structure to represent the puzzle state
struct Pazz {
    int P[N][N]; // 2D array to hold the puzzle grid
};

Pazz Q; // Global variable to hold the current state of the puzzle
int dx[4] = {0, 1, 0, -1}; // Array to represent movement in the x-direction (right, down, left, up)
int dy[4] = {1, 0, -1, 0}; // Array to represent movement in the y-direction (right, down, left, up)

// Function to calculate the heuristic value (Manhattan distance) of the puzzle state
int Heu(Pazz Q) {
    int sum = 0; // Initialize sum

    // Loop through each cell in the puzzle
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Skip the empty tile (represented by 0)
            if (Q.P[i][j] == 0) continue;

            // Calculate the expected position of the tile
            int hx = (Q.P[i][j] - 1) % N - j; // Horizontal distance
            int hy = (Q.P[i][j] - 1) / N - i; // Vertical distance

            // Update the sum based on the distances
            sum += (hx < 0) ? -hx : hx; // Add or subtract horizontal distance
            sum += (hy < 0) ? -hy : hy; // Add or subtract vertical distance
        }
    }
    return sum; // Return the total heuristic value
}

// Depth-first search function to explore possible moves
int dfs(int x, int y, int max, int count, int n) {
    int ans = -1;

    // Calculate the heuristic value for the current state
    int h = Heu(Q);

    // If the puzzle is solved (heuristic is 0), return the count of moves
    if (h == 0) return count;

    // If the current count plus heuristic exceeds the maximum allowed, return -1
    if ((count + h) > max) return -1;

    // Explore all possible moves
    for (int i = 0; i < 4; i++) {
        int x0 = x + dx[i]; // Calculate new x position
        int y0 = y + dy[i]; // Calculate new y position

        // Check if the move is valid and not reversing the last move
        if (((i == (n + 2) % 4) && (n != -1)) || !((0 <= x0) && (x0 < N) && (0 <= y0) && (y0 < N)))) continue;

        // Swap the empty tile with the adjacent tile
        std::swap(Q.P[y][x], Q.P[y0][x0]);

        // Recursively call dfs with the new position
        ans = dfs(x0, y0, max, count + 1, i);

        // If a solution is found, return the answer
        if (ans != -1) return ans;

        // Swap back to restore the previous state
        std::swap(Q.P[y][x], Q.P[y0][x0]);
    }

    return -1; // Return -1 if no solution is found
}

// Main function to execute the program
int main() {
    int kx, ky, ans; // Variables to hold the position of the empty tile and the answer
    Pazz tP; // Temporary variable to hold the puzzle state

    // Read the puzzle input from the user
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> Q.P[i][j]; // Read each tile value
            if (Q.P[i][j] == 0) { // If the tile is empty
                kx = j; // Store its x position
                ky = i; // Store its y position
            }
        }
    }

    tP = Q; // Copy the initial puzzle state
    // Attempt to solve the puzzle with increasing maximum move limits
    for (int i = 1; i < 46; i++) {
        Q = tP; // Reset the puzzle state
        ans = dfs(kx, ky, i, 0, -1); // Call dfs to find a solution
        if (ans != -1) { // If a solution is found
            std::cout << ans << std::endl; // Print the number of moves
            break; // Exit the loop
        }
    }

    return 0; // Return success
}

// <END-OF-CODE>
