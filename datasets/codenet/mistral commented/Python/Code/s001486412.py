# Get the number of elements in the list from user input
n = int(input())

# Get the list of integers from user input and convert them to a list
a = list(map(int,input().split()))

# Initialize a variable 'below' to 0
below = 0

# Iterate through each element in the list 'a' and calculate the reciprocal of each element
# Add the reciprocal to the variable 'below'
for i in range(n):
    below += 1/a[i]

# After the loop, calculate the reciprocal of the sum of all reciprocals and print it
print(1/below)
