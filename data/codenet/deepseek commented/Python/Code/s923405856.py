
while True:
	n = int(input())  # Read the number of elements
	
	if n == 0:
		break  # Exit the loop if n is 0
	
	res = -1111111111  # Initialize res to a very small number
	s = 0  # Initialize s to 0
	for i in range(n):
		a = int(input())  # Read the next element
		s = max(s + a, a)  # Update s to be the maximum of s + a and a
		res = max(s, res)  # Update res to be the maximum of s and res
	
	print(res)  # Print the result

