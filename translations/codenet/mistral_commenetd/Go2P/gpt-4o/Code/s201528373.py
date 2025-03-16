# Initialize variables
n = 0
x = 0
l = []

# Read input values for n and x
n = int(input("Enter the number of arrays: "))
x = int(input("Enter the sum of elements in an array that should not exceed: "))

# Read input values for each array and append them to the list l
for i in range(n):
    # Read the length of the current array
    tmpL = int(input(f"Enter the length of array number {i + 1}: "))
    l.append(tmpL)

# Initialize variables for sum and result slice index
tmpSum = 0
rs = 0

# Iterate through the list l to find the index of the last array whose sum is less than or equal to x
for i, v in enumerate(l):
    # Initialize a variable tmpSum to store the sum of elements in the current array
    tmpSum = 0

    # Calculate the sum of elements in the current array
    for j in range(v):
        # Read the value of the current element and add it to the sum
        tmp = int(input(f"Enter the value of element number {j + 1} in array number {i + 1}: "))
        tmpSum += tmp

    # Check if the sum of elements in the current array is greater than x
    if tmpSum > x:
        # If yes, break the loop as we don't need to check further arrays
        break

    # If the sum of elements in the current array is less than or equal to x, update the result slice index
    rs = i + 1

# Print the result slice index
print(f"The last array index whose sum of elements is less than or equal to {x} is: {rs}")

# <END-OF-CODE>
