import sys

def select(list, n):
    # Ensure the list is not null
    if list is None:
        raise ValueError("The list of elements must not be null.")
    
    # Check if the list is empty
    if len(list) == 0:
        raise ValueError("The list of elements must not be empty.")
    
    # Check if the index is within the valid range
    if n < 0 or n >= len(list):
        raise IndexError("The index must be between 0 and the size of the list - 1.")
    
    # Find the index of the n-th smallest element
    index = selectIndex(list, n)
    
    # Return the n-th smallest element
    return list[index]

# Private static method to find the index of the n-th smallest element
def selectIndex(list, n):
    return selectIndex(list, 0, len(list) - 1, n)

# Private static method to recursively find the index of the n-th smallest element
def selectIndex(list, left, right, n):
    while True:
        if left == right:
            return left
        pivotIndex = pivot(list, left, right)
        pivotIndex = partition(list, left, right, pivotIndex, n)
        if n == pivotIndex:
            return n
        elif n < pivotIndex:
            right = pivotIndex - 1
        else:
            left = pivotIndex + 1

# Private static method to partition the list around a pivot
def partition(list, left, right, pivotIndex, n):
    pivotValue = list[pivotIndex]
    list[pivotIndex], list[right] = list[right], list[pivotIndex]
    storeIndex = left
    for i in range(left, right):
        if list[i] < pivotValue:
            list[storeIndex], list[i] = list[i], list[storeIndex]
            storeIndex += 1
    list[right], list[storeIndex] = list[storeIndex], list[right]
    storeIndexEq = storeIndex
    for i in range(storeIndex, right):
        if list[i] == pivotValue:
            list[storeIndexEq], list[i] = list[i], list[storeIndexEq]
            storeIndexEq += 1
    list[storeIndexEq], list[right] = list[right], list[storeIndexEq]
    return (n < storeIndex) and storeIndex or min(n, storeIndexEq)

# Private static method to select a good pivot for partitioning
def pivot(list, left, right):
    if right - left < 5:
        return partition5(list, left, right)
    for i in range(left, right, 5):
        subRight = min(i + 4, right)
        median5 = partition5(list, i, subRight)
        list[median5], list[left + (i - left) / 5] = list[left + (i - left) / 5], list[median5]
    mid = left + (right - left) / 10 + 1
    rightIndex = left + (right - left) / 5
    return selectIndex(list, left, rightIndex, mid)

# Private static method to partition a sublist of 5 elements
def partition5(list, left, right):
    sublist = list[left:right + 1]
    sublist.sort()
    return left + (right - left) / 2

# Main method to read input, call the select method, and print the result
def main():
    n = int(raw_input().strip())
    list = []
    for i in range(n):
        list.append(int(raw_input().strip()))
    index = int(raw_input().strip())
    try:
        result = select(list, index)
        print "The " + str(index) + "-th smallest element is: " + str(result)
    except Exception as e:
        print e.message

if __name__ == "__main__":
    main()

