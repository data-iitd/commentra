# We start by defining two variables 'a' and 'b' and assigning them the values obtained from user input.
a, b = map(int, input().split())

# We use the 'map()' function to convert the user input string into integers and assign them to the variables 'a' and 'b'.

# The next block of code checks the condition 'if a <= b:'.
if a <= b:
    # If the condition is true, we print the value of 'a'.
    print(a)
else:
    # If the condition is false, we print the value of 'a-1'.
    print(a-1)
