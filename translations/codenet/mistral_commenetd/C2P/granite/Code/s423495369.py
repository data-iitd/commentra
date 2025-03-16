
# Read three integers from the standard input using input function
A, B, C = map(int, input().split())

# Check if A is less than C and C is less than B
if A < C and C < B:
  # If condition is true, print "Yes" to the standard output
  print ("Yes")
# Else if condition checks if A is greater than C and C is greater than B
elif A > C and C > B:
  # If condition is true, print "Yes" to the standard output
  print ("Yes")
# Else condition is executed when neither first nor second condition is true
else:
  # If condition is false, print "No" to the standard output
  print ("No")

# End of code
