class Main:
    DEFAULT_CAPACITY = 10

    def __init__(self, capacity=DEFAULT_CAPACITY):
        if capacity <= 0:
            raise ValueError("Main capacity must be greater than 0")
        self.max_size = capacity
        self.queue_array = [None] * capacity
        self.front = 0
        self.rear = -1
        self.n_items = 0

    def insert(self, element):
        if self.is_full():
            return False
        self.rear = (self.rear + 1) % self.max_size
        self.queue_array[self.rear] = element
        self.n_items += 1
        return True

    def remove(self):
        if self.is_empty():
            raise IndexError("Main is empty, cannot remove element")
        removed_element = self.queue_array[self.front]
        self.queue_array[self.front] = None
        self.front = (self.front + 1) % self.max_size
        self.n_items -= 1
        return removed_element

    def peek_front(self):
        if self.is_empty():
            raise IndexError("Main is empty, cannot peek front")
        return self.queue_array[self.front]

    def peek_rear(self):
        if self.is_empty():
            raise IndexError("Main is empty, cannot peek rear")
        return self.queue_array[self.rear]

    def is_empty(self):
        return self.n_items == 0

    def is_full(self):
        return self.n_items == self.max_size

    def get_size(self):
        return self.n_items

    def __str__(self):
        if self.is_empty():
            return "[]"
        elements = []
        for i in range(self.n_items):
            index = (self.front + i) % self.max_size
            elements.append(str(self.queue_array[index]))
        return "[" + ", ".join(elements) + "]"

    @staticmethod
    def main():
        import sys
        input = sys.stdin.read
        data = input().split()
        size = int(data[0])
        queue = Main(size)
        i = 1
        while i < len(data):
            command = data[i].lower()
            if command == "exit":
                break
            try:
                if command == "insert":
                    value = int(data[i + 1])
                    if queue.insert(value):
                        print(f"Inserted: {value}")
                    else:
                        print("Main is full")
                elif command == "remove":
                    print(f"Removed: {queue.remove()}")
                elif command == "peekfront":
                    print(f"Front: {queue.peek_front()}")
                elif command == "peekrear":
                    print(f"Rear: {queue.peek_rear()}")
                elif command == "getsize":
                    print(f"Size: {queue.get_size()}")
                elif command == "isempty":
                    print(f"Is empty: {queue.is_empty()}")
                elif command == "print":
                    print(f"Main: {queue}")
                else:
                    print(f"Unknown command: {command}")
                i += 1
            except Exception as e:
                print(f"Error: {e}")
            i += 1


Main.main()
