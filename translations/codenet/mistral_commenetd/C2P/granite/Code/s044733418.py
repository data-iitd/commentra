

# Python code

array = [] # Declare an empty list to store the integers
# Initialize an empty list to store the integers

for i in range(10): # Iterate through the array to read 10 integers
    array.append(int(input()))
# Read 10 integers from the user and append them to the array

array.sort(reverse=True)
# Sort the array in descending order

print(array[:3])
# Print the first three elements of the sorted array

