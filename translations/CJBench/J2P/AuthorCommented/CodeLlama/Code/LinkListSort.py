
import sys

# This is the entry point for the program.
if __name__ == "__main__":
    # Take user input for the linked list and sorting option
    n = int(input())
    inputArray = list(map(int, input().split()))
    sortingChoice = int(input())

    # Choice is choosed as any number from 1 to 3 (So the linked list will be
    # sorted by Merge sort technique/Insertion sort technique/Heap sort technique)
    if sortingChoice == 1:
        start = mergeSort(inputArray)
    elif sortingChoice == 2:
        start = insertionSort(inputArray)
    elif sortingChoice == 3:
        start = heapSort(inputArray)
    else:
        print("Invalid choice!")
        sys.exit()

    # Convert sorted linked list back to array
    resultArray = convertLinkedListToArray(start)

    # Compare sorted linked list result with expected sorted array
    if resultArray == sorted(inputArray):
        print("LinkedList is sorted correctly.")
    else:
        print("LinkedList is not sorted correctly.")

def mergeSort(inputArray):
    if len(inputArray) <= 1:
        return inputArray
    mid = len(inputArray) // 2
    left = mergeSort(inputArray[:mid])
    right = mergeSort(inputArray[mid:])
    return merge(left, right)

def merge(left, right):
    result = []
    while left and right:
        if left[0] <= right[0]:
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))
    if left:
        result.extend(left)
    if right:
        result.extend(right)
    return result

def insertionSort(inputArray):
    for i in range(1, len(inputArray)):
        key = inputArray[i]
        j = i - 1
        while j >= 0 and inputArray[j] > key:
            inputArray[j + 1] = inputArray[j]
            j -= 1
        inputArray[j + 1] = key
    return inputArray

def heapSort(inputArray):
    for i in range(len(inputArray) // 2 - 1, -1, -1):
        heapify(inputArray, i, len(inputArray))
    for i in range(len(inputArray) - 1, 0, -1):
        inputArray[0], inputArray[i] = inputArray[i], inputArray[0]
        heapify(inputArray, 0, i)
    return inputArray

def heapify(inputArray, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    if left < n and inputArray[left] > inputArray[largest]:
        largest = left
    if right < n and inputArray[right] > inputArray[largest]:
        largest = right
    if largest != i:
        inputArray[i], inputArray[largest] = inputArray[largest], inputArray[i]
        heapify(inputArray, n, largest)

def convertLinkedListToArray(head):
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result

class Node:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

