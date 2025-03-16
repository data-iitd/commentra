
import sys

# Read input from the user
H, W = map(int, input().split())

# Calculate the final answer
ans = 0
if H == 1 or W == 1:
    ans = 1
else:
    m = H * W
    if m % 2 == 0:
        ans = m // 2
    else:
        ans = m // 2 + 1

# Output the final answer
print(ans)

