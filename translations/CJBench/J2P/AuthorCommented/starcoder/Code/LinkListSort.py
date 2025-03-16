
import java.util.*;

class Main:
    def isSorted(self, array, option):
        # Take user input for the linked list and sorting option
        n = int(input())

        inputArray = [int(x) for x in input().split()]

        sortingChoice = int(input())

        sortedArray = sorted(inputArray)

        start = self.createLinkedList(inputArray)

        # Choice is choosed as any number from 1 to 3 (So the linked list will be
        # sorted by Merge sort technique/Insertion sort technique/Heap sort technique)
        if sortingChoice == 1:
            start = self.sortByMergeSort(start)
        elif sortingChoice == 2:
            start = self.sortByInsertionSort(start)
        elif sortingChoice == 3:
            start = self.sortByHeapSort(start)
        else:
            print("Invalid choice!")
            return False

        # Convert sorted linked list back to array
        resultArray = self.convertLinkedListToArray(start)

        # Compare sorted linked list result with expected sorted array
        return sortedArray == resultArray

    def createLinkedList(self, array):
        start = None
        prev = None
        for value in array:
            node = Node()
            node.val = value
            if start == None:
                start = node
            else:
                prev.next = node
            prev = node
        return start

    def convertLinkedListToArray(self, head):
        list = []
        while head!= None:
            list.append(head.val)
            head = head.next
        return list

    def sortByMergeSort(self, head):
        if head == None or head.next == None:
            return head
        count = self.countNodes(head)
        array = self.convertToArray(head, count)
        self.mergeSort(array, 0, count - 1)
        return self.convertToList(array)

    def sortByInsertionSort(self, head):
        if head == None or head.next == None:
            return head
        count = self.countNodes(head)
        array = self.convertToArray(head, count)
        self.insertionSort(array)
        return self.convertToList(array)

    def sortByHeapSort(self, head):
        if head == None or head.next == None:
            return head
        count = self.countNodes(head)
        array = self.convertToArray(head, count)
        self.heapSort(array)
        return self.convertToList(array)

    def countNodes(self, head):
        count = 0
        while head!= None:
            count += 1
            head = head.next
        return count

    def convertToArray(self, head, size):
        array = [0] * size
        index = 0
        while head!= None:
            array[index] = head.val
            index += 1
            head = head.next
        return array

    def convertToList(self, array):
        head = None
        tail = None
        for value in array:
            node = Node()
            node.val = value
            if head == None:
                head = node
            else:
                tail.next = node
            tail = node
        return head

    def mergeSort(self, array, left, right):
        if left < right:
            mid = (left + right) // 2
            self.mergeSort(array, left, mid)
            self.mergeSort(array, mid + 1, right)
            self.merge(array, left, mid, right)

    def merge(self, array, left, mid, right):
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

    def main(self):
        # This is the entry point for the program.
        if self.isSorted([], 0):
            print("LinkedList is sorted correctly.")
        else:
            print("LinkedList is not sorted correctly.")

class Node:
    def __init__(self):
        self.val = 0
        self.next = None

# 