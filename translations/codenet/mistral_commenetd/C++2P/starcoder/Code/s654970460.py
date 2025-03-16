# Start of the program

# Prompt the user to enter the size of the array
n = int(input("Enter the size of the array: "))

# Allocate memory for the array 'a' of size 'n'
a = [0] * n

# Read the elements of the array 'a' from the user input
for i in range(n):
    a[i] = int(input("Enter the element: "))

# Print the last element of the array
print("The last element of the array is: ", a[n-1])

# Print the remaining elements of the array in reverse order
for i in range(1, n):
    print(" ", a[n-i-1])

# End of the program

