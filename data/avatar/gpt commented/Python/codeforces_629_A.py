# Read the number of lines (n) from user input
n = int(input())

# Initialize a list to store the cake representation and variables for happiness and chocolate count
cake = []
happiness = 0
chocCount = 0
nfat = 1

# Process each line of cake input
for i in range(n):
    # Read a line of cake representation
    line = str(input())
    # Append the line to the cake list
    cake.append(line)
    
    # Count the number of chocolates ('C') in the current line
    for j in line:
        if (j == 'C'):
            chocCount += 1
            
    # If there are more than one chocolate, calculate the happiness contribution
    if (chocCount > 1):
        # Calculate the factorial of (chocCount - 1) and (chocCount - 2)
        for i in range(chocCount, chocCount - 2, -1):
            nfat *= i
        # Update happiness based on the calculated factorial
        happiness += nfat / 2
        
    # Reset variables for the next line
    nfat = 1
    chocCount = 0

# Initialize a counter for vertical chocolate counting
posCount = 0

# Count chocolates in each column of the cake
for j in range(n):
    for i in range(n):
        # Count the number of chocolates ('C') in the current column
        if (cake[i][j] == 'C'):
            chocCount += 1
            
    # If there are more than one chocolate in the column, calculate the happiness contribution
    if (chocCount > 1):
        # Calculate the factorial of (chocCount - 1) and (chocCount - 2)
        for i in range(chocCount, chocCount - 2, -1):
            nfat *= i
        # Update happiness based on the calculated factorial
        happiness += nfat / 2
        
    # Reset variables for the next column
    nfat = 1
    chocCount = 0

# Print the total happiness as an integer
print(int(happiness))
