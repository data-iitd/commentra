#include<stdio.h>
#define N 4

// Define a structure to represent the puzzle state
typedef struct{
  int P[N][N]; // 2D array to hold the puzzle grid
}Pazz;

Pazz Q; // Global variable to hold the current state of the puzzle
int dx[4]={0,1,0,-1}; // Array to represent movement in the x-direction (right, down, left, up)
int dy[4]={1,0,-1,0}; // Array to represent movement in the y-direction (right, down, left, up)

// Function to calculate the heuristic value (Manhattan distance) of the puzzle state
int Heu(Pazz Q){
  int i, j;
  int hx, hy, sum = 0; // Initialize variables for horizontal and vertical distances, and sum

  // Loop through each cell in the puzzle
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      // Skip the empty tile (represented by 0)
      if(Q.P[i][j] == 0) continue;

      // Calculate the expected position of the tile
      hx = (Q.P[i][j] - 1) % N - j; // Horizontal distance
      hy = (Q.P[i][j] - 1) / N - i; // Vertical distance

      // Update the sum based on the distances
      if(hx < 0) sum -= hx; // If hx is negative, subtract it from sum
      else sum += hx; // Otherwise, add it to sum

      if(hy < 0) sum -= hy; // If hy is negative, subtract it from sum
      else sum += hy; // Otherwise, add it to sum
    }
  }
  return sum; // Return the total heuristic value
}

// Depth-first search function to explore possible moves
int dfs(int x, int y, int max, int count, int n){
  int i, temp;
  int x0, y0, ans = -1, h;

  // Calculate the heuristic value for the current state
  h = Heu(Q);

  // If the puzzle is solved (heuristic is 0), return the count of moves
  if(h == 0) return count;

  // If the current count plus heuristic exceeds the maximum allowed, return -1
  if((count + h) > max) return -1;

  // Explore all possible moves
  for(i = 0; i < 4; i++){
    x0 = x + dx[i]; // Calculate new x position
    y0 = y + dy[i]; // Calculate new y position

    // Check if the move is valid and not reversing the last move
    if(((i == (n + 2) % 4) && (n != -1)) || !((0 <= x0) && (x0 < N) && (0 <= y0) && (y0 < N)))) continue;

    // Swap the empty tile with the adjacent tile
    temp = Q.P[y][x];
    Q.P[y][x] = Q.P[y0][x0];
    Q.P[y0][x0] = temp;

    // Recursively call dfs with the new position
    ans = dfs(x0, y0, max, count + 1, i);

    // If a solution is found, return the answer
    if(ans != -1) return ans;

    // Swap back to restore the previous state
    temp = Q.P[y][x];
    Q.P[y][x] = Q.P[y0][x0];
    Q.P[y0][x0] = temp;
  }

  return -1; // Return -1 if no solution is found
}

// Main function to execute the program
int main(){
  int i, j;
  int kx, ky, ans, a; // Variables to hold the position of the empty tile and the answer
  Pazz tP; // Temporary variable to hold the puzzle state

  // Read the puzzle input from the user
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      scanf("%d", &a); // Read each tile value
      Q.P[i][j] = a; // Store the value in the puzzle state
      if(a == 0){ // If the tile is empty
        kx = j; // Store its x position
        ky = i; // Store its y position
      }
    }
  }

  tP = Q; // Copy the initial puzzle state
  // Attempt to solve the puzzle with increasing maximum move limits
  for(i = 1; i < 46; i++){
    Q = tP; // Reset the puzzle state
    ans = dfs(kx, ky, i, 0, -1); // Call dfs to find a solution
    if(ans != -1){ // If a solution is found
      printf("%d\n", ans); // Print the number of moves
      break; // Exit the loop
    }
  }

  return 0; // Return success
}
