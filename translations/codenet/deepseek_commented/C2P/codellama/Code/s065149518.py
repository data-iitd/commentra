#include <stdio.h>
#include <string.h>
#define MAX 21

# Function prototypes
def init(i):
    global n, x, y
    # Set the starting position of the robot
    x = y = 10
    # Clear the grid
    fld = [[0] * MAX for _ in range(MAX)]
    # Read the positions of items and mark them in the grid
    while i:
        a, b = map(int, input().split())
        fld[b][a] = 1
        i -= 1

# Moves the robot according to the given directions and collects items
def move(i):
    global n, x, y
    # Read each movement and execute it
    while i:
        buf, a = input().split()
        # Determine the direction and convert it to an index
        if buf == 'N':
            d = 0
        elif buf == 'E':
            d = 1
        elif buf == 'S':
            d = 2
        elif buf == 'W':
            d = 3
        # Move the robot and collect items
        while a:
            # Update the robot's position based on the direction
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
            # Check if the robot collects an item
            if fld[y][x]:
                fld[y][x] = 0
                n -= 1
            a -= 1
        i -= 1

# Main function
if __name__ == '__main__':
    n = 0
    while True:
        # Read the number of items to be collected
        n = int(input())
        if n == 0:
            break
        # Initialize the grid and the robot's position
        init(n)
        # Read the number of movements
        m = int(input())
        # Perform the movements
        move(m)
        # Output the result
        print('No' if n else 'Yes')

