
# Step 1: Import the required module.
import sys

# Step 2: Define the main function.
def main():
	# Step 3: Read two integers from the user.
	a = int(input())
	b = int(input())
	
	# Step 4: Calculate the perimeter of a rectangle using the formula 2*a + 2*b and store it in x.
	x = 2*a + 2*b
	
	# Step 5: Calculate the area of a rectangle using the formula a*b and store it in y.
	y = a*b
	
	# Step 6: Print the area and perimeter.
	print(y,x)
	
	# Step 7: Return 0 to indicate successful execution.
	return 0

# Step 8: Call the main function.
if __name__ == "__main__":
	main()

# 