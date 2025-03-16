
# Importing the'sys' module to use the'stdin' object
import sys

# Reading the first integer value from the standard input stream
N = int ( sys.stdin.readline ( ) )

# Initializing the counter variable 'count' to zero
count = 0

# Assigning the value of 'N' to the variable 'temp'
temp = N

# The following while loop calculates the number of digits in the given integer 'N'
while temp > 0 :
    temp //= 10 # Dividing the current value of 'temp' by 10 to get the last digit
    count += 1 # Incrementing the counter variable 'count' by 1

# Initializing the answer variable 'ans' to zero
ans = 0

# The following for loop iterates through each digit of the given integer 'N'
for i in range ( 1, count + 1 ) :
    if i == count : # If the current digit is the last digit
        if i % 2 == 1 : # If the last digit is odd
            ans += ( N - 10 ** ( i - 1 ) + 1 ) # Adding the sum of digits before the last odd digit to the answer
    else : # If the current digit is not the last digit
        if i == 1 : # If the current digit is the first digit
            ans += 9 # Adding the number of digits after the first digit to the answer
        else : # If the current digit is odd
            ans += ( 10 ** i - 10 ** ( i - 1 ) ) # Adding the difference between the 10 raised to the power of the current digit and the 10 raised to the power of the previous digit to the answer

# Printing the final answer to the standard output stream
print ( ans )

# 