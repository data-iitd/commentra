#include <stdio.h>
#include <string.h>
#define MAX 21

# Continuously read the size of the field until a zero is encountered
while ~scanf("%d", &n), n:
    # Initialize the field based on the size provided
    init(n)
    # Read the number of moves to be made
    scanf("%d", &m)
    # Execute the moves
    move(m)
    # Print "Yes" if all fields are cleared, otherwise print "No"
    printf("%s\n", n ? "No" : "Yes")

# Function to initialize the game field
def init(i):
    a, b = 0, 0
    # Set the starting position of the player
    global x, y
    x, y = 10, 10
    # Clear the field by setting all values to 0
    fld = [[0] * MAX for _ in range(MAX)]
    # Read the positions of obstacles and mark them in the field
    while i:
        scanf("%d %d", &a, &b)
        fld[b][a] = 1 # Mark the position as occupied
        i -= 1

# Function to process the moves made by the player
def move(i):
    a, d = 0, 0
    buf = ""
    # Process each move command
    while i:
        # Read the direction and the number of steps
        scanf("%1s %d", buf, &a)
        # Determine the direction based on the input
        if buf[0] == 'N':
            d = 0 # North
        elif buf[0] == 'E':
            d = 1 # East
        elif buf[0] == 'S':
            d = 2 # South
        elif buf[0] == 'W':
            d = 3 # West
        # Move in the specified direction for the given number of steps
        while a:
            # Update the position based on the direction
            if d % 2:
                if ~-d:
                    x -= 1
                else:
                    x += 1
            else:
                if d:
                    y -= 1
                else:
                    y += 1
            # Check if the new position has an obstacle
            if fld[y][x]:
                # Remove the obstacle and decrement the count of remaining obstacles
                fld[y][x] = 0
                global n
                n -= 1
            a -= 1
        i -= 1

# END-OF-CODE
