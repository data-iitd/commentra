
import sys  # Import the sys module to access standard input-output functions

def main():
	n, m = map(int, sys.stdin.readline().split())  # Read two integers from the standard input and store them in n and m
	print((n - 1) * (m - 1))  # Print the result of the expression (n - 1) * (m - 1)
	sys.stdout.flush()  # Ensure buffered output is written to the standard output stream immediately
	return 0  # Return 0 to indicate successful execution

if __name__ == "__main__":
	main()
