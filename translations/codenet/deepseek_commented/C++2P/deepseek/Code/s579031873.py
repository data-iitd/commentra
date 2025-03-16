import sys

# Read the number of elements and the target value from standard input
N, X = map(int, sys.stdin.readline().split())

# Initialize the answer variable
ans = 0
# Initialize the minimum value variable
min_value = 1000000000
# List to store the elements
elements = []

# Read the elements from standard input
for _ in range(N):
    tmp = int(sys.stdin.readline())
    X -= tmp
    ans += 1
    elements.append(tmp)
    if tmp < min_value:
        min_value = tmp

# Calculate the final answer
ans += X // min_value

# Print the final answer to standard output
print(ans)

# End-of-code comment
