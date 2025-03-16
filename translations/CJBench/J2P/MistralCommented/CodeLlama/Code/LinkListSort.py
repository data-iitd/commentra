
import array // Importing the array module
import sys // Importing the sys module

class Node: // Defining the Node class
    def __init__(self, val=0, next=None): // Defining the constructor
        self.val = val // Initializing the value of the node
        self.next = next // Initializing the next pointer of the node

class Task: // Defining the Task class
    def sortByMergeSort(self, head): // Defining the sortByMergeSort method
        # Implementation goes here
        return head

    def countNodes(self, head): // Defining the countNodes method
        # Implementation goes here
        return 0

    def convertToArray(self, head, size): // Defining the convertToArray method
        # Implementation goes here
        return array.array("i", [])

    def convertToList(self, array): // Defining the convertToList method
        # Implementation goes here
        return None

    def mergeSort(self, array, left, right): // Defining the mergeSort method
        # Implementation goes here

    def merge(self, array, left, mid, right): // Defining the merge method
        # Implementation goes here

class Task1: // Defining the Task1 class
    def sortByInsertionSort(self, head): // Defining the sortByInsertionSort method
        # Implementation goes here
        return head

    def insertionSort(self, array): // Defining the insertionSort method
        # Implementation goes here

    def countNodes(self, head): // Defining the countNodes method
        # Implementation goes here
        return 0

    def convertToArray(self, head, size): // Defining the convertToArray method
        # Implementation goes here
        return array.array("i", [])

    def convertToList(self, array): // Defining the convertToList method
        # Implementation goes here
        return None

class Task2: // Defining the Task2 class
    def sortByHeapSort(self, head): // Defining the sortByHeapSort method
        # Implementation goes here
        return head

    def heapSort(self, array): // Defining the heapSort method
        # Implementation goes here

    def heapify(self, array, n, i): // Defining the heapify method
        # Implementation goes here

    def countNodes(self, head): // Defining the countNodes method
        # Implementation goes here
        return 0

    def convertToArray(self, head, size): // Defining the convertToArray method
        # Implementation goes here
        return array.array("i", [])

    def convertToList(self, array): // Defining the convertToList method
        # Implementation goes here
        return None

def isSorted(array, option): // Defining the isSorted function
    n = int(input()) // Reading the number of elements in the array from the console
    inputArray = array.array("i", [int(x) for x in input().split()]) // Reading and storing the input elements in an array
    sortingChoice = int(input()) // Reading the sorting choice from the console
    sortedArray = sorted(inputArray) // Sorting the input array using the sorted function
    start = createLinkedList(inputArray) // Creating a linked list from the input array using the createLinkedList function
    if sortingChoice == 1:
        start = Task().sortByMergeSort(start) // Calling the sortByMergeSort method of the Task class to sort the linked list using merge sort
    elif sortingChoice == 2:
        start = Task1().sortByInsertionSort(start) // Calling the sortByInsertionSort method of the Task1 class to sort the linked list using insertion sort
    elif sortingChoice == 3:
        start = Task2().sortByHeapSort(start) // Calling the sortByHeapSort method of the Task2 class to sort the linked list using heap sort
    else:
        print("Invalid choice!") // Printing an error message if the user enters an invalid choice
        return False // Returning false to indicate that the linked list is not sorted
    resultArray = convertLinkedListToArray(start) // Converting the sorted linked list to an array using the convertLinkedListToArray function
    return resultArray == sortedArray // Comparing the sorted linked list array with the sorted input array using the == operator and returning the result

def createLinkedList(array): // Defining the createLinkedList function
    start = None // Initializing the start node to None
    prev = None // Initializing the previous node to None
    for value in array: // Iterating through the array to create new nodes and add them to the linked list
        fresh = Node(value) // Creating a new Node object
        if start is None: // If the linked list is empty
            start = fresh // Setting the start node to the new node
        else:
            prev.next = fresh // Setting the next pointer of the previous node to the new node
        prev = fresh // Setting the previous node to the new node
    return start // Returning the start node of the linked list

def convertLinkedListToArray(head): // Defining the convertLinkedListToArray function
    list = [] // Creating an empty list to store the integer values of the linked list
    for ptr in head: // Iterating through the linked list to add each value to the list
        list.append(ptr.val)
    return list // Returning the list

if __name__ == "__main__": // Checking if the file is being run directly
    if isSorted(array.array("i", []), 0): // Calling the isSorted function with an empty array and an invalid choice to test the error handling
        print("LinkedList is sorted correctly.") // Printing a message if the linked list is sorted correctly
    else:
        print("LinkedList is not sorted correctly.") // Printing a message if the linked list is not sorted correctly
    