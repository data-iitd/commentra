

# Read the number of elements in the array
n = int(input("Enter the number of elements in the array: "))

# Initialize an empty list to store the array elements
a = []

# Initialize a for loop to read elements into the array and calculate sum
for i in range(n):
# Read each element into the array
element = int(input("Enter element %d: " % (i + 1)))
a.append(element)

# Initialize a for loop to find minimum and maximum elements in the array
min = a[0]
max = a[0]
for i in range(1, n):
# Update min and max with the current element
if a[i] > max:
max = a[i]
if a[i] < min:
min = a[i]

# Calculate the sum of all elements in the array
sum = sum(a)

# Print the minimum, maximum, and sum
print("Minimum element is %d" % min)
print("Maximum element is %d" % max)
print("Sum of all elements is %d" % sum)

# 