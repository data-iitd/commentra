# Read an integer input for the number of elements
n = int(input())

# Read a line of space-separated floats and convert them to a list of floats
arr = list(map(float, input().split()))

# Calculate the fractional parts of the elements, excluding whole numbers
arr = sorted([x - int(x) for x in arr if x - int(x) != 0])

# Calculate the number of whole numbers that can be added to the fractional parts
o = 2 * n - len(arr)

# Calculate the sum of the fractional parts
arr_sum = sum(arr)

# Initialize the result with a large number
res = int(2e9)

# Iterate through possible counts of fractional parts used
for i in range(n + 1):
    # Check if the current count of fractional parts plus whole numbers is sufficient
    if i + o >= n:
        # Update the result with the minimum difference found
        res = min(res, abs(i - arr_sum))

# Print the result formatted to three decimal places
print("%.3f" % res)
