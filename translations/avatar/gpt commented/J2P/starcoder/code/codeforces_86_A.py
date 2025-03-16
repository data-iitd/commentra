import sys

# Method to calculate the number of digits in a given number
def power(a):
    res = 0
    # Count the number of digits by dividing the number by 10 until it becomes 0
    while a > 0:
        res += 1
        a = a / 10
    return res

# Method to calculate the product of a number and the difference between the largest number with the same number of digits and the number itself
def mult(a):
    pow = power(a) # Get the number of digits in 'a'
    max = 0
    # Create the largest number with the same number of digits as 'a' (all 9s)
    for j in range(pow):
        max = max * 10 + 9
    # Return the product of 'a' and the difference between the largest number and 'a'
    return a * (max - a)

# Precompute maximum products for numbers with up to 10 digits
maxxes = [0] * 10
temp = 0
for i in range(10):
    temp = temp * 10 + 9 # Create the largest number with i+1 digits (all 9s)
    maxxes[i] = temp / 2 * (temp - temp / 2) # Calculate the maximum product for this digit length

# Read the lower bound of the range
l = int(sys.stdin.readline())
# Read the upper bound of the range
r = int(sys.stdin.readline())
# Variable to store the maximum result
res = 0
temp = 0

# Calculate the maximum product for the lower bound 'l'
res = max(mult(l), res)
# Calculate the maximum product for the upper bound 'r'
res = max(mult(r), res)

# Check for numbers formed by all 9s and see if they lie within the range [l, r]
for i in range(10):
    temp = temp * 10 + 9 # Create the largest number with i+1 digits (all 9s)
    # If the half of this number is within the range, consider its maximum product
    if l <= temp / 2 and temp / 2 <= r:
        res = max(maxxes[i], res)

# Output the maximum product found
print(res)

# 