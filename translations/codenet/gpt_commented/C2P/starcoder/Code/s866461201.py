# <START-OF-CODE>

# Declare variables
n, fd = 0, [0] * 6 # n: number of heights, fd: frequency distribution array
height = 0.0 # height: variable to store individual height input

# Read the number of heights to be processed
n = int(input())

# Process each height input
while n > 0:
    # Read the height from input
    height = float(input())
    
    # Increment the appropriate frequency distribution index based on height ranges
    if height >= 185.0: 
        fd[5] += 1 # Count for height >= 185.0
    elif height >= 180.0: 
        fd[4] += 1 # Count for height >= 180.0 and < 185.0
    elif height >= 175.0: 
        fd[3] += 1 # Count for height >= 175.0 and < 180.0
    elif height >= 170.0: 
        fd[2] += 1 # Count for height >= 170.0 and < 175.0
    elif height >= 165.0: 
        fd[1] += 1 # Count for height >= 165.0 and < 170.0
    else: 
        fd[0] += 1 # Count for height < 165.0
    
    n -= 1

# Output the frequency distribution as a histogram
for i in range(6):
    print(i + 1, ":", end = "") # Print the category number (1 to 6)
    
    # Print asterisks corresponding to the frequency count for each category
    for j in range(fd[i]):
        print("*", end = "")
    
    print("") # Move to the next line after printing the asterisks

# 