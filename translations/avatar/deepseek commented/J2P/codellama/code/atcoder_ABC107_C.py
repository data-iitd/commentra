
import math
import sys

# Read the input
N, K = map(int, input().split())
S = list(map(int, input().split()))

# Initialize variables
temp = 0
ans = 1000000000

# Check if K is equal to 1
if K == 1:
    for i in range(N):
        temp = S[i]
        ans = min(abs(temp), ans)
    print(ans)

# Check if the length of the subarray is not zero
elif N - K != 0:
    for i in range(N - K + 1):
        min = S[i]
        max = S[i + K - 1]

        # Check if the subarray contains both positive and negative numbers
        if min < 0 and max > 0:
            temp = min(2 * (-min) + max, (-min) + 2 * max)
        else:
            temp = max(abs(min), abs(max))

        ans = min(ans, temp)
    print(ans)

# If the length of the subarray is zero
else:
    min = S[0]
    max = S[N - 1]

    # Check if the array contains both positive and negative numbers
    if min < 0 and max > 0:
        print(min(2 * (-min) + max, (-min) + 2 * max))
    else:
        print(max(abs(min), abs(max)))

# End of code
