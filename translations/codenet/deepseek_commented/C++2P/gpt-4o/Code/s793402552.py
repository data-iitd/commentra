import math

# This section of the code reads two integers, a and b, from the standard input.
a, b = map(int, input().split())

# This section converts the integer b to a string to determine its length.
bstr = str(b)

# This section calculates a new number, num, by multiplying a with 10 raised to the power of the length of b (in string form), and then adding b to it.
num = a * (10 ** len(bstr)) + b

# Check for perfect square root
for i in range(1, 100101):
    if i * i == num:
        break

# This section checks if the loop has finished due to finding a perfect square root of num. If not, it prints "No". Otherwise, it prints "Yes".
if i > 100100:
    print("No")
else:
    print("Yes")

# <END-OF-CODE>
