
# Declare three integer variables 'a', 'b', and 'c'
a, b, c = 0, 0, 0

# Read three integers from the standard input using scanf()
a, b, c = map(int, input().split())

# Check if the condition 'b > a * c' is true
if b > a * c:
    # If the condition is true, print the value of 'c'
    print(c)
else:
    # If the condition is false, calculate the integer division of 'b' by 'a'
    # and print the result
    print(b // a)

# 