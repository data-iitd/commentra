from math import prod  # Import the 'prod' function from the math module to calculate the product of a list of numbers

input()  # Read an input line (not used in further calculations)

a = input()  # Read a string input from the user

# Check if the string contains any '1's
# If there are no '1's, print 0
# Otherwise, calculate the product of counts of '0's between '1's
print(0 if a.count("1") == 0 else 
      prod([i.count("0") + 1 for i in a.strip("0 ").split('1')])) 
      # Split the input string by '1's, count '0's in each segment, add 1 to each count,
      # and calculate the product of these counts
)
