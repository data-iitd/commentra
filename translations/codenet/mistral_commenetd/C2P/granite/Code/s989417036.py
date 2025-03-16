
# Declare variables
a, b, c, d, e, i = 0, 0, 0, 0, 0, 0, 0

# Initialize variables with input()
a, b, c = map(int, input().split())

# Check if b is less than or equal to c
if b <= c:
  # If so, print "NO" and exit
  print("NO")
  exit(0)

# Else, continue with the following logic
else:
  # Initialize d with a and e with the remainder of a divided by b
  d = a
  e = d % b

  # Iterate through b using a for loop
  for i in range(b):
    # Update d by calculating the remainder of d divided by b
    d = d % b

    # If d is equal to c, print "YES" and exit
    if d == c:
      print("YES")
      exit(0)

    # If d is already equal to c and i is not the first iteration, print "NO" and exit
    elif i!= 0 and d == c:
      print("NO")
      exit(0)

    # Update d by adding a
    d += a

# If the loop finishes without finding c, print "NO" and exit
print("NO")

