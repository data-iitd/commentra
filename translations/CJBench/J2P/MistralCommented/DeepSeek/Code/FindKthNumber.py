import random

def findKthMax(array, k):
    if k <= 0 or k > len(array):
        raise ValueError("k must be between 1 and the size of the array")
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
    array[pivotIndex], array[right] = array[right], array[pivotIndex]
    storeIndex = left
    for i in range(left, right):
        if array[i] < pivotValue:
            array[storeIndex], array[i] = array[i], array[storeIndex]
            storeIndex += 1
    array[storeIndex], array[right] = array[right], array[storeIndex]
    return storeIndex

def main():
    try:
        n = int(input())
        if n <= 0:
            print("Array size must be positive.")
            return
        array = list(map(int, input().split()))
        k = int(input())
        if k <= 0 or k > n:
            print("Error: k must be between 1 and the size of the array.")
            return
        result = findKthMax(array, k)
        print(f"The {k}-th largest element is: {result}")
    except Exception as e:
        print(f"An error occurred: {e}")

main()

