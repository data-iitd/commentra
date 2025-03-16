
n = int(input())  # Read the integer input `n`
a = []  # Initialize an empty list `a`
for i in range(2):
    a.append(list(map(int, input().split())))  # Take two lines of integer inputs and append them to `a`
a[1] = a[1][::-1]  # Reverse the second list in `a`
import numpy  # Import the `numpy` library
res_0 = numpy.cumsum(a[0])  # Calculate the cumulative sum of the first list in `a`
res_1 = numpy.cumsum(a[1])  # Calculate the cumulative sum of the reversed second list in `a`
ans = 0  # Initialize a variable `ans` to 0
for i in range(n):
    check = res_0[i] + res_1[n-1-i]  # Calculate the sum of the cumulative sums at each index
    ans = max(ans, check)  # Update `ans` with the maximum value found
print(ans)  # Print the value of `ans`

