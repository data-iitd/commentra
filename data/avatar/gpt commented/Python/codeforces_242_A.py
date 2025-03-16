# Read input values for x, y, a, and b and convert them to integers
x, y, a, b = map(int, input().split())

# Initialize an empty list to store valid game pairs
games = []

# Iterate over the range from a to x (inclusive)
for i in range(a, x + 1):
    # Skip the iteration if i is less than or equal to b
    if i <= b:
        continue
    else:
        # Iterate over the range from b to y (inclusive)
        for j in range(b, y + 1):
            # Check if the current i is greater than j
            if i > j:
                # If the condition is met, append the pair (i, j) to the games list
                games.append((i, j))

# Print the total number of valid game pairs found
print(len(games))

# Print each valid game pair
for i in games:
    print(f"{i[0]} {i[1]}")
