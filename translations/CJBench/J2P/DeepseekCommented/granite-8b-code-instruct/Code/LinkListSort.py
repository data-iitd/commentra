
import sys

class Node:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def is_sorted(array, option):
    n = int(input())
    input_array = list(map(int, input().split()))
    sorting_choice = int(input())
    sorted_array = sorted(input_array)
    start = create_linked_list(input_array)
    switcher = {
        1: merge_sort(start),
        2: insertion_sort(start),
        3: heap_sort(start)
    }
    sorted_list = convert_linked_list_to_array(switcher.get(sorting_choice, None))
    return sorted_list == sorted_array

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
    array = []
    while head is not None:
        array.append(head.val)
        head = head.next
    return array

def merge_sort(head):
    if head is None or head.next is None:
        return head
    count = count_nodes(head)
    array = convert_to_array(head, count)
    merge_sort_helper(array, 0, count - 1)
    return convert_to_linked_list(array)

def merge_sort_helper(array, left, right):
    if left < right:
        mid = (left + right) // 2
        merge_sort_helper(array, left, mid)
        merge_sort_helper(array, mid + 1, right)
        merge(array, left, mid, right)

def merge(array, left, mid, right):
    temp = [0] * (right - left + 1)
    i, j, k = left, mid + 1, 0
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

def count_nodes(head):
    count = 0
    while head is not None:
        count += 1
        head = head.next
    return count

def convert_to_array(head, size):
    array = [0] * size
    i = 0
    while head is not None:
        array[i] = head.val
        head = head.next
        i += 1
    return array

def convert_to_linked_list(array):
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

def insertion_sort(head):
    if head is None or head.next is None:
        return head
    count = count_nodes(head)
    array = convert_to_array(head, count)
    insertion_sort_helper(array)
    return convert_to_linked_list(array)

def insertion_sort_helper(array):
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1
        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key

def heap_sort(head):
    if head is None or head.next is None:
        return head
    count = count_nodes(head)
    array = convert_to_array(head, count)
    heap_sort_helper(array)
    return convert_to_linked_list(array)

def heap_sort_helper(array):
    n = len(array)
    for i in range(n // 2 - 1, -1, -1):
        heapify(array, n, i)
    for i in range(n - 1, -1, -1):
        array[i], array[0] = array[0], array[i]
        heapify(array, i, 0)

def heapify(array, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    if left < n and array[left] > array[largest]:
        largest = left
    if right < n and array[right] > array[largest]:
        largest = right
    if largest!= i:
        array[i], array[largest] = array[largest], array[i]
        heapify(array, n, largest)

if __name__ == "__main__":
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    array = data[1:n + 1]
    option = data[n + 1]
    sorted_array = sorted(array)
    start = create_linked_list(array)
    switcher = {
        1: merge_sort(start),
        2: insertion_sort(start),
        3: heap_sort(start)
    }
    sorted_list = convert_linked_list_to_array(switcher.get(option, None))
    print("LinkedList is sorted correctly." if sorted_list == sorted_array else "LinkedList is not sorted correctly.")

