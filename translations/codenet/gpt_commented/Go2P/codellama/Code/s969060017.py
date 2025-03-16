
# Declare two integer variables a and b
a = int(input())
b = int(input())

# Check if b is divisible by a
if b % a == 0:
    # If b is divisible by a, print the sum of a and b
    print(a + b)
else:
    # If b is not divisible by a, print the difference between b and a
    print(b - a)

