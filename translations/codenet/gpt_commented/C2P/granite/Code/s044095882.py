
# Read the size of the array from user input
n = int(input())

# Declare two arrays: one to hold the input values and another to count occurrences
a = [0] * n
count = [0] * n

# Read the input values into the array 'a', starting from index 1
for i in range(1, n):
  a[i] = int(input())

# Count the occurrences of each value in the array 'a'
# The value at a[i] is used to index into the count array
for i in range(1, n):
  count[a[i]-1] += 1

# Print the counts of each index in the count array
for i in range(n):
  print(count[i])

# End of code
