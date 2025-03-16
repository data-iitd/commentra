# Get user input as a string and convert it to a list of integers
x, y, a, b = map(int, input().split())
# Initialize an empty list to store the games
games = []

# Iterate through a range of numbers from a to x+1
for i in range(a, x + 1):
    # If i is less than or equal to b, skip to the next iteration
    if i <= b:
        continue
    # Iterate through a range of numbers from b to y+1
    for j in range(b, y + 1):
        # If i is greater than j, append the tuple (i, j) to the games list
        if i > j:
            games.append((i, j))

# Print the length of the games list
print(len(games))
# Iterate through the games list and print each tuple
for i in games:
    # Print the tuple as a string in the format "i j"
    print(f"{i[0]} {i[1]}")

# Add a comment explaining the purpose of this block
# Get user input as a string and convert it to a list of integers
x, y, a, b = map(int, input().split())
# Initialize an empty list to store the games
games = []

# Iterate through a range of numbers from a to x+1
for i in range(a, x + 1):
    # If i is less than or equal to b, skip to the next iteration
    if i <= b:
        continue
    # Iterate through a range of numbers from b to y+1
    for j in range(b, y + 1):
        # If i is greater than j, append the tuple (i, j) to the games list
        if i > j:
            games.append((i, j))

# Print the length of the games list
print(len(games))
# Iterate through the games list and print each tuple
for i in games:
    # Print the tuple as a string in the format "i j"
    print(f"{i[0]} {i[1]}")