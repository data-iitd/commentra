
# Declare variables
a = [0] * 10000
min = 0
max = 0
n = 0
i = 0
sum = 0

# Read the number of elements in the array
n = int(input("Enter the number of elements in the array: "))

# Initialize a for loop to read elements into the array and calculate sum
for i in range(0, n):
# Read each element into the array
a[i] = int(input("Enter element %d: " % (i + 1)))

# Add the current element to the sum
sum += a[i]

# Initialize a for loop to find minimum and maximum elements in the array
for i in range(1, n):
# Initialize min and max with the first element of the array
if a[i] > max: max = a[i]
if a[i] < min: min = a[i]

# Print the minimum, maximum, and sum
print("Minimum element is %d" % min)
print("Maximum element is %d" % max)
print("Sum of all elements is %d" % sum)

# Return 0 to indicate successful execution
return 0

