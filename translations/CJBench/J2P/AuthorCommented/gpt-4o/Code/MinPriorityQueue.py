class MinHeap:
    """
    A MinHeap is a specialized data structure that maintains the
    min-heap property, where the smallest element has the highest priority.

    Functions:
    - insert(int key): Inserts a new key into the queue.
    - delete(): Removes and returns the highest priority value (the minimum).
    - peek(): Returns the highest priority value without removing it.
    - is_empty(): Checks if the queue is empty.
    - is_full(): Checks if the queue is full.
    - heap_sort(): Sorts the elements in ascending order.
    - print_heap(): Prints the current elements in the queue.
    """

    def __init__(self, capacity):
        """
        Initializes a new MinHeap with a specified capacity.

        :param capacity: the maximum number of elements the queue can hold
        """
        self.capacity = capacity
        self.size = 0
        self.heap = [0] * (capacity + 1)

    def insert(self, key):
        """
        Inserts a new key into the min-priority queue.

        :param key: the value to be inserted
        """
        if self.is_full():
            raise Exception("MinHeap is full. Cannot insert new element.")
        self.size += 1
        self.heap[self.size] = key
        k = self.size
        while k > 1:
            if self.heap[k] < self.heap[k // 2]:
                self.heap[k], self.heap[k // 2] = self.heap[k // 2], self.heap[k]
            k //= 2

    def peek(self):
        """
        Retrieves the highest priority value (the minimum) without removing it.

        :return: the minimum value in the queue
        :raises Exception: if the queue is empty
        """
        if self.is_empty():
            raise Exception("MinHeap is empty. Cannot peek.")
        return self.heap[1]

    def is_empty(self):
        """
        Checks whether the queue is empty.

        :return: true if the queue is empty, false otherwise
        """
        return self.size == 0

    def is_full(self):
        """
        Checks whether the queue is full.

        :return: true if the queue is full, false otherwise
        """
        return self.size == self.capacity

    def print_heap(self):
        """ Prints the elements of the queue. """
        for i in range(1, self.size + 1):
            print(self.heap[i], end=" ")
        print()

    def heap_sort(self):
        """ Sorts the elements in the queue using heap sort. """
        sorted_elements = []
        while not self.is_empty():
            sorted_elements.append(self.delete())
        return sorted_elements

    def sink(self):
        """ Reorders the heap after a deletion to maintain the heap property. """
        k = 1
        while 2 * k <= self.size:
            min_index = k
            if 2 * k <= self.size and self.heap[2 * k] < self.heap[min_index]:
                min_index = 2 * k
            if 2 * k + 1 <= self.size and self.heap[2 * k + 1] < self.heap[min_index]:
                min_index = 2 * k + 1

            if min_index == k:
                break

            self.heap[k], self.heap[min_index] = self.heap[min_index], self.heap[k]
            k = min_index

    def delete(self):
        """
        Deletes and returns the highest priority value (the minimum) from the queue.

        :return: the minimum value from the queue
        :raises Exception: if the queue is empty
        """
        if self.is_empty():
            raise Exception("MinHeap is empty. Cannot delete.")
        min_value = self.heap[1]
        self.heap[1] = self.heap[self.size]
        self.size -= 1
        self.sink()
        return min_value


def main():
    capacity = int(input("Enter the capacity of the MinHeap: "))
    heap = MinHeap(capacity)

    print("Enter commands (insert <value>, delete, peek, print, is_empty, exit):")
    while True:
        command = input().strip().split()
        if not command:
            continue

        try:
            if command[0] == "insert":
                value = int(command[1])
                heap.insert(value)
                print(f"Inserted: {value}")

            elif command[0] == "delete":
                print(f"Deleted: {heap.delete()}")

            elif command[0] == "peek":
                print(f"Peek: {heap.peek()}")

            elif command[0] == "print":
                print("Heap: ", end="")
                heap.print_heap()

            elif command[0] == "is_empty":
                print(f"Is Empty: {heap.is_empty()}")

            elif command[0] == "exit":
                print("Exiting...")
                break

            else:
                print(f"Unknown command: {command[0]}")
        except Exception as e:
            print(f"Error: {e}")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
