
# Import the Scanner class from the java.util package
from java.util import Scanner

# Create a Scanner object to read input from the user
scan = Scanner(System.in)

# Initialize variables for coordinates and control flags
i, j, x, y, k, dx, dy = 0, 0, 0, 0, 0, 0, 0
flag = True

# Declare variables for input string and character array
s = ''
ch = []

# Create a 2D array to store coordinates
co = [[0 for i in range(101)] for j in range(2)]

# Read the input string from the user
s = scan.next()

# Convert the input string to a character array
ch = list(s)

# Store the initial coordinates (0, 0) in the coordinates array
co[0][k] = x
co[1][k] = y
k += 1 # Increment the index for the next coordinate

# Process each character in the input string to update coordinates
for i in range(len(s)):
    if ch[i] == 'L': # Move left
        x -= 1
    elif ch[i] == 'R': # Move right
        x += 1
    elif ch[i] == 'U': # Move up
        y += 1
    elif ch[i] == 'D': # Move down
        y -= 1
    co[0][k] = x # Store the updated coordinates in the array
    co[1][k] = y
    k += 1 # Increment the index for the next coordinate

# Check for any bugs in the movement path
for i in range(k - 3):
    for j in range(i + 3, k):
        # Calculate the differences in x and y coordinates
        dx = co[0][i] - co[0][j]
        dy = co[1][i] - co[1][j]
        
        # Make differences positive
        if dx < 0:
            dx *= (-1)
        if dy < 0:
            dy *= (-1)
        
        # Check if the two points are too close to each other
        if (dx <= 1 and dy == 0) or (dy <= 1 and dx == 0):
            flag = False # Set flag to false if a bug is found
            break # Exit the inner loop
    if not flag:
        break # Exit the outer loop if a bug is found

# Output the result based on the flag status
if flag:
    print("OK") # No bugs found
else:
    print("BUG") # Bugs found in the movement path

# END-OF-CODE
