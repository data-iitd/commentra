
n = int(input())  # Read the number of elements in each list
a = list(map(int, input().split()))  # Read the first list of integers
b = list(map(int, input().split()))  # Read the second list of integers
c = list(map(int, input().split()))  # Read the third list of integers

x = 0  # Initialize the sum of elements in list a
y = 0  # Initialize the sum of elements in list b
z = 0  # Initialize the sum of elements in list c

# Calculate the sum of elements in each list
for i in a:
    x += i  # Add each element of list a to x
for i in b:
    y += i  # Add each element of list b to y
for i in c:
    z += i  # Add each element of list c to z

# Print the absolute differences between the sums of the lists
print(abs(x - y))  # Print the absolute difference between the sums of lists a and b
print(abs(y - z))  # Print the absolute difference between the sums of lists b and c


