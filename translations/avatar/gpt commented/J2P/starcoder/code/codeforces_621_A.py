
# Importing necessary classes from the sys and collections packages
import sys
from collections import *

# Reading the number of elements to be processed
n = int(sys.stdin.readline())

# Initializing a list to store the input numbers
list = []

# Reading n long integers from input and adding them to the list
for i in range(n):
    list.append(int(sys.stdin.readline()))

# Initializing a list to store odd numbers and a variable to hold the sum
odd = []
sum = 0

# Iterating through the list to separate even and odd numbers
for i in list:
    if i % 2 == 0:
        # If the number is even, add it to the sum
        sum += i
    else:
        # If the number is odd, add it to the odd list
        odd.append(i)

# Sorting the list of odd numbers in ascending order
odd.sort()

# Adding all odd numbers to the sum
for i in odd:
    sum += i

# If the count of odd numbers is odd, subtract the smallest odd number from the sum
if len(odd) % 2!= 0:
    sum -= odd[0]

# Printing the final calculated sum
print(sum)

# 