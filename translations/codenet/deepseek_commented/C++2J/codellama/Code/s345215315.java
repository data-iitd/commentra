
// Java:

// Importing the required libraries
import java.util.*;
import java.lang.*;
import java.io.*;

// Class to compute the Greatest Common Divisor (GCD) of two numbers
class GCD{
    // Function to compute the GCD of two numbers
    public static int gcd(int a, int b){
        if(b==0) return a; // Base case: if b is 0, return a
        return gcd(b,a%b); // Recursive call to find GCD
    }
}

// Class to compute the Least Common Multiple (LCM) of two numbers
class LCM{
    // Function to compute the LCM of two numbers
    public static int lcm(int a, int b){
        return a/GCD.gcd(a,b)*b; // LCM formula using GCD
    }
}

// Class to solve the problem
class Solution{
    // Function to compute the minimum number of moves
    public static int minMoves(int h, int w, char[][] grid){
        // Initialize the answer to INF
        int ans = Integer.MAX_VALUE;
        // Initialize the starting position
        int sx = 0, sy = 0;
        // Find the starting position 'O' and mark it as visited
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(grid[i][j] == 'O'){
                    sx = i;
                    sy = j;
                    grid[i][j] = '.';
                }
            }
        }
        // Start DFS from the initial position
        dfs(sx, sy, grid, 0, ans);
        // Output the result: minimum moves or -1 if not reachable
        if(ans == Integer.MAX_VALUE) return -1;
        else return ans;
    }

    // Depth-First Search (DFS) function to explore the grid
    public static void dfs(int x, int y, char[][] grid, int cnt, int ans){
        // Base case: if the count exceeds 20, stop the search
        if(cnt > 20) return;

        // Check if the bottom row is reached
        if(x == h-1){
            ans = Math.min(ans, cnt); // Update the answer with the minimum moves
            return;
        }

        // Explore all 8 possible directions
        for(int i=0;i<8;i++){
            int nx = x + dx[i]; // New x-coordinate
            int ny = y + dy[i]; // New y-coordinate
            // Check if the new coordinates are within bounds
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            // Check if the current cell is not blocked
            if(grid[nx][ny] != 'X') continue;

            boolean c = true; // Flag to control the loop
            // Move in the current direction while possible
            while(c && grid[nx][ny] == 'X'){
                grid[nx][ny] = '.'; // Mark the cell as visited
                nx += dx[i]; // Move to the next cell in the direction
                ny += dy[i];
                // Check if the new coordinates are out of bounds
                if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                    if(nx >= h) ans = Math.min(ans, cnt + 1); // Update answer if out of bounds
                    c = false; // Stop the loop
                }
            }
            // Recursive DFS call for the new position
            if(c) dfs(nx, ny, grid, cnt + 1, ans);
            // Backtrack: restore the grid to its previous state
            while(nx != x || ny != y){
                nx -= dx[i];
                ny -= dy[i];
                grid[nx][ny] = 'X'; // Restore the cell
            }
            grid[x][y] = '.'; // Mark the original cell as visited
        }
    }

    // Global variables for the problem
    static int h = 19, w = 15; // Dimensions of the grid
    static int dx[] = {0,1,0,-1,1,1,-1,-1}; // Direction vectors for x-axis
    static int dy[] = {1,0,-1,0,1,-1,1,-1}; // Direction vectors for y-axis

    // Main function
    public static void main(String[] args) {
        // Input the grid
        char[][] grid = new char[h][w];
        for(int i=0;i<h;i++){
            String s = sc.nextLine();
            for(int j=0;j<w;j++){
                grid[i][j] = s.charAt(j);
            }
        }
        // Find the starting position 'O' and mark it as visited
        int sx = 0, sy = 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(grid[i][j] == 'O'){
                    sx = i;
                    sy = j;
                    grid[i][j] = '.';
                }
            }
        }
        // Start DFS from the initial position
        int ans = Integer.MAX_VALUE;
        dfs(sx, sy, grid, 0, ans);
        // Output the result: minimum moves or -1 if not reachable
        if(ans == Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(ans);
    }
}

// END-OF-CODE
