class Main:
    def __init__(self, capacity=10):
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


def main():
    import sys
    if len(sys.argv) > 1:
        size = int(sys.argv[1])
    else:
        print("Enter the size of the queue: ", end="")
        size = int(input().strip())

    queue = Main(size)

    print("Enter commands (insert <value>, remove, peekFront, peekRear, getSize, isEmpty, print, exit):")
    while True:
        command = input().strip()
        if command.lower() == "exit":
            break

        parts = command.split()
        try:
            if parts[0].lower() == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                    continue
                value = int(parts[1])
                if queue.insert(value):
                    print(f"Inserted: {value}")
                else:
                    print("Main is full")
            elif parts[0].lower() == "remove":
                print(f"Removed: {queue.remove()}")
            elif parts[0].lower() == "peekfront":
                print(f"Front: {queue.peek_front()}")
            elif parts[0].lower() == "peekrear":
                print(f"Rear: {queue.peek_rear()}")
            elif parts[0].lower() == "getsize":
                print(f"Size: {queue.get_size()}")
            elif parts[0].lower() == "isempty":
                print(f"Is empty: {queue.is_empty()}")
            elif parts[0].lower() == "print":
                print(f"Main: {queue}")
            else:
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e}")


if __name__ == "__main__":
    main()
