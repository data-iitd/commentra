

# Read the number of elements and the size of the subarray from the user
n = int(input())
a = int(input())

# Read the elements of the array from the user and store them in a list
s = [int(input()) for _ in range(n)]

# Sort the list in ascending order
s.sort()

# Calculate the sum of the last 'a' elements of the sorted list
sum = sum(s[-a:])

# Print the result
print(sum)

