# Declare variables
a = []
sum = 0

# Read the number of elements in the array
n = int(input("Enter the number of elements in the array: "))

# Initialize a for loop to read elements into the array and calculate sum
for i in range(n):
    # Read each element into the array
    element = int(input(f"Enter element {i + 1}: "))
    a.append(element)

    # Add the current element to the sum
    sum += element

# Initialize min and max with the first element of the array
min = a[0]
max = a[0]

# Initialize a for loop to find minimum and maximum elements in the array
for i in range(1, n):
    if a[i] > max:
        max = a[i]
    if a[i] < min:
        min = a[i]

# Print the minimum, maximum, and sum
print(f"Minimum element is {min}")
print(f"Maximum element is {max}")
print(f"Sum of all elements is {sum}")

# <END-OF-CODE>
