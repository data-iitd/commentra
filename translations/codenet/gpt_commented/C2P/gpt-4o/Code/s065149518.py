MAX = 21

# Function prototypes
def init(n):
    global x, y, fld
    # Set the starting position of the player
    x = y = 10
    # Clear the field by setting all values to 0
    fld = [[0] * MAX for _ in range(MAX)]
    # Read the positions of obstacles and mark them in the field
    for _ in range(n):
        a, b = map(int, input().split())
        fld[b][a] = 1  # Mark the position as occupied

def move(m):
    global n, x, y, fld
    # Process each move command
    for _ in range(m):
        buf, a = input().split()
        a = int(a)
        # Determine the direction based on the input
        if buf[0] == 'N':
            d = 0  # North
        elif buf[0] == 'E':
            d = 1  # East
        elif buf[0] == 'S':
            d = 2  # South
        elif buf[0] == 'W':
            d = 3  # West
        
        # Move in the specified direction for the given number of steps
        for _ in range(a):
            # Update the position based on the direction
            if d % 2:
                x += 1 if d == 1 else -1
            else:
                y += 1 if d == 0 else -1
            
            # Check if the new position has an obstacle
            if fld[y][x]:
                # Remove the obstacle and decrement the count of remaining obstacles
                fld[y][x] = 0
                n -= 1

# Global variables to hold the state of the game
n, x, y, fld = 0, 0, 0, []

# Continuously read the size of the field until a zero is encountered
while True:
    n = int(input())
    if n == 0:
        break
    # Initialize the field based on the size provided
    init(n)
    # Read the number of moves to be made
    m = int(input())
    # Execute the moves
    move(m)
    # Print "Yes" if all fields are cleared, otherwise print "No"
    print("Yes" if n == 0 else "No")

# <END-OF-CODE>
