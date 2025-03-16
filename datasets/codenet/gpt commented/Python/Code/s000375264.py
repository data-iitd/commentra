# Read two integers from input: X and t
X, t = map(int, input().split())

# Check if X is greater than t
if X > t:
    # If X is greater than t, calculate the difference
    answer = X - t
elif X <= t:
    # If X is less than or equal to t, set answer to 0
    answer = 0

# Output the result
print(answer)
