# Take the number of test cases as input
n = int(input())

# Read the first list 'a' of numbers from the standard input
a = list(map(int, input().split()))

# Read the second list 'b' of numbers from the standard input
b = list(map(int, input().split()))

# Read the third list 'c' of numbers from the standard input
c = list(map(int, input().split()))

# Initialize variables x, y, and z to 0
x = 0
y = 0
z = 0

# Iterate through each number in list 'a' and add it to the variable 'x'
for i in a:
    x += i

# Iterate through each number in list 'b' and add it to the variable 'y'
for i in b:
    y += i

# Iterate through each number in list 'c' and add it to the variable 'z'
for i in c:
    z += i

# Print the absolute difference between 'x' and 'y'
print(abs(x - y))

# Print the absolute difference between 'y' and 'z'
print(abs(y - z))