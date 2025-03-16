from sys import stdin

# Define a lambda function to read a line of input and convert it to a list of integers
il = lambda func=int: list(map(func, stdin.readline().rstrip().split()))

# Define a lambda function to read 'n' lines of input and evaluate them as integers
ils = lambda n, s="int(input())": [eval(s) for _ in range(n)]

# Function to compute the greatest common divisor (GCD) of two numbers
def gcd(a, b):
    # Ensure 'a' is greater than or equal to 'b'
    if a < b: return gcd(b, a)
    # Base case: if 'b' is zero, return 'a' as the GCD
    if b == 0: return a
    # Recursive case: call gcd with 'b' and the remainder of 'a' divided by 'b'
    return gcd(b, a % b)

# Function to compute the least common multiple (LCM) of two numbers
def lcm(a, b):
    # LCM is calculated using the formula: (a * b) / GCD(a, b)
    return a * b // gcd(a, b)

# Read two integers 'n' and 'm' from input
n, m = il()

# Read two strings 's' and 't' from input
s = input()
t = input()

# Calculate the GCD of 'n' and 'm'
aa = gcd(n, m)

# Calculate the LCM of 'n' and 'm'
bb = lcm(n, m)

# Calculate the ratio of GCD to LCM
cc = aa // bb

# Loop through the range of GCD to compare characters in the two strings
for i in range(aa):
    # Check if the characters at the calculated indices are equal
    if s[n // aa * i] != t[m // aa * i]:
        # If they are not equal, print -1 and exit
        print(-1)
        exit()

# If all characters match, print the LCM
print(bb)
