
n = input()
l = list(map(int, input().split()))

# Input the number of elements in the list
n = input()

# Input the list of integers and convert them to a list of integers
l = list(map(int, input().split()))

# Find the maximum value in the list
b = max(l)

# Calculate the sum of all elements in the list
s = sum(l)

# Check if the maximum value is less than the sum of the rest of the elements
if b < s - b:
    print('Yes')
else:
    print('No')

