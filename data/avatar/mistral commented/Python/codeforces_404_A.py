# Take the number of rows as input
n = int(input())

# Initialize an empty list 's' to store the rows
s = []

# Read each row and append it to the list 's'
for i in range(n):
    # Read a row as a string and convert it to a list
    k = input().split()
    # Append the list to the list 's'
    s.append(k)

# Initialize flags and empty lists 'd1' and 'd2'
flag = 0
d1 = []
d2 = []

# Iterate through each element in the list 's'
for i in range(n):
    # Iterate through each element in the same row and in the reverse order
    for j in range(n):
        # If the current indices are same, append the element to 'd1'
        if i == j:
            d1.append(s[i][j])
        # If the current indices are reverse of each other, append the element to 'd2'
        if i == n - j:
            d2.append(s[i][j])
        # If the current indices are not same and not reverse, add the element to 'rem' set
        if i != j and i != n - j:
            rem.add(s[i][j])

# Check if the size of 'rem' set is not equal to 1
if len(rem) != 1:
    # If the condition is true, print 'NO' and exit
    print('NO')
    exit()

# Check if 'd1' and 'd2' lists are equal
elif d1 != d2:
    # If the condition is true, print 'NO' and exit
    print('NO')
    exit()

# Check if all elements in 'd1' are same
elif len(set(d1)) != 1:
    # If the condition is true, print 'NO' and exit
    print('NO')
    exit()

# Check if all elements in 'd1' are present in 'rem' set
elif set(d1) == rem:
    # If the condition is true, print 'NO' and exit
    print('NO')
    exit()

# If all the above conditions are false, print 'YES'
else:
    print('YES')
