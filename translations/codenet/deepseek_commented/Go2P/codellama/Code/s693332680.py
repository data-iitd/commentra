
# Declare three integer variables x, a, and b to store input values.
x, a, b = input(), input(), input()

# Use a switch statement to evaluate the condition b-a and execute the corresponding block of code.
if b-a <= 0:
    print("delicious")
elif b-a <= x:
    print("safe")
else:
    print("dangerous")

