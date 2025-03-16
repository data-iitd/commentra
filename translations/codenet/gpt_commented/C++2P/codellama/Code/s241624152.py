#include <iostream>
using namespace std;

// Type aliases for convenience
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#define all(x) (x).begin(),(x).end()

// Function to solve the problem (currently empty)
void solve(){

}

int main(){
    // Declare variables to hold the input values
    int a, b;
    
    // Read input values for a and b
    cin >> a >> b;
    
    // Variable to store the result of the game
    string ans;

    # Python code
    if a == 1 or b == 1:
        # Special case when either a or b is 1
        if a == 1 and b == 1:
            # Both players have 1, result is a draw
            ans = "Draw"
        elif a == 1:
            # Alice has 1, Bob wins
            ans = "Alice"
        else:
            # Bob has 1, Alice wins
            ans = "Bob"
    else:
        # General case when both a and b are greater than 1
        if a == b:
            # Both players have equal values, result is a draw
            ans = "Draw"
        elif a > b:
            # Alice has a greater value, she wins
            ans = "Alice"
        else:
            # Bob has a greater value, he wins
            ans = "Bob"

    # Output the result of the game
    print(ans)

    return 0
}

