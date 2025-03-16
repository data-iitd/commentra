
n = int(input()) # Read the size of the array from the user input
a = [int(input()) for i in range(n)] # Read each element of the array 'a' from the user input

# Print the last element of the array
print(a[-1])

# Print the remaining elements of the array in reverse order
for i in range(n-1):
  print(" " + str(a[-i-2]), end="") # Print the current element with a space before it

print() # Print a newline character at the end

