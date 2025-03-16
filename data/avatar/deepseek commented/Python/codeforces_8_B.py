
record_of_movements = input()  # Take input for the movements of a character
x, y = 0, 0  # Initialize the starting position (x, y) to (0, 0)
d_movement = {'L': (0, -1), 'R': (0, 1), 'U': (1, 0), 'D': (-1, 0)}  # Define a dictionary that maps each direction to its coordinate changes
d = {(x, y): ''}  # Initialize a dictionary to keep track of visited positions
bug = False  # Set a flag bug to False

for move in record_of_movements:  # Iterate over each movement in the input
    temp = (x, y)  # Store the current position in a temporary variable
    x += d_movement[move][0]  # Update the x-coordinate based on the direction
    y += d_movement[move][1]  # Update the y-coordinate based on the direction
    
    if (x, y) not in d:  # Check if the new position has been visited before
        for step in d_movement:  # Check the surrounding positions
            if (x + d_movement[step][0], y + d_movement[step][1]) != temp and (x + d_movement[step][0], y + d_movement[step][1]) in d:
                bug = True  # Set the bug flag to True if a bug is detected
                break  # Break out of the loop if a bug is detected
    else:
        bug = True  # Set the bug flag to True if the new position has been visited before
    
    if bug:  # Check if a bug was detected
        break  # Break out of the loop if a bug was detected
    
    d[(x, y)] = ''  # Add the new position to the dictionary d

if bug:  # Check if a bug was detected
    print('BUG')  # Print 'BUG' if a bug was detected
else:
    print('OK')  # Print 'OK' if no bug was detected