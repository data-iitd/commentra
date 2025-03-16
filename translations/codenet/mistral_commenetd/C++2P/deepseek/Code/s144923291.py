import sys

# Read height and width from standard input
h, w = map(int, input().split())

# Initialize the pattern to match
s = "snuke"

# Iterate through each row of the grid
for i in range(h):
    # Read a row of characters from standard input
    t = input().strip()
    
    # Check if the current row contains the pattern 'snuke'
    if s in t:
        # Find the index of the pattern in the row
        index = t.index(s)
        
        # Calculate the column index of the matching character
        column_index = ord('A') + index
        
        # Print the character and its row number to standard output
        print(chr(column_index) + str(i + 1))
        
        # Exit the program if a match is found
        sys.exit()

# If no match is found, return 0
