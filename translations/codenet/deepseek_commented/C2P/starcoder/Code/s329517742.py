# Step 1: Include the standard input/output library.
import sys
# Step 2: Define the main function.
def main():
	a,b = map(int,raw_input().split()) # Step 3: Declare two integer variables a and b.
	if(500*a>=b): print "Yes" # Step 4: Check if the product of 500 and a is greater than or equal to b.
	else: print "No" # Step 5: Print "Yes" if the condition is true, otherwise print "No".
# Step 6: End the main function and return 0.
if __name__ == "__main__":
	main()
# 