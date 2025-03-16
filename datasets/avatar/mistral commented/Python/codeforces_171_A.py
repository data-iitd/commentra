# Importing the sys module and assigning its stdin input to a variable named 'input'
import sys

# Assigning the input to two variables 'a' and 'b' after splitting it by a space
input = sys.stdin.readline
a, b = input().split()

# Finding the maximum length between 'a' and 'b' and padding zeros to the shorter string
x = max(len(a), len(b))
a = a.rjust(x, '0')
b = b.ljust(x, '0')

# Initializing an empty string 's' and a counter 'c' for carrying
s = ''
c = 0

# Iterating through each index 'i' in the range of the length of the padded strings 'x'
for i in range(x):

    # Adding the current digits of 'a' and 'b' at the corresponding positions and carrying if necessary
    d = int(b[i]) + int(a[x-i-1]) + c

    # If the sum is greater than 9, add the carry to the next digit and reset the carry to 0
    if d > 9:
        s += str(d)[1]
        c = 1

    # If the sum is less than or equal to 9, add the digit to the result string 's'
    else:
        s += str(d)

# If there is still a carry left, add it to the result string 's'
if c == 1:
    s += '1'

# Printing the final result after removing the leading zeros (if any)
print(int(s[:-1]))
