n = int(input())
a = list(map(int, input().split()))

# Create a copy of the input list to store absolute values
abs_a = [abs(x) for x in a]

# Initialize variables to calculate the sum of absolute values and find the minimum absolute value
ans = sum(abs_a)
min_abs = abs_a[0]

# Find the minimum absolute value
for e in abs_a:
    if min_abs > e:
        min_abs = e

# Count the number of negative numbers in the original array
num_negative = sum(1 for x in a if x < 0)

# If the count of negative numbers is odd, adjust the total sum
if num_negative % 2:
    ans -= min_abs * 2

# Output the final result
print(ans)
