# Get input as string
input_str = input().split()
# Convert input string to list of integers
X, t = map(int, input_str)

# Check if X is greater than t
if X > t:
    # Calculate the difference between X and t
    answer = X - t
else:
    # If X is less than or equal to t
    answer = 0

# Print the answer
print(answer)