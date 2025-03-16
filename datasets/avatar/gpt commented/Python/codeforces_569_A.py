# Read three integers from input: t (target), s (initial value), and q (growth factor)
t, s, q = map(int, input().split())

# Initialize a counter for the number of iterations
ans = 0

# Loop until the initial value s is less than the target t
while s < t:
    # Multiply the current value of s by the growth factor q
    s *= q
    # Increment the counter for each multiplication
    ans += 1

# Print the total number of multiplications needed for s to reach or exceed t
print(ans)
