# Read the number of rows/columns for the square matrix
n = int(input())

# Initialize an empty list to store the input strings
s = []

# Read n strings from input and append them to the list s
for i in range(n):
    k = input()
    s.append(k)

# Initialize a flag variable (not used in this code)
flag = 0

# Initialize lists to store diagonal elements
d1 = []  # Primary diagonal
d2 = []  # Secondary diagonal

# Initialize a set to store non-diagonal elements
rem = set()

# Iterate through the matrix to populate the diagonals and non-diagonal elements
for i in range(n):
    for j in range(n):
        # If it's a primary diagonal element
        if (i == j):
            d1.append(s[i][j])
        # If it's a secondary diagonal element
        if (i == n - j - 1):
            d2.append(s[i][j])
        # If it's a non-diagonal element
        if (i != j and i != n - j - 1):
            rem.add(s[i][j])

# Check conditions to determine the output
# If the number of unique non-diagonal elements is not 1
if (len(rem) != 1):
    print('NO')
# If the primary and secondary diagonals are not equal
elif (d1 != d2):
    print('NO')
# If the primary diagonal does not consist of the same element
elif (len(set(d1)) != 1):
    print('NO')
# If the unique element in the primary diagonal is also in the non-diagonal set
elif (set(d1) == rem):
    print('NO')
# If all conditions are satisfied, print 'YES'
else:
    print('YES')
