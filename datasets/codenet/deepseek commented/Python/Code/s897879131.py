# Read the input values for R, G, B, and N
R, G, B, N = map(int, input().split())

# Initialize the score to keep track of valid combinations
score = 0

# Iterate over the possible number of red items
for i in range(N // R + 1):
    # Iterate over the possible number of green items
    for j in range((N - i * R) // G + 1):
        # Check if the remaining items can be exactly divided by blue items
        if N - i * R - j * G >= 0 and (N - i * R - j * G) % B == 0:
            # Increment the score if a valid combination is found
            score += 1

# Print the final score
print(score)
