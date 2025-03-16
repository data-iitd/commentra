

import sys

# Read the first two lines from standard input and store them in the variable ds
ds = sys.stdin.readline().strip() + " " + sys.stdin.readline().strip()

# Split the string ds into an array of strings dd using the split function
dd = ds.split(" ")

# Create a new list dn of length len(dd) and initialize each element to 0 using list comprehension
dn = [0] * len(dd)

# Iterate through each element i in the list dd and convert its string value to integer using the int function and store it in the corresponding index of list dn
for i, d in enumerate(dd):
    dn[i] = int(d)

# Initialize sum variable to 0
sum = 0

# Iterate through each index i in the list dn
for i in range(len(dn)):
    # Iterate through each index j greater than i in the list dn
    for j in range(i + 1, len(dn)):
        # Add the product of dn[i] and dn[j] to the sum variable
        sum += dn[i] * dn[j]

# Print the value of sum variable to the standard output using the print function
print(sum)

# End of code