

# Python code to find prime numbers and count pairs of prime numbers

# Function to find prime numbers up to a given limit
def prime(num):
	# Allocate memory for flag array of size num+1
	flag = [0]*(num+1)

	# Loop through numbers from 2 to num
	for i in range(2,int(num**0.5)+1):
		# If a number is not marked as composite, mark all its multiples as composite
		if flag[i] == 0:
			for j in range(2,num//i+1):
				flag[i*j] = 1

	# Return the flag array
	return flag

# Main function to find pairs of prime numbers
def main():
	# Call prime function to find prime numbers up to 50000
	flag = prime(50000)

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

# Call the main function
if __name__ == "__main__":
	main()

