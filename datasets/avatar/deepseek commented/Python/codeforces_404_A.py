
n = int(input())  # Take the size of the square matrix as input
s = []  # Initialize an empty list to store the matrix elements

# Take n inputs, each representing a row of the matrix, and append these to the list s
for i in range(n):
    k = input()
    s.append(k)

flag = 0  # Initialize flag to 0
d1 = []  # Initialize an empty list to store the diagonal elements from top-left to bottom-right
d2 = []  # Initialize an empty list to store the diagonal elements from top-right to bottom-left
rem = set()  # Initialize a set to store the non-diagonal elements

# Iterate through the matrix to populate d1, d2, and rem with the appropriate elements
for i in range(n):
    for j in range(n):
        if (i == j):  # Check if the element is on the diagonal from top-left to bottom-right
            d1.append(s[i][j])
        if (i == n - j - 1):  # Check if the element is on the diagonal from top-right to bottom-left
            d2.append(s[i][j])
        if (i != j and i != n - j - 1):  # Check if the element is not on the diagonals
            rem.add(s[i][j])

# Check the conditions and print 'NO' or 'YES' based on the conditions
if (len(rem) != 1):
    print('NO')  # Print 'NO' if the set of non-diagonal elements does not have a single unique element
elif (d1 != d2):
    print('NO')  # Print 'NO' if the two diagonals are not equal
elif (len(set(d1)) != 1):
    print('NO')  # Print 'NO' if the diagonal elements do not all have the same value
elif (set(d1) == rem):
    print('NO')  # Print 'NO' if the set of diagonal elements is equal to the set of non-diagonal elements
else:
    print('YES')  # Print 'YES' if all conditions are met

