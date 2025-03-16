
# Include the standard input/output library

# Function to compare two integers for qsort
def compare(a, b):
    return (b - a)
# Subtract the address of b from the address of a to get the difference between the two integers

# Declare an array of 10 integers
array = [0] * 10
# Initialize an array of 10 integers

for i in range(10): # Iterate through the array to read 10 integers
    array[i] = int(input())
# Read an integer from the user and store it in the array

array.sort(reverse=True, key=compare)
# Sort the array using the quicksort algorithm and the compare function

for i in range(3): # Iterate through the first three elements of the sorted array
    print(array[i])
# Print the first three sorted integers

# Return 0 to indicate successful execution of the program

# 