
import sys

def is_sorted(array, option):
    n = int(input())
    input_array = list(map(int, input().split()))
    sorting_choice = int(input())
    
    sorted_array = sorted(input_array)
    
    start = create_linked_list(input_array)
    
    if sorting_choice == 1:
        start = merge_sort(start)
    elif sorting_choice == 2:
        start = insertion_sort(start)
    elif sorting_choice == 3:
        start = heap_sort(start)
    else:
        print("Invalid choice!")
        sys.exit(1)
    
    result_array = convert_linked_list_to_array(start)
    
    return result_array == sorted_array

def create_linked_list(array):
    start = None
    prev = None
    
    for value in array:
        fresh = Node()
        fresh.val = value
        if start is None:
            start = fresh  # Set the start node if it's the first element
        else:
            prev.next = fresh  # Link the previous node to the current node
        prev = fresh  # Move the previous pointer to the current node
    
    return start  # Return the head of the linked list

def convert_linked_list_to_array(head):
    array = []
    
    while head is not None:
        array.append(head.val)
        head = head.next
    
    return array  # Return the converted array

def merge_sort(head):
    # Base case: if the list is empty or has one element
    if head is None or head.next is None:
        return head
    
    # Count the number of nodes in the linked list
    count = count_nodes(head)
    
    # Convert the linked list to an array for sorting
    array = convert_linked_list_to_array(head, count)
    
    # Perform merge sort on the array
    merge_sort_helper(array, 0, count - 1)
    
    # Convert the sorted array back to a linked list
    return convert_to_linked_list(array)

def merge_sort_helper(array, left, right):
    if left < right:
        mid = (left + right) // 2  # Find the middle index
        merge_sort_helper(array, left, mid)  # Sort the left half
        merge_sort_helper(array, mid + 1, right)  # Sort the right half
        merge(array, left, mid, right)  # Merge the two halves

def merge(array, left, mid, right):
    temp = [0] * (right - left + 1)  # Temporary array for merging
    i = left
    j = mid + 1
    k = 0
    
    # Merge the two halves into the temporary array
    while i <= mid and j <= right:
        if array[i] <= array[j]:
            temp[k] = array[i]  # Add smaller element to temp
            i += 1
        else:
            temp[k] = array[j]  # Add smaller element to temp
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

def insertion_sort(head):
    # Base case: if the list is empty or has one element
    if head is None or head.next is None:
        return head
    
    # Count the number of nodes in the linked list
    count = count_nodes(head)
    
    # Convert the linked list to an array for sorting
    array = convert_linked_list_to_array(head, count)
    
    # Perform insertion sort on the array
    insertion_sort_helper(array)
    
    # Convert the sorted array back to a linked list
    return convert_to_linked_list(array)

def insertion_sort_helper(array):
    for i in range(1, len(array)):
        key = array[i]  # Current element to be inserted
        j = i - 1
        # Shift elements of array that are greater than key
        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key  # Insert the key at the correct position

def count_nodes(head):
    count = 0
    while head is not None:
        count += 1
        head = head.next
    return count  # Return the total count of nodes

def convert_to_linked_list(array):
    head = None
    tail = None
    
    # Create nodes for each element in the array
    for value in array:
        fresh = Node()
        fresh.val = value
        if head is None:
            head = fresh  # Set the head if it's the first node
        else:
            tail.next = fresh  # Link the previous tail to the current node
        tail = fresh  # Move the tail pointer to the current node
    
    return head  # Return the head of the new linked list

def heap_sort(head):
    # Base case: if the list is empty or has one element
    if head is None or head.next is None:
        return head
    
    # Count the number of nodes in the linked list
    count = count_nodes(head)
    
    # Convert the linked list to an array for sorting
    array = convert_linked_list_to_array(head, count)
    
    # Perform heap sort on the array
    heap_sort_helper(array)
    
    # Convert the sorted array back to a linked list
    return convert_to_linked_list(array)

def heap_sort_helper(array):
    n = len(array)
    
    # Build a max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(array, n, i)
    
    # Extract elements from the heap one by one
    for i in range(n - 1, 0, -1):
        # Move the current root to the end
        array[0], array[i] = array[i], array[0]
        # Call heapify on the reduced heap
        heapify(array, i, 0)

def heapify(array, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    
    # If left child is larger than root
    if left < n and array[left] > array[largest]:
        largest = left
    
    # If right child is larger than largest so far
    if right < n and array[right] > array[largest]:
        largest = right
    
    # If largest is not root, swap and continue heapifying
    if largest!= i:
        array[i], array[largest] = array[largest], array[i]
        heapify(array, n, largest)  # Recursively heapify the affected sub-tree

def convert_linked_list_to_array(head, size=None):
    array = []
    
    while head is not None:
        array.append(head.val)
        head = head.next
    
    return array  # Return the converted array

def convert_to_linked_list(array):
    head = None
    tail = None
    
    # Create nodes for each element in the array
    for value in array:
        fresh = Node()
        fresh.val = value
        if head is None:
            head = fresh  # Set the head if it's the first node
        else:
            tail.next = fresh  # Link the previous tail to the current node
        tail = fresh  # Move the tail pointer to the current node
    
    return head  # Return the head of the new linked list

def main():
    if is_sorted([1, 2, 3, 4, 5], 1):
        print("LinkedList is sorted correctly.")
    else:
        print("LinkedList is not sorted correctly.")

if __name__ == "__main__":
    main()

