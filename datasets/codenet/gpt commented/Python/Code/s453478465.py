# Read two integers from input and assign them to variables a and b
a, b = map(int, input().split())

# Check if both a and b are less than or equal to 8
if a <= 8 and b <= 8:
    # If the condition is met, print a positive message
    print("Yay!")
else:
    # If the condition is not met, print a negative message
    print(":(")
