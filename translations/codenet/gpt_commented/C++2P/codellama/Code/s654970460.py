# Declare an integer variable 'n' for the number of elements,
# an array 'a' of size 101 to store the elements, and an integer 'i' for iteration.
n = 0
a = [0] * 101
i = 0

# Read the number of elements 'n' from the user.
n = int(input())

# Loop to read 'n' elements into the array 'a'.
for i in range(n):
    a[i] = int(input())

# Output the last element of the array (a[n-1]).
print(a[n-1])

# Loop to output the elements of the array in reverse order,
# starting from the second last element down to the first element.
for i in range(1, n):
    print(a[n - i - 1], end=" ")

# Print a newline character at the end of the output.
print()

# Return 0 to indicate successful completion of the program.
return 0

