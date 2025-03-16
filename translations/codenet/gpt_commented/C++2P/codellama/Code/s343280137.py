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

#define INF 1 << 29
#define LL long long int

#define MOD 1000000007

int main(){
    // Optimize input/output operations
    cin.tie(0);
    ios::sync_with_stdio(false);

    // Read the number of elements and the constant c
    LL n, c;
    cin >> n >> c;

    # <START-OF-CODE>
    # Initialize vectors to store positions and velocities
    x = [0] * (n+1)
    v = [0] * (n+1)

    # Read the positions and velocities of the elements
    for i in range(1, n+1):
        cin >> x[i] >> v[i]

    # Initialize vectors to store cumulative velocities from the left
    lefttotal = [0] * (n+1)
    maxlefttotal = [0] * (n+1)
    
    # Calculate cumulative velocities from the left
    for i in range(1, n+1):
        lefttotal[i] = lefttotal[i-1] + v[i]

    # Calculate the maximum value of lefttotal adjusted by position
    for i in range(1, n+1):
        maxlefttotal[i] = max(maxlefttotal[i-1], lefttotal[i] - x[i])

    # Initialize vectors to store cumulative velocities from the right
    righttotal = [0] * (n+1)
    maxrighttotal = [0] * (n+1)
    
    # Calculate cumulative velocities from the right
    for i in range(1, n+1):
        righttotal[i] = righttotal[i-1] + v[n-i+1]

    # Calculate the maximum value of righttotal adjusted by position
    for i in range(1, n+1):
        maxrighttotal[i] = max(maxrighttotal[i-1], righttotal[i] - (c - x[n+1-i]))

    # Initialize the answer variable to store the maximum result
    ans = 0

    # Evaluate the maximum possible value based on different scenarios
    for i in range(1, n+1):
        ans = max(ans, lefttotal[i] - x[i]) # Scenario 1
        ans = max(ans, lefttotal[i] - 2 * x[i] + maxrighttotal[n-i]) # Scenario 2
        ans = max(ans, righttotal[i] - (c - x[n+1-i])) # Scenario 3
        ans = max(ans, righttotal[i] - 2 * (c - x[n+1-i]) + maxlefttotal[n-i]) # Scenario 4

    # Output the final result
    print(ans)
    # 