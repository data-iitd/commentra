# Initialize an empty dictionary to store the visited positions
record_of_movements = input()
x, y = 0, 0 # Initialize the starting position of the bug
d_movement = { # Define a dictionary to store the direction of movement
    'L': (0, -1),
    'R': (0, 1),
    'U': (1, 0),
    'D': (-1, 0)
}
d = { # Initialize an empty dictionary to store the visited positions
    (x, y): ''
}
bug = False # Initialize a boolean variable to check if the bug is trapped

# Iterate through each movement in the record
for move in record_of_movements:
    # Save the current position of the bug
    temp = (x, y)

    # Move the bug based on the given direction
    x += d_movement[move][0]
    y += d_movement[move][1]

    # Check if the new position is already visited
    if (x, y) not in d:
        # If yes, check if there is a loop in the path
        for step in d_movement:
            if (x + d_movement[step][0], y + d_movement[step][1]) != temp and (x + d_movement[step][0], y + d_movement[step][1]) in d:
                # If a loop is found, set the bug is trapped flag
                bug = True
                break

    # If the new position is not visited, set it as visited
    d[(x, y)] = ''

# Check if the bug is trapped
if bug:
    print('BUG')
else:
    print('OK')