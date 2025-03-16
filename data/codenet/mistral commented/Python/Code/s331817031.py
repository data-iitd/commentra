# Define the height and width of the grid using input function
h, w = map(int, input().split())

# Create an empty list l to store the rows of the grid
l = []

# Iterate through each row and convert input string to list and append it to list l
for _ in range(h):
    a = list(map(str, input()))
    l.append(a)

# Initialize a variable tmp to 0
tmp = 0

# Iterate through each cell in the grid
for i in range(h):
    for j in range(w):
        
        # Check if the current cell contains "#" symbol
        if l[i][j] == "#":
            
            # Check if the column index j is less than the current column index tmp
            if j < tmp:
                
                # If the condition is not met, print "Impossible" and exit the program
                print("Impossible")
                exit()
            
            # If the condition is met, update the value of tmp to j
            else:
                tmp = j

# If we have iterated through all the cells without encountering an invalid condition, print "Possible"
print("Possible")
