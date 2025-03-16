# Declare three integer variables x, a, and b to store input values.
x, a, b = map(int, input().split())

# Use a conditional statement to evaluate the condition b-a and execute the corresponding block of code.
if b - a <= 0:
    print("delicious")
elif b - a <= x:
    print("safe")
else:
    print("dangerous")

# <END-OF-CODE>
