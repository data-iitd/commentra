#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

# Initialize variables to store the answer, maximum value, sum, minimum value, and count
ans, mx, sum, mn = 1e8, cnt = 1

# Read the input value for h
h = int(input())

# Loop until h becomes 1
while h != 1:
    # If h is odd, decrement it by 1 to make it even
    if h % 2 != 0:
        h -= 1

    # Divide h by 2
    h /= 2

    # Double the count for each iteration
    cnt *= 2

    # Accumulate the count into the answer
    ans += cnt

# Output the final answer incremented by 1
print(ans + 1)

