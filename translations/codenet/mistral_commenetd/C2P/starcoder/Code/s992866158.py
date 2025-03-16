# The main function is the entry point of the program
def main():
	# Declare variables n, k, and cnt of type int
	n = 0
	k = 0
	cnt = 0

	# Read two integers n and k from the standard input using input()
	n, k = input().split()
	# Convert n and k to integers
	n = int(n)
	k = int(k)
	# Initialize variable cnt to zero
	cnt = 0
	# Loop through n times using a while loop
	while n > 0:
		# Declare variable h of type int
		h = 0

		# Read an integer h from the standard input using input()
		h = int(input())
		# If h is greater than or equal to k, increment cnt by 1
		if h >= k:
			cnt += 1
		# Decrement n by 1
		n -= 1
	# Print the value of cnt to the standard output using print()
	print(cnt)

# Call the main function
if __name__ == "__main__":
	main()

