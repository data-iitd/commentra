#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

// Define constants for infinity and long long integer type
#define INF 1 << 29
#define LL long long int

// Define a constant for modulo operation
LL const MOD = 1000000007;

int main(){
    // Optimize input/output operations
    cin.tie(0);
    ios::sync_with_stdio(false);

    // Read the number of elements and the constant c
    LL n, c;
    cin >> n >> c;

    // Initialize vectors to store positions and velocities
    vector<LL> x(n+1, 0), v(n+1, 0);

    // Read the positions and velocities of the elements
    for(int i = 1; i < n+1; i++){
        cin >> x[i] >> v[i];
    }

    // Initialize vectors to store cumulative velocities from the left
    vector<LL> lefttotal(n+1, 0), maxlefttotal(n+1, 0);
    
    // Calculate cumulative velocities from the left
    for(int i = 1; i < n+1; i++){
        lefttotal[i] = lefttotal[i-1] + v[i];
    }

    // Calculate the maximum value of lefttotal adjusted by position
    for(int i = 1; i < n+1; i++){
        maxlefttotal[i] = max(maxlefttotal[i-1], lefttotal[i] - x[i]);
    }

    // Initialize vectors to store cumulative velocities from the right
    vector<LL> righttotal(n+1, 0), maxrighttotal(n+1, 0);
    
    // Calculate cumulative velocities from the right
    for(int i = 1; i < n+1; i++){
        righttotal[i] = righttotal[i-1] + v[n-i+1];
    }
    
    // Calculate the maximum value of righttotal adjusted by position
    for(int i = 1; i < n+1; i++){
        maxrighttotal[i] = max(maxrighttotal[i-1], righttotal[i] - (c - x[n+1-i]));
    }

    // Initialize the answer variable to store the maximum result
    LL ans = 0;

    // Evaluate the maximum possible value based on different scenarios
    for(int i = 1; i < n+1; i++){
        ans = max(ans, lefttotal[i] - x[i]); // Scenario 1
        ans = max(ans, lefttotal[i] - 2 * x[i] + maxrighttotal[n-i]); // Scenario 2
        ans = max(ans, righttotal[i] - (c - x[n+1-i])); // Scenario 3
        ans = max(ans, righttotal[i] - 2 * (c - x[n+1-i]) + maxlefttotal[n-i]); // Scenario 4
    }

    // Output the final result
    cout << ans << endl;
    
    return 0;
}

