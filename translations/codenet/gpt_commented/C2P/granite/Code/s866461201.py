
# Read the number of heights to be processed
n = int(input())

# Initialize frequency distribution array
fd = [0] * 6

# Process each height input
for _ in range(n):
    # Read the height from input
    height = float(input())
    
    # Increment the appropriate frequency distribution index based on height ranges
    if height >= 185.0:
        fd[5] += 1
    elif height >= 180.0:
        fd[4] += 1
    elif height >= 175.0:
        fd[3] += 1
    elif height >= 170.0:
        fd[2] += 1
    elif height >= 165.0:
        fd[1] += 1
    else:
        fd[0] += 1

# Output the frequency distribution as a histogram
for i in range(6):
    print(f"{i + 1}:", end="")  # Print the category number (1 to 6)
    
    # Print asterisks corresponding to the frequency count for each category
    for _ in range(fd[i]):
        print("*", end="")
    
    print()

