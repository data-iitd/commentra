# Read two integers n and k from input, where n is the total number of elements and k is the position of interest
n, k = map(int, input().split())

# Read the string of values (v) from input
v = input()

# Define the directions for movement: LEFT and RIGHT
d = ["LEFT", "RIGHT"]

# Determine if we should move LEFT or RIGHT based on the position k
# If k is closer to the start (LEFT), f will be True; otherwise, it will be False
f = k - 1 < n - k

# Calculate the minimum number of moves needed to reach the desired position
m = min(k - 1, n - k)

# Initialize an empty list to store the sequence of moves and prints
a = []

# Append the necessary number of LEFT or RIGHT moves to the list based on the calculated minimum moves
for i in range(0, m):
    a.append(d[not f])  # Append the opposite direction of f

# Append the print commands for each character in the string v
# The slicing reverses the order of characters if moving RIGHT (f is True)
for i in v[:: -1 + 2 * f]:
    a.append("PRINT " + i)  # Append the print command for the current character
    a.append(d[f])          # Append the direction for the next move

# Print the final sequence of moves and print commands, excluding the last move
print(*a[:-1], sep="\n")
