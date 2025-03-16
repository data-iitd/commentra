
A,B = map(int, input().split())

# Taking two integer inputs A and B

if (A+B)%2 == 1 :
	# Checking if the sum of A and B is odd
	print('IMPOSSIBLE')
else :
	# If the sum is even, calculating the average of A and B
	print((A+B)//2)

