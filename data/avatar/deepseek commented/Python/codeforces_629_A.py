
n = int(input())  # Take the size of the cake as input
cake = []  # Initialize an empty list to store the rows of the cake
happiness = 0  # Initialize the happiness score to 0
chocCount = 0  # Initialize the chocolate count to 0
nfat = 1  # Initialize nfat to 1 for calculating factorial

# Loop through each row of the cake
for i in range(n):
    line = str(input())  # Take each row as input
    cake.append(line)  # Append the row to the cake list
    for j in line:  # Loop through each character in the row
        if j == 'C':  # If the character is a chocolate
            chocCount += 1  # Increment the chocolate count
    if chocCount > 1:  # If there is more than one chocolate in the row
        # Calculate the factorial of chocCount and update happiness
        for i in range(chocCount, chocCount - 2, -1):
            nfat *= i
        happiness += nfat / 2
    nfat = 1  # Reset nfat to 1
    chocCount = 0  # Reset chocCount to 0

posCount = 0  # Initialize posCount to 0 (not used in the code)

# Loop through each column of the cake
for j in range(n):
    chocCount = 0  # Reset the chocolate count for each column
    for i in range(n):
        if cake[i][j] == 'C':  # If the character is a chocolate
            chocCount += 1  # Increment the chocolate count
    if chocCount > 1:  # If there is more than one chocolate in the column
        # Calculate the factorial of chocCount and update happiness
        for i in range(chocCount, chocCount - 2, -1):
            nfat *= i
        happiness += nfat / 2
    nfat = 1  # Reset nfat to 1
    chocCount = 0  # Reset chocCount to 0

print(int(happiness))  # Print the integer value of happiness

