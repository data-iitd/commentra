# Declare two integer variables to hold user input
a = int(input())
b = int(input())

# Check if the product of a and b is even
if((a * b) % 2 == 0):
  # If the product is even, print "Even"
  print("Even")
else:
  # If the product is odd, print "Odd"
  print("Odd")

# Return 0 to indicate successful completion of the program
return 0

