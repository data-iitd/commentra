import java.util.*;

public class Main {
  public static void main(String[] args) {
    int[][] P = new int[4][4]; // 2D array to hold the puzzle grid
    int[] dx = new int[4]; // Array to represent movement in the x-direction (right, down, left, up)
    int[] dy = new int[4]; // Array to represent movement in the y-direction (right, down, left, up)
    int i, j, kx, ky, ans, a; // Variables to hold the position of the empty tile and the answer
    int[] tP = new int[16]; // Temporary array to hold the puzzle state

    // Read the puzzle input from the user
    for(i = 0; i < 4; i++){
      for(j = 0; j < 4; j++){
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt(); // Read each tile value
        P[i][j] = a; // Store the value in the puzzle state
        if(a == 0){ // If the tile is empty
          kx = j; // Store its x position
          ky = i; // Store its y position
        }
      }
    }

    // Copy the initial puzzle state
    for(i = 0; i < 16; i++) tP[i] = P[i / 4][i % 4];

    // Attempt to solve the puzzle with increasing maximum move limits
    for(i = 1; i < 46; i++){
      // Reset the puzzle state
      for(j = 0; j < 16; j++) P[j / 4][j % 4] = tP[j];
      ans = dfs(kx, ky, i, 0, -1); // Call dfs to find a solution
      if(ans!= -1){ // If a solution is found
        System.out.println(ans); // Print the number of moves
        break; // Exit the loop
      }
    }
  }

  // Depth-first search function to explore possible moves
  public static int dfs(int x, int y, int max, int count, int n){
    int i, temp;
    int x0, y0, ans = -1, h;

    // Calculate the heuristic value for the current state
    h = Heu(P);

    // If the puzzle is solved (heuristic is 0), return the count of moves
    if(h == 0) return count;

    // If the current count plus heuristic exceeds the maximum allowed, return -1
    if((count + h) > max) return -1;

    // Explore all possible moves
    for(i = 0; i < 4; i++){
      x0 = x + dx[i]; // Calculate new x position
      y0 = y + dy[i]; // Calculate new y position

      // Check if the move is valid and not reversing the last move
      if(((i == (n + 2) % 4) && (n!= -1)) ||!((0 <= x0) && (x0 < 4) && (0 <= y0) && (y0 < 4)))) continue;

      // Swap the empty tile with the adjacent tile
      temp = P[y][x];
      P[y][x] = P[y0][x0];
      P[y0][x0] = temp;

      // Recursively call dfs with the new position
      ans = dfs(x0, y0, max, count + 1, i);

      // If a solution is found, return the answer
      if(ans!= -1) return ans;

      // Swap back to restore the previous state
      temp = P[y][x];
      P[y][x] = P[y0][x0];
      P[y0][x0] = temp;
    }

    return -1; // Return -1 if no solution is found
  }

  // Function to calculate the heuristic value (Manhattan distance) of the puzzle state
  public static int Heu(int[][] P){
    int i, j;
    int hx, hy, sum = 0; // Initialize variables for horizontal and vertical distances, and sum

    // Loop through each cell in the puzzle
    for(i = 0; i < 4; i++){
      for(j = 0; j < 4; j++){
        // Skip the empty tile (represented by 0)
        if(P[i][j] == 0) continue;

        // Calculate the expected position of the tile
        hx = (P[i][j] - 1) % 4 - j; // Horizontal distance
        hy = (P[i][j] - 1) / 4 - i; // Vertical distance

        // Update the sum based on the distances
        if(hx < 0) sum -= hx; // If hx is negative, subtract it from sum
        else sum += hx; // Otherwise, add it to sum

        if(hy < 0) sum -= hy; // If hy is negative, subtract it from sum
        else sum += hy; // Otherwise, add it to sum
      }
    }
    return sum; // Return the total heuristic value
  }
}

