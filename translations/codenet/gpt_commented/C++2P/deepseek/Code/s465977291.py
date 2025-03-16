import math

# Read input values for n and d from the user
n, d = map(int, input().split())

# Calculate the effective range of coverage, which is (d*2 + 1)
a = d * 2 + 1

# Calculate and output the minimum number of groups needed to cover 'n' items
# This is done by dividing 'n' by the coverage 'a' and rounding up to the nearest whole number
groups = math.ceil(n / a)
print(groups)
