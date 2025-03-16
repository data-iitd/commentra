# Declare variables
n = int(input("Enter the number of heights: "))  # Read the number of heights to be processed
fd = [0] * 6  # Frequency distribution array initialized to zero

# Process each height input
for _ in range(n):
    height = float(input("Enter height: "))  # Read the height from input
    
    # Increment the appropriate frequency distribution index based on height ranges
    if height >= 185.0:
        fd[5] += 1  # Count for height >= 185.0
    elif height >= 180.0:
        fd[4] += 1  # Count for height >= 180.0 and < 185.0
    elif height >= 175.0:
        fd[3] += 1  # Count for height >= 175.0 and < 180.0
    elif height >= 170.0:
        fd[2] += 1  # Count for height >= 170.0 and < 175.0
    elif height >= 165.0:
        fd[1] += 1  # Count for height >= 165.0 and < 170.0
    else:
        fd[0] += 1  # Count for height < 165.0

# Output the frequency distribution as a histogram
for i in range(6):
    print(f"{i + 1}:", end='')  # Print the category number (1 to 6)
    
    # Print asterisks corresponding to the frequency count for each category
    print('*' * fd[i])  # Print asterisks in one go

# Indicate successful completion of the program
# <END-OF-CODE>
