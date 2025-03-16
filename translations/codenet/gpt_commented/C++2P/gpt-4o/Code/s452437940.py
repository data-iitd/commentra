# Declare variables to hold the input values
a, b, x = map(int, input().split())

# Calculate the number of multiples of x in the range [a, b]
s = (b // x - a // x)

# If 'a' is a multiple of 'x', include it in the count
if a % x == 0:
    s += 1

# Print the result: the total count of multiples of x in the range
print(s)

# <END-OF-CODE>
