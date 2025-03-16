import sys

class Node:
    def __init__(self, val=0):
        self.val = val
        self.next = None

def is_sorted(option):
    # Take user input for the linked list and sorting option
    n = int(input())
    input_array = list(map(int, input().split()))
    sorting_choice = int(input())

    sorted_array = sorted(input_array)
    start = create_linked_list(input_array)

    # Choice is chosen as any number from 1 to 3
    if sorting_choice == 1:
        start = Task().sort_by_merge_sort(start)
    elif sorting_choice == 2:
        start = Task1().sort_by_insertion_sort(start)
    elif sorting_choice == 3:
        start = Task2().sort_by_heap_sort(start)
    else:
        print("Invalid choice!")
        return False

    # Convert sorted linked list back to array
    result_array = convert_linked_list_to_array(start)

    # Compare sorted linked list result with expected sorted array
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
    result = []
    ptr = head
    while ptr is not None:
        result.append(ptr.val)
        ptr = ptr.next
    return result

class Task:
    def sort_by_merge_sort(self, head):
        if head is None or head.next is None:
            return head
        count = self.count_nodes(head)
        array = self.convert_to_array(head, count)
        self.merge_sort(array, 0, count - 1)
        return self.convert_to_list(array)

    def count_nodes(self, head):
        count = 0
        while head is not None:
            count += 1
            head = head.next
        return count

    def convert_to_array(self, head, size):
        array = [0] * size
        index = 0
        while head is not None:
            array[index] = head.val
            index += 1
            head = head.next
        return array

    def convert_to_list(self, array):
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

    def merge_sort(self, array, left, right):
        if left < right:
            mid = (left + right) // 2
            self.merge_sort(array, left, mid)
            self.merge_sort(array, mid + 1, right)
            self.merge(array, left, mid, right)

    def merge(self, array, left, mid, right):
        temp = []
        i = left
        j = mid + 1
        while i <= mid and j <= right:
            if array[i] <= array[j]:
                temp.append(array[i])
                i += 1
            else:
                temp.append(array[j])
                j += 1
        while i <= mid:
            temp.append(array[i])
            i += 1
        while j <= right:
            temp.append(array[j])
            j += 1
        for i in range(len(temp)):
            array[left + i] = temp[i]

class Task1:
    def sort_by_insertion_sort(self, head):
        if head is None or head.next is None:
            return head
        count = self.count_nodes(head)
        array = self.convert_to_array(head, count)
        self.insertion_sort(array)
        return self.convert_to_list(array)

    def insertion_sort(self, array):
        for i in range(1, len(array)):
            key = array[i]
            j = i - 1
            while j >= 0 and array[j] > key:
                array[j + 1] = array[j]
                j -= 1
            array[j + 1] = key

    def count_nodes(self, head):
        count = 0
        while head is not None:
            count += 1
            head = head.next
        return count

    def convert_to_array(self, head, size):
        array = [0] * size
        index = 0
        while head is not None:
            array[index] = head.val
            index += 1
            head = head.next
        return array

    def convert_to_list(self, array):
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

class Task2:
    def sort_by_heap_sort(self, head):
        if head is None or head.next is None:
            return head
        count = self.count_nodes(head)
        array = self.convert_to_array(head, count)
        self.heap_sort(array)
        return self.convert_to_list(array)

    def heap_sort(self, array):
        n = len(array)
        for i in range(n // 2 - 1, -1, -1):
            self.heapify(array, n, i)
        for i in range(n - 1, 0, -1):
            array[0], array[i] = array[i], array[0]
            self.heapify(array, i, 0)

    def heapify(self, array, n, i):
        largest = i
        left = 2 * i + 1
        right = 2 * i + 2
        if left < n and array[left] > array[largest]:
            largest = left
        if right < n and array[right] > array[largest]:
            largest = right
        if largest != i:
            array[i], array[largest] = array[largest], array[i]
            self.heapify(array, n, largest)

    def count_nodes(self, head):
        count = 0
        while head is not None:
            count += 1
            head = head.next
        return count

    def convert_to_array(self, head, size):
        array = [0] * size
        index = 0
        while head is not None:
            array[index] = head.val
            index += 1
            head = head.next
        return array

    def convert_to_list(self, array):
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

if __name__ == "__main__":
    if is_sorted(0):
        print("LinkedList is sorted correctly.")
    else:
        print("LinkedList is not sorted correctly.")

# <END-OF-CODE>
