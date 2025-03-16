#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

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

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vp;

// Global variables
int ans = INF;
int h = 19,w = 15;
vs s(19); // 2D vector to store the grid
int dx[] = {0,1,0,-1,1,1,-1,-1};
int dy[] = {1,0,-1,0,1,-1,1,-1};

// Function to perform a depth-first search from a given position
// with a given number of steps
void dfs(int x, int y, int cnt){
    // Base case: if the number of steps is greater than 20, return
    if(cnt > 20)return;

    // Print the current position, number of steps, and the current state of the grid
    // for debugging purposes
    //cout << x << " " << y << " " << cnt << endl;
    // Print the current state of the grid
    //rep(i,h)cout << s[i]<<endl;

    // Check if the current position is the last row of the grid
    if(x == h-1){
        // Update the answer if the current number of steps is less than the previous answer
        ans = min(ans,cnt);
        return;
    }

    // Iterate through all the possible directions
    rep(i,8){
        int nx = x + dx[i];
        int ny = y + dy[i];

        // Check if the next position is out of the grid
        if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;

        // Check if the next position contains an 'X'
        if(s[nx][ny] != 'X')continue;

        // Perform a depth-first search from the next position with one more step
        bool c = true;
        while(c && s[nx][ny] == 'X'){
            s[nx][ny] = '.';
            nx += dx[i];
            ny += dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                if(nx >= h)ans = min(ans, cnt+1);
                c = false;
            }
        }

        // If the loop did not exit due to an out-of-grid position, perform the depth-first search
        if(c)dfs(nx,ny,cnt+1);

        // Backtrack by restoring the previous state of the grid
        while(nx != x || ny != y){
            nx -= dx[i];
            ny -= dy[i];
            s[nx][ny] = 'X';
        }

        // Restore the current position of the 'O'
        s[x][y] = '.';
    }
}

// Main function
int main(void) {
    // Initialize the 2D vector to store the grid
    rep(i,h)cin >> s[i];

    // Find the position of the 'O'
    int sx,sy;
    rep(i,h)rep(j,w)if(s[i][j] == 'O'){
        sx = i, sy = j;
        s[i][j] = '.';
    }

    // Perform a depth-first search from the position of the 'O' with 0 steps
    dfs(sx,sy,0);

    // Print the answer if it is not equal to INF
    if(ans == INF)cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}

