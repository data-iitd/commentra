

# Step 1: Import the required module
import sys

# Step 2: Define the main function
def main():
	# Step 3: Read input from the user
	n = int(input())
	
	# Step 4: Calculate the sum of the first n natural numbers
	sum = (n * (n + 1)) // 2
	
	# Step 5: Print the result
	print(sum)
	
	# Step 6: Return from the main function
	return 0

# Step 7: Call the main function
if __name__ == "__main__":
	sys.exit(main())

# 