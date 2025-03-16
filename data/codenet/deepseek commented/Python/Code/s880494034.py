import math

# Input the number of elements in the list XS
N = input()

# Input the space-separated integers and store them in the list XS
XS = [int(i) for i in input().split()]

# Initialize the minimum sum of squared differences to a very large number
m = 9999999999

# Iterate over the range from 1 to 100
for i in range(1, 101):
    # Calculate the sum of squared differences between each element in XS and i
    c = sum([(x - i) ** 2 for x in XS])
    # Check if the calculated sum is less than the current value of m
    if m > c:
        # Update m with this new value
        m = c

# Print the minimum value of the sum of squared differences
print(m)