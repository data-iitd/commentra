#######
# Code
#######

# Import map function from built-in module
# This function applies a given function to each item of an iterable
import mapper as map  # Alias map for readability

# Take input from user as a list of four integers
R, G, B, N = map(int, input().split())

# Initialize score to 0
score = 0

# Nested for loop to check all possible combinations of i and j
for i in range(int(N / R) + 1):  # Check if i goes up to the ceiling of N/R
    for j in range(int((N - i * R) / G) + 1):  # Check if j goes up to the ceiling of (N-i*R)/G
        # Check if the condition is satisfied
        if N - i * R - j * G >= 0 and (N - i * R - j * G) % B == 0:
            score += 1  # Increment score if condition is satisfied

# Print the final score
print(score)
