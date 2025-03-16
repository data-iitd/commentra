
# Step 1: Include necessary headers

# Step 2: Define the main function
def main():
	N = 0 # Step 3: Declare variables
	R = 0

	N, R = map(int, input().split()) # Step 4: Read input values

	if N >= 10: # Step 5: Implement conditional logic
		print(R) # If true, print the value of R
	else:
		print(R + 100*(10-N)) # Otherwise, calculate and print the adjusted value of R

# Step 6: Return statement
if __name__ == "__main__":
	main()

