# Take an integer input 'n' from the user
n = int(input())

# Take 'n' floating point numbers as input and store them in a list 'arr'
arr = list(map(float, input().split()))

# Filter out the integers from the list 'arr' and sort the remaining floating point numbers
arr = sorted([x - int(x) for x in arr if x - int(x) != 0])

# Calculate the length of the filtered list 'arr' and assign it to the variable 'o'
o = 2 * n - len(arr)

# Calculate the sum of all the floating point numbers in the list 'arr' and assign it to the variable 'arr_sum'
arr_sum = sum(arr)

# Initialize the variable 'res' with a large integer value
res = int(2e9)

# Iterate through the range from 0 to n+1
for i in range(n+1):
    # Check if the index 'i' plus the offset 'o' is greater than or equal to 'n'
    if i + o >= n:
        # Update the minimum value of 'res' with the absolute difference between 'i' and 'arr_sum'
        res = min(res, abs(i - arr_sum))

# Print the result with three decimal places
print("%.3f" % res)
