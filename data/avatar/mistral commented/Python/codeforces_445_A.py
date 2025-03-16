# Define the number of rows (n) and columns (m) of the grid
n, m = map(int, input().split())

# Initialize an empty list 'l' to store the rows of the grid
l = []

# Iterate through each row 'i' in the grid
for i in range(n):
    # Read the row as a string from user input
    row = input()
    
    # Convert the row string into a list for further processing
    row = list(row)

    # Iterate through each cell 'j' in the row
    for j in range(m):
        
        # If the cell contains a '.', assign it a color based on its position in the grid
        if row[j] == '.':
            if (i + j) % 2:  # If the row index and column index have different parity
                row[j] = 'W'   # Assign the cell the color 'W'
            else:
                row[j] = 'B'   # Assign the cell the color 'B'

    # Append the processed row to the list 'l'
    l.append(row)

# Print each row of the grid
for row in l:
    print("".join(row))