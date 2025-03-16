# Import the bisect module for efficient searching in a sorted list
from bisect import bisect_right, bisect_left

# Read the number of elements 'n' and a list 'l' of 'n' integers from standard input
n, * l = map(int, open(0).read().split())

# Sort the list 'l' in ascending order
l.sort()

# Initialize an answer variable 'ans' to zero
ans = 0

# Iterate through each pair of indices 'i' and 'j' in the list 'l'
for i in range(n):
    for j in range(i+1, n):
        # Assign the elements at indices 'i' and 'j' to variables 'a' and 'b' respectively
        a = l[i]
        b = l[j]

        # Use bisect_left to find the index 'right' where an element greater than 'a+b' is present
        right = bisect_left(l, a+b)

        # Use bisect_right to find the index 'left' where the smallest element greater than 'max(a-b, b-a)' is present
        left = bisect_right(l, max(a-b, b-a))

        # Calculate the temporary answer 'tmp' based on the indices 'left' and 'right'
        tmp = max(0, right-left)

        # Subtract one from the temporary answer 'tmp' if both 'i' and 'j' lie between 'left' and 'right'
        if left <= i < right:
            tmp -= 1
        if left <= j < right:
            tmp -= 1

        # Add the temporary answer 'tmp' to the final answer 'ans'
        ans += tmp

# Print the final answer 'ans' divided by three
print(ans // 3)
