# Read the number of elements
n = int(input())

# Initialize a list to store the input numbers
a = list(map(int, input().split()))

# Create a copy of the input list to store absolute values
abs_a = a.copy()

# Convert all elements in abs_a to their absolute values
for i in range(n):
    if abs_a[i] < 0:
        abs_a[i] = -abs_a[i]

# Initialize variables to calculate the sum of absolute values and find the minimum absolute value
ans = 0
min_val = abs_a[0]

# Iterate through the absolute values to calculate the total sum and find the minimum
for e in abs_a:
    ans += e  # Accumulate the sum of absolute values
    if min_val > e:
        min_val = e  # Update the minimum absolute value found

# Count the number of negative numbers in the original array
num_negative = 0
for e in a:
    if e < 0:
        num_negative += 1  # Increment count for each negative number

# If the count of negative numbers is odd, adjust the total sum
if num_negative % 2:
    ans -= min_val * 2  # Subtract twice the minimum absolute value from the total sum

# Output the final result
print(ans)

# <END-OF-CODE>
