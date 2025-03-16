# Read the values of R, G, B, and N from user input
R, G, B, N = map(int, input().split())

# Initialize the score to count valid combinations
score = 0

# Iterate over the number of R items that can be used (from 0 to N // R)
for i in range(N // R + 1):
    # Iterate over the number of G items that can be used (from 0 to the remaining N after using i R items)
    for j in range((N - i * R) // G + 1):
        # Check if the remaining amount after using i R and j G items is non-negative
        # and if it can be evenly divided by B (i.e., if we can use some B items)
        if N - i * R - j * G >= 0 and (N - i * R - j * G) % B == 0:
            # If both conditions are met, increment the score (valid combination found)
            score += 1

# Output the total number of valid combinations found
print(score)
