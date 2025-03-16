#include<stdio.h>

# Declare variables
i = 0
j = 0
x = [0]*10000

# Initialize array x with zeros
for i in range(10000):
	x[i] = 0
	# Comment explaining what the loop does
	# This loop initializes all elements of the array x with zero

# Read the first integer input and store it in the array x at index i
x[i] = int(input())
# Comment explaining what the line does
# Read the first integer input and store it in the array x

# Read remaining integers and store them in the array x
while x[i]!= 0:
	i = i + 1
	x[i] = int(input())
	# Comment explaining what the loop does
	# This loop reads and stores the remaining integers in the array x

# Print the results
for j in range(i):
	print("Case %d: %d" % (j+1,x[j]))
	# Comment explaining what the loop does
	# This loop prints the results for each input integer

# Signal successful termination of the program
return 0

