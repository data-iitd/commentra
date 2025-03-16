# Declare variables
n = 0
avg = 0
s = 0
ans = 0

# Read the number of elements from the standard input
n = int(input())

# Declare and initialize an array of size 100 with zeros
a = [0] * 100

# Read an element from the standard input and store it in the array
for i in range(n):
    a[i] = int(input())

# Calculate the average of the elements in the array
for i in range(n):
    avg += a[i]

# Calculate the average and divide it by the number of elements
avg /= n

# Initialize the difference between the first element and the average
s = abs(a[0] - avg)

# Initialize the index of the element with the maximum difference from the average
ans = 0

# Find the index of the element with the maximum difference from the average
for i in range(1, n):
    if s > abs(a[i] - avg):
        s = abs(a[i] - avg)
        ans = i

# Print the index of the element with the maximum difference from the average
print(ans)

# Terminate the program
