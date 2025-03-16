
# Read the number of elements and the number of largest elements to sum
n = int(input())
a = int(input())

# Initialize a variable to hold the sum of the largest elements
sum = 0

# Declare an array to hold the elements
s = []

# Read the elements into the array from user input
for i in range(n):
    s.append(int(input()))

# Sort the array in non-decreasing order
s.sort()

# Sum the largest 'a' elements from the sorted array
for i in range(n - a, n):
    sum += s[i]

# Output the calculated sum of the largest 'a' elements
print(sum)

