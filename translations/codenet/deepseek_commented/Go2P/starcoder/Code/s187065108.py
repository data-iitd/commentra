# Reads a single word from the input
def scanString():
	return input()

# Reads a slice of integers from input
def scanInts(n):
	return list(map(int, input().split()))

# Reads a slice of strings from input
def scanStrings(n):
	return input().split()

# Converts a scanned string to an integer
def scanInt():
	return int(scanString())

# Initializes the scanner to split input words
import sys
sc = sys.stdin.readline

# Main function to execute the program
def main():
	# Read initial values for r, D, and x
	r, D, x = scanInts(3)
	
	# Loop to calculate and print the values of x for 10 iterations
	for i in range(1, 11):
		x = r*x - D
		print(x)

# Entry point of the program
if __name__ == "__main__":
	main()

