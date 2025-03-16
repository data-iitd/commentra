
# Importing the required libraries
import sys
import math

# Reading the first line of input and splitting it into an array of strings
sa = sys.stdin.readline().split(" ")

# Parsing the first element of the array as an integer representing the size of the array
n = int(sa[0])

# Reading the second line of input and splitting it into an array of strings
sa = sys.stdin.readline().split(" ")

# Creating an integer array of size n
c = [0] * n

# Initializing the array c with the input values
for i in range(n):
    c[i] = int(sa[i])

# Defining a constant value for modulus
mod = 1000000007

# Checking if the size of the array is 1
if n == 1:
    # Printing the result for the case when the size of the array is 1
    print(c[0] * 2 % mod)
    sys.exit() # Exiting the program after printing the result

# Sorting the array c in parallel using Arrays.parallelSort() method
c.sort()

# Calculating the values of b and a
b = power(2, n)
a = power(2, n - 2)

# Initializing the variable ans to 0
ans = 0

# Iterating through the array from index 2 to n+1
for i in range(2, n + 1):
    # Calculating the value of val using the current index i and the previously calculated value a
    val = a * i % mod

    # Multiplying the value of val with the current element of the array c[n+1-i]
    val *= c[n + 1 - i]

    # Taking the modulus of the product to ensure the result is within the range of modulus
    val %= mod

    # Adding the value of val to the variable ans
    ans += val

    # Taking the modulus of the sum of ans and val to ensure the result is within the range of modulus
    ans %= mod

# Multiplying the value of ans with the value of b
ans *= b

# Taking the modulus of the product to ensure the result is within the range of modulus
ans %= mod

# Printing the final result
print(ans)

# 