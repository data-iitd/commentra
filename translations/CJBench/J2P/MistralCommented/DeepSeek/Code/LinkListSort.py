import sys

class Node:
    def __init__(self):
        self.val = 0
        self.next = None

def is_sorted(array, option):
    input_array = array.copy()
    sorting_choice = int(input())
    sorted_array = sorted(input_array)
    
    if sorting_choice == 1:
        start = create_linked_list(input_array)
        start = Task().sort_by_merge_sort(start)
    elif sorting_choice == 2:
        start = create_linked_list(input_array)
        start = Task1().sort_by_insertion_sort(start)
    elif sorting_choice == 3:
        start = create_linked_list(input_array)
        start = Task2().sort_by_heap_sort(start)
    else:
        print("Invalid choice!")
        return False
    
    result_array = convert_linked_list_to_array(start)
    return result_array == sorted_array

def create_linked_list(array):
    start = None
    prev = None
    for value in array:
        fresh = Node()
        fresh.val = value
        if start is None:
            start = fresh
        else:
            prev.next = fresh
        prev = fresh
    return start

def convert_linked_list_to_array(head):
    result = []
    ptr = head
    while ptr:
        result.append(ptr.val)
        ptr = ptr.next
    return result

class Task:
    def sort_by_merge_sort(self, head):
        # Implementation goes here
        pass
    
    def count_nodes(self, head):
        # Implementation goes here
        pass
    
    def convert_to_array(self, head, size):
        # Implementation goes here
        pass
    
    def convert_to_list(self, array):
        # Implementation goes here
        pass
    
    def merge_sort(self, array, left, right):
        # Implementation goes here
        pass
    
    def merge(self, array, left, mid, right):
        # Implementation goes here
        pass

class Task1:
    def sort_by_insertion_sort(self, head):
        # Implementation goes here
        pass
    
    def insertion_sort(self, array):
        # Implementation goes here
        pass
    
    def count_nodes(self, head):
        # Implementation goes here
        pass
    
    def convert_to_array(self, head, size):
        # Implementation goes here
        pass
    
    def convert_to_list(self, array):
        # Implementation goes here
        pass

class Task2:
    def sort_by_heap_sort(self, head):
        # Implementation goes here
        pass
    
    def heap_sort(self, array):
        # Implementation goes here
        pass
    
    def heapify(self, array, n, i):
        # Implementation goes here
        pass
    
    def count_nodes(self, head):
        # Implementation goes here
        pass
    
    def convert_to_array(self, head, size):
        # Implementation goes here
        pass
    
    def convert_to_list(self, array):
        # Implementation goes here
        pass

if __name__ == "__main__":
    if is_sorted([], 0):
        print("LinkedList is sorted correctly.")
    else:
        print("LinkedList is not sorted correctly.")
