
import math
import sys

# Reading the first number from the standard input stream and storing it in the variable x
x = int(sys.stdin.readline().strip())

# Creating an empty ArrayList to store digits
list = []

# The following while loop runs as long as the number x is greater than zero
while x > 0:
    # Storing the last digit of the number x in the variable r
    r = x % 10

    # The following if statement checks if the difference between 9 and the last digit r is less than r itself
    if 9 - r < r:
        # The following nested if statement checks if both x and the difference between 9 and the last digit r are zero
        if x / 10 == 0 and 9 - r == 0:
            # Adding the last digit r to the ArrayList if it is the only digit in the number x or if it is the last digit of a number greater than zero and the difference between 9 and the last digit is zero
            list.append(r)
        else:
            # Adding the number 9 minus the last digit r to the ArrayList if the difference between 9 and the last digit is greater than the last digit itself
            list.append(9 - r)
    else:
        # Adding the last digit r to the ArrayList if the difference between 9 and the last digit is less than or equal to the last digit itself
        list.append(r)

    x = x // 10

# Initializing the variable pow to 0 to be used as the power of 10 in the calculation of the new number
pow = 0

# Initializing the variable newNumber to 0 to store the final number after calculating the digits in reverse order
newNumber = 0

# The following for loop runs through each digit in the ArrayList and calculates the new number by adding the digit multiplied by the power of 10 to the variable newNumber
for i in range(len(list)):
    newNumber += list[i] * (10 ** pow)
    pow += 1

# Printing the final number to the standard output stream
print(newNumber)

