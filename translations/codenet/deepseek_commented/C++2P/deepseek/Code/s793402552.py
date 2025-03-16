import sys

# This section of the code reads two integers, a and b, from the standard input.
a, b = map(int, sys.stdin.readline().split())

# This section converts the integer b to a string to determine its length.
bstr = str(b)

# This section calculates a new number, num, by multiplying a with 10 raised to the power of the length of b (in string form), and then adding b to it.
num = a * (10 ** len(bstr)) + b

i = 1
while i * i <= num:
    if i * i == num:
        print("Yes")
        break
    i += 1
else:
    print("No")
