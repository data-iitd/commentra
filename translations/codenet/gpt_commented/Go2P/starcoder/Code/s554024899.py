# Set log flags to show the file name and line number for log messages
import logging
logging.basicConfig(level=logging.DEBUG, format='%(filename)s:%(lineno)d %(message)s')

# Initialize a new scanner to read input
sc = newScanner()

# Read two integers from input
x = sc.nextInt()
y = sc.nextInt()

# Initialize variables to store the category indices of x and y
xt, yt = 0, 0

# Define a 2D array where each sub-array represents a category of numbers
a = [[1, 3, 5, 7, 8, 10, 12], [4, 6, 9, 11], [2]]

# Iterate through the categories to find the indices of x and y
for i, t in enumerate(a):
	for _, n in enumerate(t):
		# Check if the current number matches x
		if x == n:
			xt = i # Store the category index for x
		# Check if the current number matches y
		if y == n:
			yt = i # Store the category index for y

# Compare the category indices of x and y and print the result
if xt == yt:
	print("Yes") # x and y belong to the same category
else:
	print("No")  # x and y belong to different categories

# 