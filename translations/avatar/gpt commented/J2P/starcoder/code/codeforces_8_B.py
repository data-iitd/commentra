# Create a Scanner object to read input from the user
scan = Scanner(sys.stdin)

# Initialize variables for coordinates and control flags
i, j, x = 0, 0, 0, 0, 0, 0
flag = True

# Declare variables for input string and character array
s = ""
ch = [0] * 100

# Create a 2D array to store coordinates
co = [[0] * 101 for i in range(2)]

# Read the input string from the user
s = scan.next()

# Convert the input string to a character array
for i in range(len(s)):
    ch[i] = s[i]

# Store the initial coordinates (0, 0) in the coordinates array
co[0][0] = x
co[1][0] = y

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
    # Store the updated coordinates in the array
    co[0][i + 1] = x
    co[1][i + 1] = y

# Check for any bugs in the movement path
for i in range(len(s) - 3):
    for j in range(i + 3, len(s)):
        # Calculate the differences in x and y coordinates
        dx = co[0][i] - co[0][j]
        dy = co[1][i] - co[1][j]
        
        # Make differences positive
        if dx < 0: dx *= (-1)
        if dy < 0: dy *= (-1)
        
        # Check if the two points are too close to each other
        if (dx <= 1 and dy == 0) or (dy <= 1 and dx == 0):
            flag = False # Set flag to false if a bug is found
            break # Exit the inner loop
    if not flag: break # Exit the outer loop if a bug is found

# Output the result based on the flag status
if flag: 
    print("OK") # No bugs found
else: 
    print("BUG") # Bugs found in the movement path

# 