#include <iostream>
using namespace std;

using uint = unsigned int; // Define alias for unsigned int
using ll = long long;      // Define alias for long long
using ull = unsigned long long; // Define alias for unsigned long long
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

// Define the solve function, which can be used for problem-solving encapsulation
def solve():
    pass

a, b = map(int, input().split()) # Read two integers from standard input
ans = ""

# Check if either a or b is 1 and determine the winner based on their values
if a == 1 or b == 1:
    if a == 1 and b == 1:
        ans = "Draw" # If both a and b are 1, it's a draw
    elif a == 1:
        ans = "Alice" # If a is 1, Alice wins
    else:
        ans = "Bob" # If b is 1, Bob wins
else:
    # If neither a nor b is 1, determine the winner based on their values
    if a == b:
        ans = "Draw" # If a and b are equal, it's a draw
    elif a > b:
        ans = "Alice" # If a is greater than b, Alice wins
    else:
        ans = "Bob" # If b is greater than a, Bob wins

print(ans) # Output the result to standard output

# 