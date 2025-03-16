# Read two integers from user input and assign them to variables a and b
a, b = map(int, input().split())

# Check if the value of a is less than or equal to b
if a <= b:
    # If true, print the value of a
    print(a)
else:
    # If false, print a decremented by 1
    print(a - 1)
