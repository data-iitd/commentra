# Read five integers from the standard input
a, b, c, x, y = map(int, input().split())

# Multiply the value of variable c by 2
c *= 2

# Check if the sum of variables a and b is less than or equal to the value of variable c
if a + b <= c:
    print(a * x + b * y)
else:
    # Check if the value of variable x is less than or equal to the value of variable y
    if x <= y:
        # Check if the value of variable b is less than or equal to the value of variable c
        if b <= c:
            print(c * x + (y - x) * b)
        else:
            print(c * y)
    else:
        # Check if the value of variable a is less than or equal to the value of variable c
        if a <= c:
            print(c * y + (x - y) * a)
        else:
            print(c * x)
