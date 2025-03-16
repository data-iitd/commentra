# Declare two integer variables to hold the input values
a, b = map(int, input().split())

# If the first input value is 1, set it to 14
if a == 1:
    a = 14

# If the second input value is 1, set it to 14
if b == 1:
    b = 14

# Compare the two values and print the result
if a < b:
    # If 'a' is less than 'b', print "Bob"
    print("Bob")
elif a > b:
    # If 'a' is greater than 'b', print "Alice"
    print("Alice")
else:
    # If 'a' is equal to 'b', print "Draw"
    print("Draw")

# <END-OF-CODE>
