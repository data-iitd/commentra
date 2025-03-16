
# <START-OF-CODE>

# Read the first integer n, which represents the number of elements
n = int(input())

# Read the second integer m, which represents the upper limit
m = int(input())

# Initialize an array to hold the processed values
a = []

# Read n integers from input, divide each by 2, and store in array a
for i in range(n):
    a.append(int(input()) / 2)

# Initialize the least common denominator (lcd) to 1
lcd = 1

# Calculate the least common multiple (lcd) of the array elements
for i in range(n):
    gcd = getGCD(lcd, a[i]) # Get the greatest common divisor (gcd) of lcd and current element
    lcd = lcd * a[i] / gcd # Update lcd using the formula: lcd = (lcd * a[i]) / gcd

    # If lcd exceeds m, print 0 and exit
    if lcd > m:
        print(0)
        exit()

# Check if the condition for each element in the array is satisfied
for i in range(n):
    # If lcd divided by the current element is even, print 0 and exit
    if (lcd / a[i]) % 2 == 0:
        print(0)
        exit()

# Calculate and print the final result based on the value of m and lcd
print((m / lcd + 1) / 2)

# Method to compute the greatest common divisor (gcd) using recursion
def getGCD(a, b):
    if b == 0:
        return a
    else:
        return getGCD(b, a % b) # Recursive call to find gcd

# 