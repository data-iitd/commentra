import sys

class Node:  # Defining the Node class to represent each node in the linked list
    def __init__(self, val=0):  # Constructor to initialize the node
        self.val = val  # Defining the value of the node
        self.next = None  # Defining the next pointer of the node

class Task:  # Defining the Task class to implement merge sort algorithm for the linked list
    def sort_by_merge_sort(self, head):  # Implementing the merge sort algorithm for the linked list
        # Implementation goes here
        pass

    # Helper methods for merge sort algorithm
    def count_nodes(self, head):  # Count the number of nodes in the linked list
        # Implementation goes here
        pass

    def convert_to_array(self, head, size):  # Convert linked list to array
        # Implementation goes here
        pass

    def convert_to_list(self, array):  # Convert array to linked list
        # Implementation goes here
        pass

    def merge_sort(self, array, left, right):  # Merge sort algorithm
        # Implementation goes here
        pass

    def merge(self, array, left, mid, right):  # Merge two halves
        # Implementation goes here
        pass

class Task1:  # Defining the Task1 class to implement insertion sort algorithm for the linked list
    def sort_by_insertion_sort(self, head):  # Implementing the insertion sort algorithm for the linked list
        # Implementation goes here
        pass

    # Helper methods for insertion sort algorithm
    def insertion_sort(self, array):  # Insertion sort algorithm
        # Implementation goes here
        pass

    def count_nodes(self, head):  # Count the number of nodes in the linked list
        # Implementation goes here
        pass

    def convert_to_array(self, head, size):  # Convert linked list to array
        # Implementation goes here
        pass

    def convert_to_list(self, array):  # Convert array to linked list
        # Implementation goes here
        pass

class Task2:  # Defining the Task2 class to implement heap sort algorithm for the linked list
    def sort_by_heap_sort(self, head):  # Implementing the heap sort algorithm for the linked list
        # Implementation goes here
        pass

    # Helper methods for heap sort algorithm
    def heap_sort(self, array):  # Heap sort algorithm
        # Implementation goes here
        pass

    def heapify(self, array, n, i):  # Heapify a subtree
        # Implementation goes here
        pass

    def count_nodes(self, head):  # Count the number of nodes in the linked list
        # Implementation goes here
        pass

    def convert_to_array(self, head, size):  # Convert linked list to array
        # Implementation goes here
        pass

    def convert_to_list(self, array):  # Convert array to linked list
        # Implementation goes here
        pass

def create_linked_list(array):  # Defining the create_linked_list function to create a linked list from an integer array
    start = None  # Initializing the start node to None
    prev = None  # Initializing the previous node to None
    for value in array:  # Iterating through the array to create new nodes and add them to the linked list
        fresh = Node(value)  # Creating a new Node object
        if start is None:  # If the linked list is empty
            start = fresh  # Setting the start node to the new node
        else:
            prev.next = fresh  # Setting the next pointer of the previous node to the new node
        prev = fresh  # Setting the previous node to the new node
    return start  # Returning the start node of the linked list

def convert_linked_list_to_array(head):  # Defining the convert_linked_list_to_array function to convert a linked list to an integer array
    result = []  # Creating an empty list to store the integer values of the linked list
    ptr = head  # Initializing a pointer to the head of the linked list
    while ptr is not None:  # Iterating through the linked list
        result.append(ptr.val)  # Adding each value to the list
        ptr = ptr.next  # Moving to the next node
    return result  # Returning the list of values

def is_sorted(array, option):  # Defining the is_sorted function that takes an integer array and an option as arguments
    n = int(input())  # Reading the number of elements in the array from the console
    input_array = list(map(int, input().split()))  # Reading and storing the input elements
    sorting_choice = int(input())  # Reading the sorting choice from the console
    sorted_array = sorted(input_array)  # Sorting the input array using the sorted function
    start = create_linked_list(input_array)  # Creating a linked list from the input array
    if sorting_choice == 1:
        start = Task().sort_by_merge_sort(start)  # Sorting the linked list using merge sort
    elif sorting_choice == 2:
        start = Task1().sort_by_insertion_sort(start)  # Sorting the linked list using insertion sort
    elif sorting_choice == 3:
        start = Task2().sort_by_heap_sort(start)  # Sorting the linked list using heap sort
    else:
        print("Invalid choice!")  # Printing an error message if the user enters an invalid choice
        return False  # Returning False to indicate that the linked list is not sorted
    result_array = convert_linked_list_to_array(start)  # Converting the sorted linked list to an array
    return result_array == sorted_array  # Comparing the sorted linked list array with the sorted input array and returning the result

def main():  # Defining the main function to test the is_sorted function
    if is_sorted([], 0):  # Calling the is_sorted function with an empty array and an invalid choice
        print("LinkedList is sorted correctly.")  # Printing a message if the linked list is sorted correctly
    else:
        print("LinkedList is not sorted correctly.")  # Printing a message if the linked list is not sorted correctly

if __name__ == "__main__":  # Checking if the script is being run directly
    main()  # Calling the main function

# <END-OF-CODE>
