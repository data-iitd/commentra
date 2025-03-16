MAX = 21

# Function prototypes
def init(n):
    global x, y, fld
    # Set the starting position of the robot
    x, y = 10, 10
    # Clear the grid
    fld = [[0] * MAX for _ in range(MAX)]
    # Read the positions of items and mark them in the grid
    for _ in range(n):
        a, b = map(int, input().split())
        fld[b][a] = 1

# Moves the robot according to the given directions and collects items
def move(m):
    for _ in range(m):
        buf = input().strip()
        a = int(input().strip())
        # Determine the direction and convert it to an index
        if buf[0] == 'N':
            d = 0
        elif buf[0] == 'E':
            d = 1
        elif buf[0] == 'S':
            d = 2
        elif buf[0] == 'W':
            d = 3
        # Move the robot and collect items
        for _ in range(a):
            # Update the robot's position based on the direction
            if d % 2 == 1:
                d = 3 if d == 0 else d - 1
            else:
                d = 2 if d == 1 else d - 1
            # Check if the robot collects an item
            if fld[y][x] == 1:
                fld[y][x] = 0
                global n
                n -= 1

# Main function
while True:
    n = int(input().strip())
    if n == 0:
        break
    # Initialize the grid and the robot's position
    init(n)
    # Read the number of movements
    m = int(input().strip())
    # Perform the movements
    move(m)
    # Output the result
    print("Yes" if n == 0 else "No")
