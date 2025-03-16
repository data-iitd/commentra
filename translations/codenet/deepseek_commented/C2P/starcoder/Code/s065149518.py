#include <stdio.h>
#include <string.h>
#define MAX 21

# Function prototypes
def init(i):
    global x, y, fld
    # Set the starting position of the robot
    x = y = 10
    # Clear the grid
    fld = [[0 for i in range(MAX)] for j in range(MAX)]
    # Read the positions of items and mark them in the grid
    while(i):
        a, b = map(int, input().split())
        fld[b][a] = 1
        i -= 1

# Moves the robot according to the given directions and collects items
def move(i):
    global x, y, fld, n
    # Read each movement and execute it
    while(i):
        buf, a = input().split()
        # Determine the direction and convert it to an index
        d = {'N': 0, 'E': 1, 'S': 2, 'W': 3}[buf]
        # Move the robot and collect items
        while(a):
            # Update the robot's position based on the direction
            d % 2 and not d and x -= 1 or x += 1
            d and y -= 1 or y += 1
            # Check if the robot collects an item
            if(fld[y][x]):
                fld[y][x] = 0
                n -= 1
            a -= 1
        i -= 1

# Main program
if __name__ == '__main__':
    # Read the number of items to be collected
    while(True):
        n = int(input())
        if(n == -1):
            break
        # Initialize the grid and the robot's position
        init(n)
        # Read the number of movements
        m = int(input())
        # Perform the movements
        move(m)
        # Output the result
        print("No" if n else "Yes")

# 