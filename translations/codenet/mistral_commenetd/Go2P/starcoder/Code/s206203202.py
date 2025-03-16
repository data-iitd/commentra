# Package main is the entry point of the program
import sys

# Abs function returns the absolute value of an integer
def Abs(x):
	if x < 0:
		# If the input integer is negative, return its negation
		return -x
	# Otherwise, return the input integer as it is
	return x

# min function returns the minimum of two integers
def min(a, b):
	if a > b:
		# If the first integer is greater than the second, return the second
		return b
	# Otherwise, return the first integer
	return a

# main function is the entry point of the program
def main():
	# Declare and initialize two integer variables, N and K, using sys.stdin.readline
	N, K = map(int, sys.stdin.readline().split())

	# Declare and initialize an integer variable, x, with the value of N modulo K
	x = N % K

	# Call the Abs function to get the absolute value of x if it's negative
	x = Abs(x)

	# Call the min function to find the minimum between x and Abs(x-K)
	x = min(Abs(x-K), x)

	# Print the result using sys.stdout.write
	sys.stdout.write(str(x))

# Call the main function
if __name__ == "__main__":
	main()

