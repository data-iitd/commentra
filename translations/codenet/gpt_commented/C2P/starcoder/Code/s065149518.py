#include <stdio.h>
#include <string.h>
#define MAX 21

# Function prototypes
def init(i):
    a, b
    # Set the starting position of the player
    x = y = 10
    # Clear the field by setting all values to 0
    fld = [[0 for i in range(MAX)] for j in range(MAX)]
    # Read the positions of obstacles and mark them in the field
    while(i):
        scanf("%d %d", &a, &b)
        fld[b][a] = 1 # Mark the position as occupied
        i -= 1

def move(i):
    a, d
    buf = [0, 0]
    # Process each move command
    while(i):
        # Read the direction and the number of steps
        scanf("%1s %d", buf, &a)
        # Determine the direction based on the input
        if(buf[0] == 'N'):
            d = 0 # North
        elif(buf[0] == 'E'):
            d = 1 # East
        elif(buf[0] == 'S'):
            d = 2 # South
        elif(buf[0] == 'W'):
            d = 3 # West
        # Move in the specified direction for the given number of steps
        while(a):
            # Update the position based on the direction
            d % 2 and ~-d and x-- or x++
            d and y-- or y++
            # Check if the new position has an obstacle
            if(fld[y][x]):
                # Remove the obstacle and decrement the count of remaining obstacles
                fld[y][x] = 0
                n -= 1
            a -= 1
        i -= 1

# Main function
def main():
    i = 0
    # Continuously read the size of the field until a zero is encountered
    while(~scanf("%d", &i), i):
        # Initialize the field based on the size provided
        init(i)
        # Read the number of moves to be made
        scanf("%d", &i)
        # Execute the moves
        move(i)
        # Print "Yes" if all fields are cleared, otherwise print "No"
        printf("%s\n", i? "No" : "Yes")

# Start the execution if it's the main script
if __name__ == "__main__":
    main()

