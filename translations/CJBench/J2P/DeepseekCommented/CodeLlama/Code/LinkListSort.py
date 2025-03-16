import sys

def is_sorted(array, option):
    # Read the size of the array.
    n = int(input())
    input_array = list(map(int, input().split()))
    # Read the sorting choice.
    sorting_choice = int(input())
    # Create a copy of the input array to compare with the sorted result.
    sorted_array = sorted(input_array)
    # Create a linked list from the input array.
    start = create_linked_list(input_array)
    # Sort the linked list based on the user's choice.
    if sorting_choice == 1:
        start = sort_by_merge_sort(start)
    elif sorting_choice == 2:
        start = sort_by_insertion_sort(start)
    elif sorting_choice == 3:
        start = sort_by_heap_sort(start)
    else:
        print("Invalid choice!")
        return False
    # Convert the sorted linked list back to an array.
    result_array = convert_linked_list_to_array(start)
    # Compare the sorted linked list with the sorted array.
    return result_array == sorted_array

# Converts an array into a linked list.
def create_linked_list(array):
    start = None
    prev = None
    for value in array:
        fresh = Node(value)
        if start is None:
            start = fresh
        else:
            prev.next = fresh
        prev = fresh
    return start

# Converts a linked list back into an array.
def convert_linked_list_to_array(head):
    list = []
    for ptr in range(head):
        list.append(ptr.val)
    return list

# Node class definition for a linked list.
class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

# Task class implementing Merge Sort for linked lists.
class Task:
    def sort_by_merge_sort(self, head):
        if head is None or head.next is None:
            return head
        count = count_nodes(head)
        array = convert_to_array(head, count)
        merge_sort(array, 0, count - 1)
        return convert_to_linked_list(array)

    # Counts the number of nodes in the linked list.
    def count_nodes(self, head):
        count = 0
        while head is not None:
            count += 1
            head = head.next
        return count

    # Converts a linked list to an array.
    def convert_to_array(self, head, size):
        array = [0] * size
        index = 0
        while head is not None:
            array[index] = head.val
            head = head.next
            index += 1
        return array

    # Converts an array to a linked list.
    def convert_to_linked_list(self, array):
        head = None
        tail = None
        for value in array:
            node = Node(value)
            if head is None:
                head = node
            else:
                tail.next = node
            tail = node
        return head

    # Merge Sort implementation for arrays.
    def merge_sort(self, array, left, right):
        if left < right:
            mid = (left + right) // 2
            merge_sort(array, left, mid)
            merge_sort(array, mid + 1, right)
            merge(array, left, mid, right)

    # Merges two sorted subarrays.
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

# Task1 class implementing Insertion Sort for linked lists.
class Task1:
    def sort_by_insertion_sort(self, head):
        if head is None or head.next is None:
            return head
        count = count_nodes(head)
        array = convert_to_array(head, count)
        insertion_sort(array)
        return convert_to_linked_list(array)

    # Insertion Sort implementation for arrays.
    def insertion_sort(self, array):
        for i in range(1, len(array)):
            key = array[i]
            j = i - 1
            while j >= 0 and array[j] > key:
                array[j + 1] = array[j]
                j -= 1
            array[j + 1] = key

    # Counts the number of nodes in the linked list.
    def count_nodes(self, head):
        count = 0
        while head is not None:
            count += 1
            head = head.next
        return count

    # Converts a linked list to an array.
    def convert_to_array(self, head, size):
        array = [0] * size
        index = 0
        while head is not None:
            array[index] = head.val
            head = head.next
            index += 1
        return array

    # Converts an array to a linked list.
    def convert_to_linked_list(self, array):
        head = None
        tail = None
        for value in array:
            node = Node(value)
            if head is None:
                head = node
            else:
                tail.next = node
            tail = node
        return head

# Task2 class implementing Heap Sort for linked lists.
class Task2:
    def sort_by_heap_sort(self, head):
        if head is None or head.next is None:
            return head
        count = count_nodes(head)
        array = convert_to_array(head, count)
        heap_sort(array)
        return convert_to_linked_list(array)

    # Heap Sort implementation for arrays.
    def heap_sort(self, array):
        n = len(array)
        for i in range(n // 2 - 1, -1, -1):
            heapify(array, n, i)
        for i in range(n - 1, -1, -1):
            temp = array[0]
            array[0] = array[i]
            array[i] = temp
            heapify(array, i, 0)

    # Heapify implementation for arrays.
    def heapify(self, array, n, i):
        largest = i
        left = 2 * i + 1
        right = 2 * i + 2
        if left < n and array[left] > array[largest]:
            largest = left
        if right < n and array[right] > array[largest]:
            largest = right
        if largest != i:
            temp = array[i]
            array[i] = array[largest]
            array[largest] = temp
            heapify(array, n, largest)

    # Counts the number of nodes in the linked list.
    def count_nodes(self, head):
        count = 0
        while head is not None:
            count += 1
            head = head.next
        return count

    # Converts a linked list to an array.
    def convert_to_array(self, head, size):
        array = [0] * size
        index = 0
        while head is not None:
            array[index] = head.val
            head = head.next
            index += 1
        return array

    # Converts an array to a linked list.
    def convert_to_linked_list(self, array):
        head = None
        tail = None
        for value in array:
            node = Node(value)
            if head is None:
                head = node
            else:
                tail.next = node
            tail = node
        return head

# Main method where the program execution starts.
def main():
    if is_sorted(None, 0):
        print("LinkedList is sorted correctly.")
    else:
        print("LinkedList is not sorted correctly.")

# Driver code.
if __name__ == "__main__":
    main()
    print("