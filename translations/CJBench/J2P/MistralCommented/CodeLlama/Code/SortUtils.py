
import sys

# Reads the number of elements in the array from the standard input
n = int(sys.stdin.readline().strip())

# Creates an Integer array with the given size
array = [int(sys.stdin.readline().strip()) for _ in range(n)]

# Reads the indices i and j of the two elements to be swapped from the standard input
i, j = map(int, sys.stdin.readline().strip().split())

# Swaps the elements at the given indices in the array
array[i], array[j] = array[j], array[i]

# Prints the swapped array
print(' '.join(map(str, array)))

# Checks if the array is sorted in ascending order
sorted = True
for i in range(1, len(array)):
    if array[i] < array[i - 1]:
        sorted = False
        break

# Prints whether the array is sorted or not
print(sorted)

# Reads the left and right indices of the subarray to be flipped from the standard input
left, right = map(int, sys.stdin.readline().strip().split())

# Flips the subarray from left to right in the array
array[left:right + 1] = array[left:right + 1][::-1]

# Prints the flipped array
print(' '.join(map(str, array)))

# END-OF-CODE
