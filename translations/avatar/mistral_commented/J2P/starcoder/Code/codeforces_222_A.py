
# Importing the Python's standard input library to read input from the standard input
import sys

# Reading the first integer from the standard input
n = int(input())

# Reading the second integer from the standard input
k = int(input())

# Initializing the variables l and c with values 0 and 1 respectively
l = 0
c = 1

# Starting a for loop that iterates n times
for i in range(n):
    # Reading the next integer from the standard input and assigning it to variable a
    a = int(input())

    # If the current integer is equal to the previous one, increment the counter c by 1
    if a == l:
        c += 1
    # Otherwise, reset the counter c to 1
    else:
        c = 1

    # Assigning the current integer to the previous integer variable l
    l = a

# Checking if the sum of counter c and integer k is greater than the total number of integers n
if c + k > n:
    # If true, print the difference between n and c
    print(n - c)
# If false, print -1
else:
    print(-1)

# 