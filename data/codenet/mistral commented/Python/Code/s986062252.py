# Import sys module for reading input from standard input
from sys import stdin

# Define a lambda function il to read a list of integers from standard input
il = lambda func=int: list(map(func, stdin.readline().rstrip().split()))

# Define another lambda function il to read a list of integers with a custom input function
ils = lambda n, s="int(input())": [eval(s) for _ in range(n)]

# Define a function gcd to find the greatest common divisor of two numbers
def gcd(a, b):
    # Base case: if a is smaller than b, swap a and b
    if a < b: return gcd(b, a)
    # Base case: if b is zero, return a
    elif b == 0: return a
    # Recursive case: find gcd of b and the remainder of a divided by b
    else: return gcd(b, a % b)

# Define a function lcm to find the least common multiple of two numbers
def lcm(a, b):
    # Return the product of a and b divided by their gcd
    return a * b // gcd(a, b)

# Read the number of test cases and the number of strings to compare from standard input
n, m = il()

# Read the strings s and t from standard input
s = input()
t = input()

# Find the greatest common divisor and the least common multiple of n and m
aa = gcd(n, m)
bb = lcm(n, m)

# Calculate the common quotient of n and m divided by their greatest common divisor
cc = aa // bb

# Iterate through each index i from 0 to the greatest common divisor aa
for i in range(aa):
    # Check if the corresponding characters of strings s and t are equal
    if s[n//aa*i] != t[m//aa*i]:
        # If not, print -1 and exit the program
        print(-1)
        exit()

# If all checks pass, print the least common multiple bb
print(bb)
