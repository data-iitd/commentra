
# Get user input as a string
input_string = input()

# Use map() function to convert input string into a list of integers
numbers = list(map(int, input_string.split()))

# Assign the input numbers to variables a, b, and c
a, b, c = numbers

# Check if the sum of a and b is greater than or equal to c
if a + b >= c:
 # If the condition is true, print "Yes"
 print("Yes")
else:
 # If the condition is false, print "No"
 print("No")