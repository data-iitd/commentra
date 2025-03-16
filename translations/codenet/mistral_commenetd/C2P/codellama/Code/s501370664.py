
#include <stdio.h>
#include <stdlib.h>

# Declare a flag array to keep track of prime numbers
flag = [0] * 50001

# Function to find prime numbers up to a given limit
def prime(num):
	for i in range(2, int(num**0.5) + 1):
		if flag[i] == 0:
			for j in range(i*i, num+1, i):
				flag[j] = 1

# Loop until user inputs 0
while True:
	# Read user input for number n
	n = int(input())
	# Break the loop if user inputs 0
	if n == 0:
		break
	# Initialize i and cnt to 0
	i = 2
	cnt = 0
	# Loop through numbers from 2 to square root of n
	while i*i <= n:
		# If i and n-i are both prime, increment cnt
		if flag[i] == 0 and flag[n-i] == 0:
			cnt += 1
		# Increment i for next iteration
		i += 1
	# Print the result
	print(cnt)

# Return 0 to indicate successful execution
return 0

