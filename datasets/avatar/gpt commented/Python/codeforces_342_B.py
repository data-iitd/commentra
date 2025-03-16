# Define a lambda function to read multiple integers from input
R = lambda: map(int, input().split())

# Read the values of n (total positions), m (number of obstacles), s (starting position), and f (finishing position)
n, m, s, f = R()

# Determine the direction of movement based on the starting and finishing positions
if s < f:
    d = 1  # Move right
    c = 'R'  # Character representing right movement
else:
    d = -1  # Move left
    c = 'L'  # Character representing left movement

# Initialize the result string to store the path taken
res = ""

# Initialize the step counter and current position
i = 1
j = s

# Read the first obstacle's position and range
t, l, r = R()
k = 1  # Counter for the number of obstacles processed

# Loop until the current position reaches the finishing position
while j != f:
    # Check if we need to read a new obstacle's position and range
    if i > t and k < m:
        t, l, r = R()  # Read the next obstacle's position and range
        k += 1  # Increment the obstacle counter

    # Check if the current position is at an obstacle
    if i == t and (l <= j <= r or l <= j + d <= r):
        res += 'X'  # Mark the position with 'X' if it's blocked by an obstacle
    else:
        res += c  # Append the direction character to the result
        j += d  # Move to the next position in the determined direction

    i += 1  # Increment the step counter

# Print the resulting path taken
print(res)
