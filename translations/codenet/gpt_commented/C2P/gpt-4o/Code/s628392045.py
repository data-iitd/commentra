# Declare variables
n = int(input())  # Read the number of elements
h = []  # List to store heights
max_height = -1  # Variable to track the maximum height
flag = 0  # Flag to indicate if the condition is met

# Loop to read heights and determine the maximum height
for i in range(n):
    height = int(input())  # Read height
    h.append(height)  # Store height in the list
    
    # Update maximum height if current height is greater
    if max_height < height:
        max_height = height

    # Check if the difference between max height and current height is 2 or more
    if max_height - height >= 2:
        flag = 1  # Set flag if condition is met

# Output result based on the flag value
if flag == 1:
    print("No")  # If flag is set, print "No"
else:
    print("Yes")  # If flag is not set, print "Yes"

# <END-OF-CODE>
