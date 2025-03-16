import sys

# Main function is the entry point of the program
def main():
	# Initialize variables R, G, B, and N with next integers
	R = int(input())
	G = int(input())
	B = int(input())
	N = int(input())

	# Initialize variable ans with zero
	ans = 0

	# Nested for loops to iterate through all possible combinations of x and y within the range of N
	for x in range(N+1):
		for y in range(N+1):
			# Calculate temporary variable tmp
			tmp = N - R*x - G*y

			# Check if tmp is non-negative and the remainder of tmp when divided by B is zero
			if tmp >= 0 and tmp%B == 0:
				# Increment the value of ans if the condition is true
				ans += 1

	# Print the value of ans
	print(ans)

# Input related functions
def nextInt():
	# Read next word as string, convert it to integer, and return
	return int(input())

def nextFloat():
	# Read next word as string, convert it to float64, and return
	return float(input())

def nextString():
	# Read next word as string and return
	return input()

# Utility functions
def abs(x):
	# Return absolute value of x
	return abs(x)

def min(x, y):
	# Return minimum value of x and y
	return min(x, y)

def max(x, y):
	# Return maximum value of x and y
	return max(x, y)

# Entry point of program
if __name__ == "__main__":
	main()

