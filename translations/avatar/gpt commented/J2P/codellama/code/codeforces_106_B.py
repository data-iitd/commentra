import sys 

# Read the number of entries
n = int(sys.stdin.readline()) 

# Initialize a 2D array to store the input values
vec = [[0 for x in range(4)] for y in range(n)] 

# Read input values into the 2D array
for i in range(n): 
    vec[i][0] = int(sys.stdin.readline()) # Read first value
    vec[i][1] = int(sys.stdin.readline()) # Read second value
    vec[i][2] = int(sys.stdin.readline()) # Read third value
    vec[i][3] = int(sys.stdin.readline()) # Read price

# Initialize variables to track the best option
ans = 500 # Default answer if no valid option is found
ansprice = 20000 # Set a high initial price

# Iterate through each entry to find the best option
for i in range(n): 
    fl = 1 # Flag to check if the current entry is not dominated
    
    # Check if the current entry is dominated by any other entry
    for j in range(n): 
        if vec[i][0] < vec[j][0] and vec[i][1] < vec[j][1] and vec[i][2] < vec[j][2]: 
            fl = 0 # Set flag to 0 if dominated
    
    # If the current entry is not dominated, check its price
    if fl == 1: 
        if vec[i][3] < ansprice: 
            ansprice = vec[i][3] # Update the best price found
            ans = i + 1 # Update the answer with the current index (1-based)

# Output the result
print(ans) 

# 