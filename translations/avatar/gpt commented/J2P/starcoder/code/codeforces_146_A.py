import sys

# Reading the length of the number and the number itself as a string
n = int(sys.stdin.readline())
str = sys.stdin.readline()

# Converting the string to a character array for easier manipulation
l = list(str)

# Initializing variables to hold the sum of the first half and the second half of the digits
x = 0
y = 0
t = 0 # Variable to check if there are any digits other than '4' or '7'

# Checking if all characters in the string are either '4' or '7'
for i in range(n):
    if l[i]!= '4' and l[i]!= '7':
        t = 1 # Set t to 1 if a character is found that is not '4' or '7'

# If t is set, print "NO" indicating the number is not lucky
if t == 1:
    print("NO")
else:
    # Calculate the sum of the first half of the digits
    for i in range(n // 2):
        x = x + int(l[i])
    # Calculate the sum of the second half of the digits
    for i in range(n - 1, n // 2 - 1, -1):
        y = y + int(l[i])
    # Compare the two sums and print "YES" if they are equal, otherwise print "NO"
    if x == y:
        print("YES")
    else:
        print("NO")

# 