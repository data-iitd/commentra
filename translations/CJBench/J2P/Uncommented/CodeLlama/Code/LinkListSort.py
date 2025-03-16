
import sys

def is_sorted(array, option):
    n = int(input())
    input_array = list(map(int, input().split()))
    sorting_choice = int(input())
    sorted_array = sorted(input_array)
    start = create_linked_list(input_array)
    if sorting_choice == 1:
        start = sort_by_merge_sort(start)
    elif sorting_choice == 2:
        start = sort_by_insertion_sort(start)
    elif sorting_choice == 3:
        start = sort_by_heap_sort(start)
    else:
        print("Invalid choice!")
        return False
    result_array = convert_linked_list_to_array(start)
    return result_array == sorted_array

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

def convert_linked_list_to_array(head):
    list = []
    for ptr in range(head, None):
        list.append(ptr.val)
    return list

def sort_by_merge_sort(head):
    if head is None or head.next is None:
        return head
    count = count_nodes(head)
    array = convert_to_array(head, count)
    merge_sort(array, 0, count - 1)
    return convert_to_linked_list(array)

def count_nodes(head):
    count = 0
    while head is not None:
        count += 1
        head = head.next
    return count

def convert_to_array(head, size):
    array = [0] * size
    index = 0
    while head is not None:
        array[index] = head.val
        index += 1
        head = head.next
    return array

def convert_to_linked_list(array):
    start = None
    tail = None
    for value in array:
        fresh = Node(value)
        if start is None:
            start = fresh
        else:
            tail.next = fresh
        tail = fresh
    return start

def merge_sort(array, left, right):
    if left < right:
        mid = (left + right) // 2
        merge_sort(array, left, mid)
        merge_sort(array, mid + 1, right)
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

def sort_by_insertion_sort(head):
    if head is None or head.next is None:
        return head
    count = count_nodes(head)
    array = convert_to_array(head, count)
    insertion_sort(array)
    return convert_to_linked_list(array)

def insertion_sort(array):
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1
        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key

def sort_by_heap_sort(head):
    if head is None or head.next is None:
        return head
    count = count_nodes(head)
    array = convert_to_array(head, count)
    heap_sort(array)
    return convert_to_linked_list(array)

def heap_sort(array):
    n = len(array)
    for i in range(n // 2 - 1, -1, -1):
        heapify(array, n, i)
    for i in range(n - 1, -1, -1):
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
    if largest != i:
        temp = array[i]
        array[i] = array[largest]
        array[largest] = temp
        heapify(array, n, largest)

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

if is_sorted([], 0):
    print("LinkedList is sorted correctly.")
else:
    print("LinkedList is not sorted correctly.")

# 