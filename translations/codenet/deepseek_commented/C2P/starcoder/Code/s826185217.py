# Step 1: Include the standard input/output library to use print and input functions.

a, b, c, d = input().split() # Step 2: Declare four integer variables a, b, c, and d to store the input values.

a = int(a) # Step 3: Convert the input values to integers.
b = int(b)
c = int(c)
d = int(d)

if a + b > c + d: # Step 4: Compare the sum of a and b with the sum of c and d.
	print("Left") # Step 5: If the sum of a and b is greater than the sum of c and d, print "Left".
elif a + b < c + d: # Step 6: If the sum of a and b is less than the sum of c and d, print "Right".
	print("Right")
else: # Step 7: If the sums are equal, print "Balanced".
	print("Balanced")

# Step 8: End the program with comment "