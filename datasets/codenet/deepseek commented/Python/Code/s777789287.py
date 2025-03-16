
n, m = map(int, input().split())  # Read two integers n and m from input
a = list(map(int, input().split()))  # Read a list of integers a from input
a.sort(reverse=True)  # Sort the list a in descending order
s = sum(a)/(4*m)  # Calculate the average of the list a divided by 4*m
if a[m-1]>=s:  # Compare the m-th element of the sorted list a with the threshold s
    print('Yes')  # Print 'Yes' if the m-th element is greater than or equal to s
else:
    print('No')  # Print 'No' otherwise

