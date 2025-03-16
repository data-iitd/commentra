# Start of the main function
n = int(input())  # Read the size of the array from the user input

# Allocate memory for the array 'a' of size 'n'
a = [0] * n  # Declare a list 'a' of size 'n'

for i in range(n):
    a[i] = int(input())  # Read each element of the array 'a' from the user input

# Print the last element of the array
print(a[n-1], end='')  # Print the last element without a newline

# Print the remaining elements of the array in reverse order
for i in range(1, n):
    print(" ", a[n-i-1], end='')  # Print the current element with a space before it

print()  # Print a newline character at the end

# Indicate successful termination of the program
# <END-OF-CODE>
