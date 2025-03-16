import math

# Read two integers a and b from input
a, b = map(int, input().split())

# Convert b to string to determine its length
bstr = str(b)

# Calculate the number formed by concatenating a and b
num = a * (10 ** len(bstr)) + b

# Initialize a variable to find the square root of num
i = 1

# Loop to check if there exists an integer i such that i*i equals num
while i <= 100100:
    if i * i == num:
        break
    i += 1

# Check if a valid integer i was found within the range
if i > 100100:
    print("No")  # If no such i exists, print "No"
else:
    print("Yes")  # If such i exists, print "Yes"

# <END-OF-CODE>
