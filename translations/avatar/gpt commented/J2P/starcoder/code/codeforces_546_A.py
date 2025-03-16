import sys; # Importing the sys module for reading input from the console

# Declaring variables to hold input values and a counter
pandu, vundu, urdu, c = 0, 0, 0, 0

# Reading three long integer values from user input
pandu = int(sys.stdin.readline()) # The first input value
vundu = int(sys.stdin.readline()) # The second input value
urdu = int(sys.stdin.readline())  # The third input value

# Calculating the cumulative sum of 'pandu' multiplied by each integer from 1 to 'urdu'
for i in range(1, urdu + 1):
    c += i * pandu # Incrementing 'c' by the product of 'i' and 'pandu'

# Checking if the calculated sum 'c' is less than 'vundu'
if c < vundu:
    print("0") # If true, print "0"
else:
    # If 'c' is greater than or equal to 'vundu', print the difference
    print(c - vundu)

# 