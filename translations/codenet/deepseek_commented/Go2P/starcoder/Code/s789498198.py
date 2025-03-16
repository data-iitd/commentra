import sys

# Read two integers A and B from standard input
A, B = map(int, input().split())

# Check if the sum of A and B is even
if (A+B)%2 == 0:
	# If even, print the average of A and B
	print((A + B) / 2)
else:
	# If not even, print "IMPOSSIBLE"
	print("IMPOSSIBLE")

# 