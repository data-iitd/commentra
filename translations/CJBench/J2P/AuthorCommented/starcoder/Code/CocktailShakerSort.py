import sys

# Reading the size of the array
n = int(sys.stdin.readline())
array = []

# Reading the array elements
for i in range(n):
    array.append(int(sys.stdin.readline()))

# Sorting the array
def sort(array):
    if len(array) == 0:
        return

    left = 0
    right = len(array) - 1

    while left < right:
        right = performForwardPass(array, left, right)
        left = performBackwardPass(array, left, right)

def performForwardPass(array, left, right):
    lastSwappedIndex = left

    for i in range(left, right):
        if array[i] > array[i + 1]:
            swap(array, i, i + 1)
            lastSwappedIndex = i

    return lastSwappedIndex

def performBackwardPass(array, left, right):
    lastSwappedIndex = right

    for i in range(right, left, -1):
        if array[i] < array[i - 1]:
            swap(array, i - 1, i)
            lastSwappedIndex = i

    return lastSwappedIndex

def swap(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp

sort(array)

# Printing the sorted array
for num in array:
    print(num)

