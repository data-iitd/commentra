#include<iostream>
#include<vector>
#define N 4

// Define a structure to represent the puzzle state
struct Pazz {
  std::vector<std::vector<int>> P; // 2D vector to hold the puzzle grid
  Pazz() : P(N, std::vector<int>(N)) {} // Constructor to initialize the 2D vector
};

Pazz Q; // Global variable to hold the current state of the puzzle
std::vector<int> dx{0, 1, 0, -1}; // Vector to represent movement in the x-direction (right, down, left, up)
std::vector<int> dy{1, 0, -1, 0}; // Vector to represent movement in the y-direction (right, down, left, up)

// Function to calculate the heuristic value (Manhattan distance) of the puzzle state
int Heu(const Pazz& Q) {
  int sum = 0; // Initialize sum for the Manhattan distance
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (Q.P[i][j] == 0) continue; // Skip the empty tile
      int value = Q.P[i][j] - 1;
      int targetX = value % N;
      int targetY = value / N;
      sum += std::abs(i - targetY) + std::abs(j - targetX); // Calculate Manhattan distance
    }
  }
  return sum; // Return the total heuristic value
}

// Depth-first search function to explore possible moves
int dfs(int x, int y, int max, int count, int n) {
  int h = Heu(Q); // Calculate the heuristic value for the current state
  if (h == 0) return count; // If the puzzle is solved, return the count of moves
  if (count + h > max) return -1; // If the current count plus heuristic exceeds the maximum allowed, return -1
  for (int i = 0; i < 4; ++i) {
    int x0 = x + dx[i]; // Calculate new x position
    int y0 = y + dy[i]; // Calculate new y position
    if (((i == (n + 2) % 4) && (n != -1)) || !(0 <= x0 && x0 < N && 0 <= y0 && y0 < N)) continue;
    std::swap(Q.P[y][x], Q.P[y0][x0]); // Swap the empty tile with the adjacent tile
    int ans = dfs(x0, y0, max, count + 1, i); // Recursively call dfs with the new position
    if (ans != -1) return ans; // If a solution is found, return the answer
    std::swap(Q.P[y][x], Q.P[y0][x0]); // Swap back to restore the previous state
  }
  return -1; // Return -1 if no solution is found
}

// Main function to execute the program
int main() {
  Pazz tP; // Temporary variable to hold the puzzle state
  int kx, ky, ans, a; // Variables to hold the position of the empty tile and the answer
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      std::cin >> a; // Read each tile value
      Q.P[i][j] = a; // Store the value in the puzzle state
      if (a == 0) { // If the tile is empty
        kx = j; // Store its x position
        ky = i; // Store its y position
      }
    }
  }
  tP = Q; // Copy the initial puzzle state
  for (int i = 1; i < 46; ++i) { // Attempt to solve the puzzle with increasing maximum move limits
    Q = tP; // Reset the puzzle state
    ans = dfs(kx, ky, i, 0, -1); // Call dfs to find a solution
    if (ans != -1) { // If a solution is found
      std::cout << ans << std::endl; // Print the number of moves
      break; // Exit the loop
    }
  }
  return 0; // Return success
}
