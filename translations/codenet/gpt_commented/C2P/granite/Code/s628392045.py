
# Read the number of elements
n = int(input())

# Initialize variables
h = []
max = -1
flag = 0

# Loop to read heights and determine the maximum height
for i in range(n):
    # Read height into the array
    height = int(input())
    h.append(height)
    
    # Update maximum height if current height is greater
    if max < height: max = height
    
    # Check if the difference between max height and current height is 2 or more
    if max - height >= 2: flag = 1 # Set flag if condition is met

# Output result based on the flag value
if flag == 1: 
    print("No") # If flag is set, print "No"
else: 
    print("Yes") # If flag is not set, print "Yes"

