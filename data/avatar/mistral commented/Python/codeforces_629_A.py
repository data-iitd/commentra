
n = int(input())  # Read the number of lines in the input
cake = []        # Initialize an empty list to store each line
happiness = 0    # Initialize happiness variable to zero
chocCount = 0    # Initialize chocolate count variable to zero
nfat = 1         # Initialize nFAT variable to 1

for i in range(n):  # Iterate through each line in the input
    line = str(input())  # Read a line and convert it to a string
    cake.append(line)   # Append the line to the list

    for j in line:     # Iterate through each character in the line
        if j == 'C':   # If the character is 'C', increment chocolate count
            chocCount += 1

    if chocCount > 1:  # If there are more than one 'C' in the line
        nfat = 1       # Reset nFAT to 1
        for i in range(chocCount, chocCount-2, -1):  # Calculate nFAT using the chocolate count
            nfat *= i
        happiness += nfat / 2  # Add happiness based on the nFAT value

    chocCount = 0    # Reset chocolate count to zero

posCount = 0       # Initialize position count variable to zero
for j in range(n):  # Iterate through each column in the cake
    for i in range(n):  # Iterate through each line in the cake
        if cake[i][j] == 'C':  # If the character at the position (i,j) is 'C', increment chocolate count
            chocCount += 1

    if chocCount > 1:  # If there are more than one 'C' in the column
        nfat = 1       # Reset nFAT to 1
        for i in range(chocCount, chocCount-2, -1):  # Calculate nFAT using the chocolate count
            nfat *= i
        happiness += nfat / 2  # Add happiness based on the nFAT value

    chocCount = 0    # Reset chocolate count to zero

print(int(happiness))  # Print the final happiness value as an integer.