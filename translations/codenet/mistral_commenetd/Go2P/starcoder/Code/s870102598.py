
# Define the main function as the entry point of our program
def main():
	# Declare and initialize three integer variables "a", "b", and "c"
	a, b, c = 0, 0, 0
	a, b, c = map(int, input().split())

	# Check if the value of "c" is within the range of "a" and "b"
	if c >= a and c <= b:
		# If the condition is true, print the string "Yes" to the standard output
		print("Yes")
	else:
		# If the condition is false, print the string "No" to the standard output
		print("No")

# Start the execution if it's the main script
if __name__ == "__main__":
	# Start the execution of the main function
	main()

