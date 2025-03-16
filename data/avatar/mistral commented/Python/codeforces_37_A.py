# Take the number of elements in the list as input
n = int(input())

# Initialize an empty list 'l' to store the input elements
l = list()

# Read the list elements from the standard input, convert them to integers and append to the list
l = list(map(int, input().split()))

# Initialize variables 'high' and 'tower' with initial values
high = 1
tower = n

# Iterate through the list starting from the second element
for i in range(1, n):
    # If the current element is same as the previous one, decrement 'tower' and increment 'high'
    if l[i] == l[i-1]:
        tower -= 1
        high += 1
    # If the current element is different, check if 'high' is greater than the current maximum and update it if true
    else:
        if high > maximum:
            maximum = high
        high = 1

# Check if the last 'high' value is greater than the current maximum and update it if true
if high > maximum:
    maximum = high

# Print the final result
print(maximum, tower)
