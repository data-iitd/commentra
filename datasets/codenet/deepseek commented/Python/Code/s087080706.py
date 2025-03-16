# Take three integers n, m, and x as input and assign them to variables n, m, and x respectively.
n, m, x = (int(i) for i in input().split())

# Take a list of integers as input and assign it to the variable a.
a = [int(i) for i in input().split()]

# Initialize the variable ans to 0.
ans = 0

# Import the bisect function from the bisect module.
from bisect import bisect

# Assign the index where x would be inserted into the list a using the bisect function to the variable i.
i = bisect(a, x)

# Output the minimum of the lengths of the sublists a[:i] and a[i:].
print(min(len(a[:i]), len(a[i:])))
