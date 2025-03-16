

class Node:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Task:
    def sortByMergeSort(self, head: Node) -> Node:
        if not head or not head.next:
            return head
        count = self.countNodes(head)
        array = self.convertToArray(head, count)
        self.mergeSort(array, 0, count - 1)
        return self.convertToList(array)

    def countNodes(self, head: Node) -> int:
        count = 0
        while head:
            count += 1
            head = head.next
        return count

    def convertToArray(self, head: Node, size: int) -> list:
        array = []
        index = 0
        while head:
            array.append(head.val)
            head = head.next
        return array

    def convertToList(self, array: list) -> Node:
        head = None
        tail = None
        for value in array:
            node = Node(value)
            if not head:
                head = node
            else:
                tail.next = node
            tail = node
        return head

    def mergeSort(self, array: list, left: int, right: int) -> None:
        if left < right:
            mid = (left + right) // 2
            self.mergeSort(array, left, mid)
            self.mergeSort(array, mid + 1, right)
            self.merge(array, left, mid, right)

    def merge(self, array: list, left: int, mid: int, right: int) -> None:
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

class Task1:
    def sortByInsertionSort(self, head: Node) -> Node:
        if not head or not head.next:
            return head
        count = self.countNodes(head)
        array = self.convertToArray(head, count)
        self.insertionSort(array)
        return self.convertToList(array)

    def insertionSort(self, array: list) -> None:
        for i in range(1, len(array)):
            key = array[i]
            j = i - 1
            while j >= 0 and array[j] > key:
                array[j + 1] = array[j]
                j -= 1
            array[j + 1] = key

    def countNodes(self, head: Node) -> int:
        count = 0
        while head:
            count += 1
            head = head.next
        return count

    def convertToArray(self, head: Node, size: int) -> list:
        array = []
        index = 0
        while head:
            array.append(head.val)
            head = head.next
        return array

    def convertToList(self, array: list) -> Node:
        head = None
        tail = None
        for value in array:
            node = Node(value)
            if not head:
                head = node
            else:
                tail.next = node
            tail = node
        return head

class Task2:
    def sortByHeapSort(self, head: Node) -> Node:
        if not head or not head.next:
            return head
        count = self.countNodes(head)
        array = self.convertToArray(head, count)
        self.heapSort(array)
        return self.convertToList(array)

    def heapSort(self, array: list) -> None:
        n = len(array)
        for i in range(n // 2 - 1, -1, -1):
            self.heapify(array, n, i)
        for i in range(n - 1, -1, -1):
            array[i], array[0] = array[0], array[i]
            self.heapify(array, i, 0)

    def heapify(self, array: list, n: int, i: int) -> None:
        largest = i
        left = 2 * i + 1
        right = 2 * i + 2
        if left < n and array[left] > array[largest]:
            largest = left
        if right < n and array[right] > array[largest]:
            largest = right
        if largest!= i:
            array[i], array[largest] = array[largest], array[i]
            self.heapify(array, n, largest)

    def countNodes(self, head: Node) -> int:
        count = 0
        while head:
            count += 1
            head = head.next
        return count

    def convertToArray(self, head: Node, size: int) -> list:
        array = []
        index = 0
        while head:
            array.append(head.val)
            head = head.next
        return array

    def convertToList(self, array: list) -> Node:
        head = None
        tail = None
        for value in array:
            node = Node(value)
            if not head:
                head = node
            else:
                tail.next = node
            tail = node
        return head

