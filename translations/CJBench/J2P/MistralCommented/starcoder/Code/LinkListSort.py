import java.util.*; // Importing the utility class Scanner from the java.util package

class Main: # Defining the Main class
    @staticmethod # Defining the isSorted method that takes an integer array and an option as arguments
    def isSorted(array, option):
        sc = Scanner(System.in); # Creating a new Scanner object to read input from the console
        n = sc.nextInt(); # Reading the number of elements in the array from the console
        inputArray = [0] * n; # Creating an integer array of size n to store the input elements
        for i in range(n): # Iterating through the array to read and store the input elements
            inputArray[i] = sc.nextInt();
        sortingChoice = sc.nextInt(); # Reading the sorting choice from the console
        sortedArray = inputArray.copy(); # Creating a copy of the input array to store the sorted elements
        sortedArray.sort(); # Sorting the copied array using the sorted method
        start = Main.createLinkedList(inputArray); # Creating a linked list from the input array using the createLinkedList method
        switch (sortingChoice): # Switching the sorting choice based on the user input
            case 1:
                start = Task().sortByMergeSort(start); # Calling the sortByMergeSort method of the Task class to sort the linked list using merge sort
                break;
            case 2:
                start = Task1().sortByInsertionSort(start); # Calling the sortByInsertionSort method of the Task1 class to sort the linked list using insertion sort
                break;
            case 3:
                start = Task2().sortByHeapSort(start); # Calling the sortByHeapSort method of the Task2 class to sort the linked list using heap sort
                break;
            default:
                print("Invalid choice!"); # Printing an error message if the user enters an invalid choice
                return False; # Returning false to indicate that the linked list is not sorted
        resultArray = Main.convertLinkedListToArray(start); # Converting the sorted linked list to an array using the convertLinkedListToArray method
        return sortedArray == resultArray; # Comparing the sorted linked list array with the sorted input array using the == operator and returning the result

    # Defining the createLinkedList method to create a linked list from an integer array
    @staticmethod
    def createLinkedList(array):
        start = None; # Initializing the start node to null
        prev = None; # Initializing the previous node to null
        for value in array: # Iterating through the array to create new nodes and add them to the linked list
            fresh = Node(); # Creating a new Node object
            fresh.val = value; # Setting the value of the new node
            if start == None: # If the linked list is empty
                start = fresh; # Setting the start node to the new node
            else:
                prev.next = fresh; # Setting the next pointer of the previous node to the new node
            prev = fresh; # Setting the previous node to the new node
        return start; # Returning the start node of the linked list

    # Defining the convertLinkedListToArray method to convert a linked list to an integer array
    @staticmethod
    def convertLinkedListToArray(head):
        list = []; # Creating an empty list to store the integer values of the linked list
        for ptr in head: # Iterating through the linked list to add each value to the list
            list.append(ptr.val);
        return list; # Converting the list to an integer array

# Defining the Node class to represent each node in the linked list
class Node:
    val = 0; # Defining the value of the node
    next = None; # Defining the next pointer of the node

# Defining the Task class to implement merge sort algorithm for the linked list
class Task:
    # Implementing the merge sort algorithm for the linked list
    def sortByMergeSort(self, head):
        # Implementation goes here
    # Helper methods for merge sort algorithm
    def countNodes(self, head):
        # Implementation goes here
    def convertToArray(self, head, size):
        # Implementation goes here
    def convertToList(self, array):
        # Implementation goes here
    def mergeSort(self, array, left, right):
        # Implementation goes here
    def merge(self, array, left, mid, right):
        # Implementation goes here

# Defining the Task1 class to implement insertion sort algorithm for the linked list
class Task1:
    # Implementing the insertion sort algorithm for the linked list
    def sortByInsertionSort(self, head):
        # Implementation goes here
    # Helper methods for insertion sort algorithm
    def insertionSort(self, array):
        # Implementation goes here
    def countNodes(self, head):
        # Implementation goes here
    def convertToArray(self, head, size):
        # Implementation goes here
    def convertToList(self, array):
        # Implementation goes here

# Defining the Task2 class to implement heap sort algorithm for the linked list
class Task2:
    # Implementing the heap sort algorithm for the linked list
    def sortByHeapSort(self, head):
        # Implementation goes here
    # Helper methods for heap sort algorithm
    def heapSort(self, array):
        # Implementation goes here
    def heapify(self, array, n, i):
        # Implementation goes here
    def countNodes(self, head):
        # Implementation goes here
    def convertToArray(self, head, size):
        # Implementation goes here
    def convertToList(self, array):
        # Implementation goes here

if __name__ == '__main__': # Defining the main method to test the isSorted method with an empty array
    if Main.isSorted([], 0): # Calling the isSorted method with an empty array and an invalid choice to test the error handling
        print("LinkedList is sorted correctly."); # Printing a message if the linked list is sorted correctly
    else:
        print("LinkedList is not sorted correctly."); # Printing a message if the linked list is not sorted correctly

