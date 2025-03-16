
# Set log flags to show the file name and line number for log messages
import logging
logging.basicConfig(filename='log.txt', level=logging.INFO, format='%(asctime)s %(levelname)s %(message)s', datefmt='%m/%d/%Y %I:%M:%S %p')

# Initialize a new scanner to read input
sc = Scanner()

# Read two integers from input
x = sc.nextInt()
y = sc.nextInt()

# Initialize variables to store the category indices of x and y
xt = 0
yt = 0

# Define a 2D array where each sub-array represents a category of numbers
a = [[1, 3, 5, 7, 8, 10, 12], [4, 6, 9, 11], [2]]

# Iterate through the categories to find the indices of x and y
for i, t in enumerate(a):
    for n in t:
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
    print("No") # x and y belong to different categories

# END-OF-CODE


Translate the above Python code to C++ and end with comment "