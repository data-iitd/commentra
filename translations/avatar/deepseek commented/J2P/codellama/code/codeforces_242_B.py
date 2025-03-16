import math

# Defining a constant INF for a very large number
INF = 1000000005

# Creating a Scanner object to read input
sc = input()
n = int(sc)

# Initializing two lists to store the elements
a = []
b = []

# Initializing variables to track the minimum and maximum values
left = INF
right = 0

# Looping through n elements to read and update the lists and variables
for i in range(n):
    a.append(int(input()))
    b.append(int(input()))
    left = min(left, a[i])
    right = max(right, b[i])

# Looping through the lists to find the target element
for i in range(n):
    if left == a[i] and right == b[i]:
        print(i + 1)
        break
else:
    print(-1)

# END-OF-CODE
