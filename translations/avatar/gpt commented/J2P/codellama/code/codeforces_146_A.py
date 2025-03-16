import math
import sys

# Reading the length of the number and the number itself as a string
n = int(input())
str = input()

# Converting the string to a character array for easier manipulation
l = list(str)

# Checking if all characters in the string are either '4' or '7'
t = 0
for i in range(n):
    if l[i] != '4' and l[i] != '7':
        t = 1

# If t is set, print "NO" indicating the number is not lucky
if t == 1:
    print("NO")
else:
    # Calculate the sum of the first half of the digits
    x = 0
    for i in range(n // 2):
        x += int(l[i])

    # Calculate the sum of the second half of the digits
    y = 0
    for i in range(n - 1, n // 2 - 1, -1):
        y += int(l[i])

    # Compare the two sums and print "YES" if they are equal, otherwise print "NO"
    if x == y:
        print("YES")
    else:
        print("NO")

