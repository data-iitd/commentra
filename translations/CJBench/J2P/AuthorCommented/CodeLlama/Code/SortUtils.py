
import sys

# Input: Array elements
n = int(input())
array = list(map(int, input().split()))

# Perform operations
# Example 1: Swap elements
i, j = map(int, input().split())
array[i], array[j] = array[j], array[i]
print(*array)

# Example 2: Check if the array is sorted
print(all(array[i] <= array[i + 1] for i in range(len(array) - 1)))

# Example 3: Flip the array between two indices
left, right = map(int, input().split())
array[left:right + 1] = array[left:right + 1][::-1]
print(*array)

# END-OF-CODE
