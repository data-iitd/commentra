
#include <iostream>
using namespace std;

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

def solve():
    # Initialize variables
    a, b = 0, 0

    # Read input values from the user
    a, b = map(int, input().split())

    # Initialize output string
    ans = ""

    # Determine the answer based on the input values
    if a == 1 and b == 1:
        # Both a and b are equal to 1, so the answer is a draw
        ans = "Draw"
    elif a == 1:
        # a is equal to 1, so the answer is Alice
        ans = "Alice"
    else:
        # Neither a nor b is equal to 1, so the answer is Bob
        ans = "Bob"

    # Print the answer to the console
    print(ans)

solve()

# 