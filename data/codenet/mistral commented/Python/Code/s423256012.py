
A, B = map(int, input().split())

# Define A and B as integers using map() and input().split() method

if (A + B) % 2 == 1:
	# Check if the sum of A and B is odd
	print('IMPOSSIBLE')
	# If sum is odd, print 'IMPOSSIBLE' as output
else:
	# If sum is even, print the result of sum divided by 2
	print((A + B) // 2)