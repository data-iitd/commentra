import java.util.*;
import java.io.*;

public class Main {
    // Type definitions for convenience
    static class pii{
        int x, y;
        pii(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    // Function to compute the Greatest Common Divisor (GCD) of two numbers
    static int gcd(int a, int b){
        if(b==0) return a; // Base case: if b is 0, return a
        return gcd(b,a%b); // Recursive call to find GCD
    }

    // Function to compute the Least Common Multiple (LCM) of two numbers
    static int lcm(int a, int b){
        return a/gcd(a,b)*b; // LCM formula using GCD
    }

    // Global variables for the problem
    static int ans = Integer.MAX_VALUE; // Variable to store the minimum number of moves
    static int h = 19, w = 15; // Dimensions of the grid
    static int dx[] = {0,1,0,-1,1,1,-1,-1}; // Direction vectors for x-axis
    static int dy[] = {1,0,-1,0,1,-1,1,-1}; // Direction vectors for y-axis
    static char[][] s = new char[h][w]; // 2D grid representation

    // Depth-First Search (DFS) function to explore the grid
    static void dfs(int x, int y, int cnt){
        // Base case: if the count exceeds 20, stop the search
        if(cnt > 20) return;

        // Check if the bottom row is reached
        if(x == h-1){
            ans = Math.min(ans, cnt); // Update the answer with the minimum moves
            return;
        }

        // Explore all 8 possible directions
        for(int i=0; i<8; i++){
            int nx = x + dx[i]; // New x-coordinate
            int ny = y + dy[i]; // New y-coordinate
            // Check if the new coordinates are within bounds
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            // Check if the current cell is not blocked
            if(s[nx][ny]!= 'X') continue;

            boolean c = true; // Flag to control the loop
            // Move in the current direction while possible
            while(c && s[nx][ny] == 'X'){
                s[nx][ny] = '.'; // Mark the cell as visited
                nx += dx[i]; // Move to the next cell in the direction
                ny += dy[i];
                // Check if the new coordinates are out of bounds
                if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                    if(nx >= h) ans = Math.min(ans, cnt + 1); // Update answer if out of bounds
                    c = false; // Stop the loop
                }
            }
            // Recursive DFS call for the new position
            if(c) dfs(nx, ny, cnt + 1);
            // Backtrack: restore the grid to its previous state
            while(nx!= x || ny!= y){
                nx -= dx[i];
                ny -= dy[i];
                s[nx][ny] = 'X'; // Restore the cell
            }
            s[x][y] = '.'; // Mark the original cell as visited
        }
    }

    // Main function
    public static void main(String[] args) {
        // Input the grid
        Scanner sc = new Scanner(System.in);
        rep(i, h) rep(j, w) s[i][j] = sc.next().charAt(0);
        int sx, sy; // Starting coordinates
        // Find the starting position 'O' and mark it as visited
        rep(i, h) rep(j, w) if(s[i][j] == 'O'){
            sx = i;
            sy = j; // Store the starting position
            s[i][j] = '.'; // Mark the starting position as visited
        }
        // Start DFS from the initial position
        dfs(sx, sy, 0);
        // Output the result: minimum moves or -1 if not reachable
        if(ans == Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(ans);
    }
}

