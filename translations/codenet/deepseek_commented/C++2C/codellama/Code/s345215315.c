#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

// Type definitions for convenience
#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

// Redefining int as long long for larger integer support
#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Type definitions for commonly used data structures
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vp;

// Function to compute the Greatest Common Divisor (GCD) of two numbers
int gcd(int a, int b){
    if(b==0) return a; // Base case: if b is 0, return a
    return gcd(b,a%b); // Recursive call to find GCD
}

// Function to compute the Least Common Multiple (LCM) of two numbers
int lcm(int a, int b){
    return a/gcd(a,b)*b; // LCM formula using GCD
}

// Global variables for the problem
int ans = INF; // Variable to store the minimum number of moves
int h = 19, w = 15; // Dimensions of the grid
int dx[] = {0,1,0,-1,1,1,-1,-1}; // Direction vectors for x-axis
int dy[] = {1,0,-1,0,1,-1,1,-1}; // Direction vectors for y-axis
vs s(19); // 2D grid representation

// Depth-First Search (DFS) function to explore the grid
void dfs(int x, int y, int cnt){
    // Base case: if the count exceeds 20, stop the search
    if(cnt > 20) return;

    // Check if the bottom row is reached
    if(x == h-1){
        ans = min(ans, cnt); // Update the answer with the minimum moves
        return;
    }

    // Explore all 8 possible directions
    rep(i, 8){
        int nx = x + dx[i]; // New x-coordinate
        int ny = y + dy[i]; // New y-coordinate
        // Check if the new coordinates are within bounds
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        // Check if the current cell is not blocked
        if(s[nx][ny] != 'X') continue;

        bool c = true; // Flag to control the loop
        // Move in the current direction while possible
        while(c && s[nx][ny] == 'X'){
            s[nx][ny] = '.'; // Mark the cell as visited
            nx += dx[i]; // Move to the next cell in the direction
            ny += dy[i];
            // Check if the new coordinates are out of bounds
            if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                if(nx >= h) ans = min(ans, cnt + 1); // Update answer if out of bounds
                c = false; // Stop the loop
            }
        }
        // Recursive DFS call for the new position
        if(c) dfs(nx, ny, cnt + 1);
        // Backtrack: restore the grid to its previous state
        while(nx != x || ny != y){
            nx -= dx[i];
            ny -= dy[i];
            s[nx][ny] = 'X'; // Restore the cell
        }
        s[x][y] = '.'; // Mark the original cell as visited
    }
}

// Main function
signed main(void) {
    // Input the grid
    rep(i, h) scanf("%s", s[i]);
    int sx, sy; // Starting coordinates
    // Find the starting position 'O' and mark it as visited
    rep(i, h) rep(j, w) if(s[i][j] == 'O'){
        sx = i, sy = j; // Store the starting position
        s[i][j] = '.'; // Mark the starting position as visited
    }
    // Start DFS from the initial position
    dfs(sx, sy, 0);
    // Output the result: minimum moves or -1 if not reachable
    if(ans == INF) printf("%d\n", -1);
    else printf("%d\n", ans);
}

