import sys
import math
from io import StringIO

# Mock the input
input_text = """4 10
2 3 5 7
"""
sys.stdin = StringIO(input_text)

# Read input values for n and x
n, x = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))

# Sort the array A
A.sort()

# Initialize answer variable
ans = 0
# Count how many elements can be taken from A without exceeding x
for i in range(n):
    if x >= A[i]:
        ans += 1
        x -= A[i]
    else:
        break
# Adjust answer if all elements are taken and there is still remaining x
if ans == n and x > 0:
    ans -= 1
# Print the final answer
print(ans)
