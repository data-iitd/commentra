
# Read five integer values from user input
a, b, c, x, y = map(int, input().split())

# Double the value of c
c *= 2

# Check if the sum of a and b is less than or equal to c
if a + b <= c:
    # If true, calculate and print the total cost using x and y
    print(a * x + b * y)
else:
    # If the sum of a and b is greater than c, check the value of x against y
    if x <= y:
        # If x is less than or equal to y, check if b is less than or equal to c
        if b <= c:
            # If true, calculate and print the total cost considering c and the remaining b
            print(c * x + (y - x) * b)
        else:
            # If b is greater than c, print the total cost using c and y
            print(c * y)
    else:
        # If x is greater than y, check if a is less than or equal to c
        if a <= c:
            # If true, calculate and print the total cost considering c and the remaining a
            print(c * y + (x - y) * a)
        else:
            # If a is greater than c, print the total cost using c and x
            print(c * x)

# End of code
