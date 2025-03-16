
# Read the number of integers to be processed
n = int(input())

# Read n integers from input and calculate their sum
a = []
sum = 0
for i in range(n):
    a.append(int(input()))
    sum += a[i]

# Initialize min and max with the first element of the array
max = min = a[0]

# Iterate through the array to find the minimum and maximum values
for i in range(1, n):
    if a[i] > max: max = a[i] # Update max if the current element is greater
    if a[i] < min: min = a[i] # Update min if the current element is smaller

# Print the minimum, maximum, and sum of the integers
print(min, max, sum)

