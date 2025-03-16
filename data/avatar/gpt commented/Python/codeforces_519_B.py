# Read an integer input which represents the number of elements in the lists
n = int(input())

# Read three lists of integers from input
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))

# Initialize variables to hold the sum of each list
x = 0
y = 0
z = 0

# Calculate the sum of elements in list 'a'
for i in a:
    x += i

# Calculate the sum of elements in list 'b'
for i in b:
    y += i

# Calculate the sum of elements in list 'c'
for i in c:
    z += i

# Print the absolute difference between the sums of list 'a' and list 'b'
print(abs(x - y))

# Print the absolute difference between the sums of list 'b' and list 'c'
print(abs(y - z))
