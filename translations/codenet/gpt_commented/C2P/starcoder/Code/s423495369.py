# <START-OF-CODE>

# Declare three integer variables A, B, and C
A = 0
B = 0
C = 0

# Read three integers from user input and store them in A, B, and C
A = int(input())
B = int(input())
C = int(input())

# Check if C is between A and B (A < C < B)
if (A < C and C < B):
  # If true, print "Yes"
  print ("Yes")
# Check if C is between B and A (A > C > B)
elif (A > C and C > B):
  # If true, print "Yes"
  print ("Yes")
# If neither condition is met, print "No"
else:
  print ("No")

# 