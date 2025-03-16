# Read the input string representing movements
record_of_movements = input()

# Initialize the starting coordinates (x, y) at (0, 0)
x, y = 0, 0

# Define the movement directions: Left (L), Right (R), Up (U), Down (D)
d_movement = {'L': (0, -1), 'R': (0, 1), 'U': (1, 0), 'D': (-1, 0)}

# Create a dictionary to track visited coordinates, starting with the initial position
d = {(x, y): ''}

# Initialize a flag to detect if a bug occurs
bug = False

# Iterate through each movement in the input string
for move in record_of_movements:
    # Store the current position before the move
    temp = (x, y)

    # Update the coordinates based on the movement direction
    x += d_movement[move][0]
    y += d_movement[move][1]

    # Check if the new position has already been visited
    if (x, y) not in d:
        # If not visited, check for potential bugs by looking at all movement directions
        for step in d_movement:
            # Check if moving in any direction from the new position leads to a visited position
            if (x + d_movement[step][0], y + d_movement[step][1]) != temp and \
               (x + d_movement[step][0], y + d_movement[step][1]) in d:
                # If a bug is detected, set the flag and break the loop
                bug = True
                break
    else:
        # If the new position was already visited, set the bug flag
        bug = True

    # If a bug has been detected, exit the loop
    if bug:
        break

    # Mark the new position as visited
    d[x, y] = ''

# After processing all movements, check if a bug was detected
if bug:
    # Print 'BUG' if a bug was found
    print('BUG')
else:
    # Print 'OK' if no bugs were found
    print('OK')
