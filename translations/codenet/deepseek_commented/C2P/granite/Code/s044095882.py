
# Read the value of n from the standard input
n = int(input())

# Declare an array `a` with size n
a = [0] * n

# Declare an array `count` with size n
count = [0] * n

# Loop to read n-1 values into the array `a`
for i in range(1, n):
    a[i] = int(input())

# Loop to increment the `count` array based on the values in `a`
for i in range(1, n):
    count[a[i]-1] += 1

# Loop to print the values in the `count` array
for i in range(n):
    print(count[i])

