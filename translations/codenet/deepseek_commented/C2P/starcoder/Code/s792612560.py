# Step 1: Import the math module
import math

# Step 2: Define a function called factorial that takes a single input
def factorial(n):
	# Step 3: Declare an integer variable m
	m=n
	# Step 4: Read an integer input from the user and store it in n
	n=int(input("Enter a number: "))
	# Step 5: Copy the value of n to m
	m=n
	# Step 6: Decrement the value of n by 1
	n-=1
	# Step 7: Start a for loop that runs while n is greater than 1
	for i in range(n,1,-1):
		# Inside the loop, multiply m by n and decrement n by 1
		m*=i
	# Step 8: Print the value of m, which represents the factorial of the input number
	print(m)

# Step 9: Call the factorial function
factorial(n)

# Step 10: End the program with a comment
# 