# Read two integers from input and assign them to variables a and b
a, b = map(int, input().split())

# Check if the two integers are equal
if a == b:
    # If they are equal, print their sum
    print(a + b)
else:
    # If they are not equal, print the maximum of the two integers multiplied by 2, minus 1
    print(max(a, b) * 2 - 1)
