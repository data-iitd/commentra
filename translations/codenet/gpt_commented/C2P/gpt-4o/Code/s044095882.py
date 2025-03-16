# Declare a variable to hold the size of the array
n = int(input())

# Declare two lists: one to hold the input values and another to count occurrences
a = [0] * n
count = [0] * n

# Read the input values into the list 'a', starting from index 1
for i in range(1, n):
    a[i] = int(input())

# Count the occurrences of each value in the list 'a'
# The value at a[i] is used to index into the count list
for i in range(1, n):
    count[a[i] - 1] += 1

# Print the counts of each index in the count list
for i in range(n):
    print(count[i])

# <END-OF-CODE>
