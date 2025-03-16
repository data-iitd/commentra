MAX = 21

# Function prototypes
def init(i):
    global x, y, fld
    # Set the starting position of the robot
    x = y = 10
    # Clear the grid
    fld = [[0] * MAX for _ in range(MAX)]
    # Read the positions of items and mark them in the grid
    for _ in range(i):
        a, b = map(int, input().split())
        fld[b][a] = 1

def move(i):
    global n
    # Read each movement and execute it
    for _ in range(i):
        buf, a = input().split()
        a = int(a)
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
            if d % 2:
                x += -1 if d == 3 else 1
            else:
                y += -1 if d == 0 else 1
            
            # Check if the robot collects an item
            if fld[y][x]:
                fld[y][x] = 0
                n -= 1

# Global variables
n, x, y, fld = 0, 0, 0, []

if __name__ == "__main__":
    while True:
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
        print("No" if n else "Yes")
        
# <END-OF-CODE>
