
import random
import sys

def findKthMax(array, k):
    if k <= 0 or k > len(array):
        raise Exception("k must be between 1 and the size of the array")
    return quickSelect(array, 0, len(array) - 1, len(array) - k)

def quickSelect(array, left, right, kSmallest):
    if left == right:
        return array[left]
    pivotIndex = left + random.randint(0, right - left)
    pivotIndex = partition(array, left, right, pivotIndex)
    if kSmallest == pivotIndex:
        return array[kSmallest]
    elif kSmallest < pivotIndex:
        return quickSelect(array, left, pivotIndex - 1, kSmallest)
    else:
        return quickSelect(array, pivotIndex + 1, right, kSmallest)

def partition(array, left, right, pivotIndex):
    pivotValue = array[pivotIndex]
    swap(array, pivotIndex, right)
    storeIndex = left
    for i in range(left, right):
        if array[i] < pivotValue:
            swap(array, storeIndex, i)
            storeIndex += 1
    swap(array, storeIndex, right)
    return storeIndex

def swap(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp

if __name__ == "__main__":
    try:
        n = int(sys.stdin.readline())
        if n <= 0:
            print("Array size must be positive.")
            sys.exit(1)
        array = [int(sys.stdin.readline()) for i in range(n)]
        k = int(sys.stdin.readline())
        if k <= 0 or k > n:
            print("Error: k must be between 1 and the size of the array.")
            sys.exit(1)
        result = findKthMax(array, k)
        print("The " + str(k) + "-th largest element is: " + str(result))
    except Exception as e:
        print("An error occurred: " + str(e))

