import sys

class Node:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def is_sorted(array, option):
    import sys
    input_data = sys.stdin.read().splitlines()
    n = int(input_data[0])
    input_array = list(map(int, input_data[1].split()))
    sorting_choice = int(input_data[2])
    
    sorted_array = sorted(input_array)
    
    start = create_linked_list(input_array)
    
    if sorting_choice == 1:
        start = Task().sort_by_merge_sort(start)
    elif sorting_choice == 2:
        start = Task1().sort_by_insertion_sort(start)
    elif sorting_choice == 3:
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
        node = Node(value)
        if start is None:
            start = node
        else:
            prev.next = node
        prev = node
    return start

def convert_linked_list_to_array(head):
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result

class Task:
    def sort_by_merge_sort(self, head):
        if not head or not head.next:
            return head
        
        count = count_nodes(head)
        array = convert_to_array(head, count)
        self.merge_sort(array, 0, count - 1)
        return convert_to_list(array)

    def count_nodes(self, head):
        count = 0
        while head:
            count += 1
            head = head.next
        return count

    def convert_to_array(self, head, size):
        array = []
        while head:
            array.append(head.val)
            head = head.next
        return array

    def convert_to_list(self, array):
        dummy = Node(0)
        tail = dummy
        for value in array:
            tail.next = Node(value)
            tail = tail.next
        return dummy.next

    def merge_sort(self, array, left, right):
        if left < right:
            mid = (left + right) // 2
            self.merge_sort(array, left, mid)
            self.merge_sort(array, mid + 1, right)
            self.merge(array, left, mid, right)

    def merge(self, array, left, mid, right):
        temp = []
        i, j = left, mid + 1
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
        for i in range(left, right + 1):
            array[i] = temp[i - left]

class Task1:
    def sort_by_insertion_sort(self, head):
        if not head or not head.next:
            return head
        
        count = count_nodes(head)
        array = convert_to_array(head, count)
        self.insertion_sort(array)
        return convert_to_list(array)

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
        while head:
            count += 1
            head = head.next
        return count

    def convert_to_array(self, head, size):
        array = []
        while head:
            array.append(head.val)
            head = head.next
        return array

    def convert_to_list(self, array):
        dummy = Node(0)
        tail = dummy
        for value in array:
            tail.next = Node(value)
            tail = tail.next
        return dummy.next

class Task2:
    def sort_by_heap_sort(self, head):
        if not head or not head.next:
            return head
        
        count = count_nodes(head)
        array = convert_to_array(head, count)
        self.heap_sort(array)
        return convert_to_list(array)

    def heap_sort(self, array):
        n = len(array)
        for i in range(n // 2 - 1, -1, -1):
            self.heapify(array, n, i)
        for i in range(n - 1, 0, -1):
            array[i], array[0] = array[0], array[i]
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
        while head:
            count += 1
            head = head.next
        return count

    def convert_to_array(self, head, size):
        array = []
        while head:
            array.append(head.val)
            head = head.next
        return array

    def convert_to_list(self, array):
        dummy = Node(0)
        tail = dummy
        for value in array:
            tail.next = Node(value)
            tail = tail.next
        return dummy.next

# Main function to execute the program
if __name__ == "__main__":
    if is_sorted([], 0):
        print("LinkedList is sorted correctly.")
    else:
        print("LinkedList is not sorted correctly.")
