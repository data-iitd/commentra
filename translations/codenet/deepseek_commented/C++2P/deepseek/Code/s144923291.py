import sys

# Read the dimensions of the grid
h, w = map(int, input().split())

# Define the pattern to search for
s = "snuke"

# Loop over each row
for i in range(h):
    # Loop over each column
    for j in range(w):
        # Read a character array
        t = input().strip()
        # Compare the character array with the pattern
        if t == s:
            # Calculate the column letter
            c = chr(ord('A') + j)
            # Output the position in the grid
            print(f"{c}{i + 1}")
            # Terminate the program
            sys.exit()

# End-of-code
