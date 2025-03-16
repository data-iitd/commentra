
import sys
import random

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def isSorted(array, option):
    n = int(sys.stdin.readline())
    inputArray = [int(sys.stdin.readline()) for i in range(n)]
    sortingChoice = int(sys.stdin.readline())
    sortedArray = sorted(inputArray)
    start = createLinkedList(inputArray)
    if sortingChoice == 1:
        start = sortByMergeSort(start)
    elif sortingChoice == 2:
        start = sortByInsertionSort(start)
    elif sortingChoice == 3:
        start = sortByHeapSort(start)
    else:
        print("Invalid choice!")
        return False
    resultArray = convertLinkedListToArray(start)
    return sortedArray == resultArray

def createLinkedList(array):
    start = None
    prev = None
    for value in array:
        node = Node(value)
        if start == None:
            start = node
        else:
            prev.next = node
        prev = node
    return start

def convertLinkedListToArray(head):
    array = []
    while head!= None:
        array.append(head.val)
        head = head.next
    return array

def sortByMergeSort(head):
    if head == None or head.next == None:
        return head
    count = countNodes(head)
    array = convertToArray(head, count)
    mergeSort(array, 0, count - 1)
    return convertToList(array)

def countNodes(head):
    count = 0
    while head!= None:
        count += 1
        head = head.next
    return count

def convertToArray(head, size):
    array = [0] * size
    index = 0
    while head!= None:
        array[index] = head.val
        index += 1
        head = head.next
    return array

def convertToList(array):
    head = None
    tail = None
    for value in array:
        node = Node(value)
        if head == None:
            head = node
        else:
            tail.next = node
        tail = node
    return head

def mergeSort(array, left, right):
    if left < right:
        mid = (left + right) / 2
        mergeSort(array, left, mid)
        mergeSort(array, mid + 1, right)
        merge(array, left, mid, right)

def merge(array, left, mid, right):
    temp = [0] * (right - left + 1)
    i = left
    j = mid + 1
    k = 0
    while i <= mid and j <= right:
        if array[i] <= array[j]:
            temp[k] = array[i]
            i += 1
        else:
            temp[k] = array[j]
            j += 1
        k += 1
    while i <= mid:
        temp[k] = array[i]
        i += 1
        k += 1
    while j <= right:
        temp[k] = array[j]
        j += 1
        k += 1
    for i in range(left, right + 1):
        array[i] = temp[i - left]

def sortByInsertionSort(head):
    if head == None or head.next == None:
        return head
    count = countNodes(head)
    array = convertToArray(head, count)
    insertionSort(array)
    return convertToList(array)

def insertionSort(array):
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1
        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key

def sortByHeapSort(head):
    if head == None or head.next == None:
        return head
    count = countNodes(head)
    array = convertToArray(head, count)
    heapSort(array)
    return convertToList(array)

def heapSort(array):
    n = len(array)
    for i in range(n / 2 - 1, -1, -1):
        heapify(array, n, i)
    for i in range(n - 1, 0, -1):
        temp = array[0]
        array[0] = array[i]
        array[i] = temp
        heapify(array, i, 0)

def heapify(array, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    if left < n and array[left] > array[largest]:
        largest = left
    if right < n and array[right] > array[largest]:
        largest = right
    if largest!= i:
        swap = array[i]
        array[i] = array[largest]
        array[largest] = swap
        heapify(array, n, largest)

if __name__ == "__main__":
    if isSorted([], 0):
        print("LinkedList is sorted correctly.")
    else:
        print("LinkedList is not sorted correctly.")

