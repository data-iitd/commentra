# Python program to perform basic operations
# on two numbers and print the result

# Function to perform basic operations
def basic_op(a, b, S):
	# Perform operations based on the value of S
	if S == '+':
		print(a + b)
	elif S == '-':
		print(a - b)
	elif S == '*':
		print(a * b)
	elif S == '/':
		print(a / b)

# Infinite loop to continuously take input and perform operations
while True:
	# Take input in the format a S b
	a, S, b = input().split()
	
	# Convert the input into integers
	a = int(a)
	b = int(b)
	
	# Call the function to perform basic operations
	basic_op(a, b, S)
	
	# Break the loop if S is '?'
	if S == '?':
		break

# 