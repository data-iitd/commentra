# Read two integers A and B from input
A, B = map(int, input().split())

# Calculate the minimum and maximum possible values based on B
min = B * 10  # Minimum value is B multiplied by 10
max = (B + 1) * 10 - 1  # Maximum value is (B + 1) multiplied by 10 minus 1

# Initialize the answer variable to -1, indicating no valid answer found yet
ans = -1

# Iterate through the range from min to max (inclusive)
for i in range(min, max + 1):
    # Check if 8% of the current value i equals A
    if int(i * 0.08) == A:
        ans = i  # If condition is met, set ans to the current value i
        break  # Exit the loop as we found a valid answer

# Print the result, which is either the found value or -1 if no valid value was found
print(ans)
