# Step 1: Include the necessary header files.
# We need to include the iostream header file to use input and output functions.

# Step 2: Declare the necessary variables.
# We need to declare a variable to store the number of elements in the array and an array to store the elements.

n = int(input())
array = [0] * 100  # Initialize an array of size 100

# Step 3: Read the number of elements and the elements of the array.
# We need to read the number of elements from the user and then read the elements of the array from the user.
for i in range(n):
    array[i] = int(input())

# Step 4: Calculate the sum of the products of all pairs of elements in the array.
# We need to use nested loops to iterate through all pairs of elements in the array and calculate their products.
sum = 0
for i in range(n - 1):
    for j in range(i + 1, n):
        sum += array[i] * array[j]

# Step 5: Print the result.
# Finally, we need to print the calculated sum.
print(sum)

# <END-OF-CODE>
