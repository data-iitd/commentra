# Read two integers n and m from input, where n is the number of elements and m is the threshold index
n, m = map(int, input().split())

# Read a list of integers from input and store it in variable 'a'
a = list(map(int, input().split()))

# Sort the list 'a' in descending order
a.sort(reverse=True)

# Calculate the average of the top 4*m elements
s = sum(a) / (4 * m)

# Check if the m-th largest element is greater than or equal to the calculated average
if a[m - 1] >= s:
    # If the condition is met, print 'Yes'
    print('Yes')
else:
    # If the condition is not met, print 'No'
    print('No')
