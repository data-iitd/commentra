
# Read the value of n, which represents the number of elements in the array.
n = int(input())
# Dynamically allocate memory for an array 'a' of size n.
a = [0] * n
# Read n elements into the array 'a'.
for i in range(n):
    a[i] = int(input())
# Iterate through the array and calculate the sum of the differences between consecutive elements, updating the array 'a' to ensure each element is at least as large as the previous one.
sum = 0
for i in range(1, n):
    if a[i - 1] > a[i]:
        sum += a[i - 1] - a[i]
        a[i] = a[i - 1]
# Print the calculated sum.
print(sum)

