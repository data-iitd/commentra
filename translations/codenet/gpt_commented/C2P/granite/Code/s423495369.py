
# Read three integers from user input and store them in A, B, and C
A, B, C = map(int, input().split())

# Check if C is between A and B (A < C < B)
if A < C < B:
  # If true, print "Yes"
  print("Yes")
# Check if C is between B and A (A > C > B)
elif A > C > B:
  # If true, print "Yes"
  print("Yes")
# If neither condition is met, print "No"
else:
  print("No")

