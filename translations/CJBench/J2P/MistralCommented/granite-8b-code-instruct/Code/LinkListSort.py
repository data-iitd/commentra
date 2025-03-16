
import sys

def is_sorted(array, option):
    n = int(input())
    input_array = list(map(int, input().split()))
    sorting_choice = int(input())
    sorted_array = sorted(input_array)
    start = create_linked_list(input_array)
    switcher = {
        1: lambda: new_task().sort_by_merge_sort(start),
        2: lambda: new_task1().sort_by_insertion_sort(start),
        3: lambda: new_task2().sort_by_heap_sort(start)
    }
    func = switcher.get(sorting_choice, lambda: "Invalid choice!")
    sorted_list = convert_linked_list_to_array(func())
    return sorted_list == sorted_array

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
    list = []
    for ptr in head:
        list.append(ptr.val)
    return list

class Node:
    def __init__(self):
        self.val = 0
        self.next = None

class Task:
    def sort_by_merge_sort(self, head):
        # Implementation goes here

class Task1:
    def sort_by_insertion_sort(self, head):
        # Implementation goes here

class Task2:
    def sort_by_heap_sort(self, head):
        # Implementation goes here

def new_task():
    return Task()

def new_task1():
    return Task1()

def new_task2():
    return Task2()

if __name__ == "__main__":
    if is_sorted([], 0):
        print("LinkedList is sorted correctly.")
    else:
        print("LinkedList is not sorted correctly.")

