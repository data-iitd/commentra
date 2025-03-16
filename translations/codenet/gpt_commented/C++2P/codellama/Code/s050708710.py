#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    # Declare variables for the number of red, green, blue items and the total number of items
    r, g, b, n = 0, 0, 0, 0

    # Input the values for red, green, blue items and total items
    r, g, b, n = map(int, input().split())

    # Initialize the answer counter to zero
    ans = 0

    # Iterate over the possible counts of red items (i)
    for i in range(0, n // r + 1):
        # Iterate over the possible counts of green items (j)
        for j in range(0, n // g + 1):
            # Calculate the remaining items after selecting i red and j green items
            num = n - r * i - g * j

            # Check if the remaining items can be exactly filled with blue items
            if num >= 0 and num % b == 0:
                # If valid, increment the answer counter
                ans += 1

    # Output the total number of valid combinations found
    print(ans)

    return 0
}

