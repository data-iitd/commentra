import sys
input = sys.stdin.readline

# Read the integer input
n = int(input())

# Initialize the answer variable to a very large number
ans = 10 ** 18

# Loop from 1 to the square root of n plus 2
for i in range(1, int(n ** (1 / 2)) + 2):
    # Check if i is a divisor of n
    if n % i != 0:
        continue
    # Calculate the corresponding divisor j
    j = n // i
    # Update the answer with the minimum value of current ans and i + j - 2
    ans = min(ans, i + j - 2)

# Print the final answer
print(ans)