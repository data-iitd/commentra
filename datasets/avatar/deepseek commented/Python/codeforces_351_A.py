n = int(input())  # Input the number of elements (n)
arr = list(map(float, input().split()))  # Input the array elements

# Extract fractional parts and sort them
arr = sorted([x - int(x) for x in arr if x - int(x) != 0])

# Calculate the number of elements to be added to make the total number of elements equal to 2 * n
o = 2 * n - len(arr)

# Sum of the sorted fractional parts
arr_sum = sum(arr)

# Initialize the result variable to a very large number
res = int(2e9)

# Iterate to find the best position
for i in range(n + 1):
    if i + o >= n:
        res = min(res, abs(i - arr_sum))

# Print the result with three decimal places
print("%.3f" % res)
