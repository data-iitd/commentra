
# Method to check if the linked list is sorted based on user input
def is_sorted(array, option):
    # Read the number of elements in the array
    n = int(input())
    input_array = list(map(int, input().split()))
    
    # Read the sorting choice from user input
    sorting_choice = int(input())
    
    # Create a copy of the input array and sort it using built-in sort
    sorted_array = sorted(input_array)
    
    # Create a linked list from the input array
    start = create_linked_list(input_array)
    
    # Sort the linked list based on the user's choice of sorting algorithm
    if sorting_choice == 1:
        start = sort_by_merge_sort(start)
    elif sorting_choice == 2:
        start = sort_by_insertion_sort(start)
    elif sorting_choice == 3:
        start = sort_by_heap_sort(start)
    else:
        # Handle invalid sorting choice
        print("Invalid choice!")
        return False
    
    # Convert the sorted linked list back to an array
    result_array = convert_linked_list_to_array(start)
    
    # Compare the sorted linked list array with the built-in sorted array
    return result_array == sorted_array

# Method to create a linked list from an array
def create_linked_list(array):
    start = None
    prev = None
    
    # Iterate through the array and create nodes for the linked list
    for value in array:
        fresh = Node()
        fresh.val = value
        if start is None:
            start = fresh # Set the start node if it's the first element
        else:
            prev.next = fresh # Link the previous node to the current node
        prev = fresh # Move the previous pointer to the current node
    return start # Return the head of the linked list

# Method to convert a linked list back to an array
def convert_linked_list_to_array(head):
    list = []
    
    # Traverse the linked list and add values to the list
    while head is not None:
        list.append(head.val)
        head = head.next
    return list # Return the filled array

# Class to represent each element in the linked list
class Node:
    def __init__(self):
        self.val = 0
        self.next = None

# Class to implement merge sort on a linked list
class Task:
    def sort_by_merge_sort(self, head):
        # Base case: if the list is empty or has one element
        if head is None or head.next is None:
            return head
        
        # Count the number of nodes in the linked list
        count = count_nodes(head)
        
        # Convert the linked list to an array for sorting
        array = convert_to_array(head, count)
        
        # Perform merge sort on the array
        merge_sort(array, 0, count - 1)
        
        # Convert the sorted array back to a linked list
        return convert_to_linked_list(array)

# Method to count the number of nodes in the linked list
def count_nodes(head):
    count = 0
    while head is not None:
        count += 1
        head = head.next
    return count # Return the total count of nodes

# Method to convert a linked list to an array
def convert_to_array(head, size):
    array = [0] * size
    index = 0
    
    # Traverse the linked list and fill the array
    while head is not None:
        array[index] = head.val
        head = head.next
        index += 1
    return array # Return the filled array

# Method to convert an array back to a linked list
def convert_to_linked_list(array):
    head = None
    tail = None
    
    # Create nodes for each element in the array
    for value in array:
        fresh = Node()
        fresh.val = value
        if head is None:
            head = fresh # Set the head if it's the first node
        else:
            tail.next = fresh # Link the previous tail to the current node
        tail = fresh # Move the tail pointer to the current node
    return head # Return the head of the new linked list

# Method to perform merge sort on an array
def merge_sort(array, left, right):
    if left < right:
        mid = (left + right) // 2 # Find the middle index
        merge_sort(array, left, mid) # Sort the left half
        merge_sort(array, mid + 1, right) # Sort the right half
        merge(array, left, mid, right) # Merge the two halves

# Method to merge two sorted halves of an array
def merge(array, left, mid, right):
    temp = [0] * (right - left + 1) # Temporary array for merging
    i = left
    j = mid + 1
    k = 0
    
    # Merge the two halves into the temporary array
    while i <= mid and j <= right:
        if array[i] <= array[j]:
            temp[k] = array[i] # Add smaller element to temp
            i += 1
        else:
            temp[k] = array[j] # Add smaller element to temp
            j += 1
        k += 1
    
    # Copy remaining elements from the left half, if any
    while i <= mid:
        temp[k] = array[i]
        i += 1
        k += 1
    
    # Copy remaining elements from the right half, if any
    while j <= right:
        temp[k] = array[j]
        j += 1
        k += 1
    
    # Copy the sorted elements back to the original array
    for i in range(left, right + 1):
        array[i] = temp[i - left]

# Class to implement insertion sort on a linked list
class Task1:
    def sort_by_insertion_sort(self, head):
        # Base case: if the list is empty or has one element
        if head is None or head.next is None:
            return head
        
        # Count the number of nodes in the linked list
        count = count_nodes(head)
        
        # Convert the linked list to an array for sorting
        array = convert_to_array(head, count)
        
        # Perform insertion sort on the array
        insertion_sort(array)
        
        # Convert the sorted array back to a linked list
        return convert_to_linked_list(array)

# Method to perform insertion sort on an array
def insertion_sort(array):
    for i in range(1, len(array)):
        key = array[i] # Current element to be inserted
        j = i - 1
        # Shift elements of array that are greater than key
        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key # Insert the key at the correct position

# Class to implement heap sort on a linked list
class Task2:
    def sort_by_heap_sort(self, head):
        # Base case: if the list is empty or has one element
        if head is None or head.next is None:
            return head
        
        # Count the number of nodes in the linked list
        count = count_nodes(head)
        
        # Convert the linked list to an array for sorting
        array = convert_to_array(head, count)
        
        # Perform heap sort on the array
        heap_sort(array)
        
        # Convert the sorted array back to a linked list
        return convert_to_linked_list(array)

# Method to perform heap sort on an array
def heap_sort(array):
    n = len(array)
    
    # Build a max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(array, n, i)
    
    # Extract elements from the heap one by one
    for i in range(n - 1, -1, -1):
        # Move the current root to the end
        temp = array[0]
        array[0] = array[i]
        array[i] = temp
        # Call heapify on the reduced heap
        heapify(array, i, 0)

# Method to maintain the heap property
def heapify(array, n, i):
    largest = i # Initialize largest as root
    left = 2 * i + 1 # Left child index
    right = 2 * i + 2 # Right child index
    
    # If left child is larger than root
    if left < n and array[left] > array[largest]:
        largest = left
    # If right child is larger than largest so far
    if right < n and array[right] > array[largest]:
        largest = right
    
    # If largest is not root, swap and continue heapifying
    if largest != i:
        array[i], array[largest] = array[largest], array[i]
        heapify(array, n, largest) # Recursively heapify the affected sub-tree

# Main method to execute the program
def main():
    # Check if the linked list is sorted and print the result
    if is_sorted(None, 0):
        print("LinkedList is sorted correctly.")
    else:
        print("LinkedList is not sorted correctly.")

# End of code
if __name__ == "__main__":
    main()


Translate the above Python code to C++ and end with comment "