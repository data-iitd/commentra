
# Take the number of elements and the size of the list as input
n, m = map(int, input().split())

# Convert the input strings to integers
a = list(map(int, input().split()))

# Sort the list in descending order
a.sort(reverse=True)

# Calculate the average value of the list elements
s = sum(a)/(4*m)

# Check if the last element of the list is greater than or equal to the average value
if a[m-1] >= s:
    print('Yes')
else:
    print('No')