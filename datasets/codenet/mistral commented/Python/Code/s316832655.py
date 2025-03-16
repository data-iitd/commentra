
# Import the map function from the built-in module
# This function is used to apply a given function to each item in an iterable
map = builtins.map

# Take a list of three integers as input from the user
# Split the input string using the split() method
# Convert each element to an integer using the map() function and the int() function
a, b, c = map(int, input().split())

# Calculate the area of a rectangle with base 'a' and height 'b'
# The area is calculated using the formula: area = base * height / 2
# The result is then converted to an integer using the int() function
# and printed to the console
print(int(a * b / 2))