# Read the height (h) and width (w) of the grid from input
h, w = map(int, input().split())

# Initialize an empty list to store the grid
l = []

# Read each row of the grid and append it to the list
for _ in range(h):
    a = list(map(str, input()))  # Read a row as a list of characters
    l.append(a)  # Append the row to the grid

# Initialize a variable to track the rightmost position of '#' seen so far
tmp = 0

# Iterate through each cell in the grid
for i in range(h):
    for j in range(w):
        # Check if the current cell contains a '#'
        if l[i][j] == "#":
            # If the current column index is less than the last seen '#', it's impossible
            if j < tmp:
                print("Impossible")  # Output "Impossible" if the condition is met
                exit()  # Exit the program
            else:
                # Update the rightmost position of '#' seen so far
                tmp = j

# If the loop completes without finding an impossible condition, output "Possible"
print("Possible")
