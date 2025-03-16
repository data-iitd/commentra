

import queue

class Main:
    def __init__(self, capacity=10):
        if capacity <= 0:
            raise ValueError("Main capacity must be greater than 0")
        self.queue = queue.Queue(capacity)

    def insert(self, value):
        try:
            self.queue.put(value, block=False)
            return True
        except queue.Full:
            return False

    def remove(self):
        try:
            return self.queue.get(block=False)
        except queue.Empty:
            return None

    def peek_front(self):
        try:
            return self.queue.queue[0]
        except IndexError:
            return None

    def peek_rear(self):
        try:
            return self.queue.queue[-1]
        except IndexError:
            return None

    def is_empty(self):
        return self.queue.empty()

    def is_full(self):
        return self.queue.full()

    def get_size(self):
        return self.queue.qsize()

    def print_queue(self):
        print(self.queue.queue)

if __name__ == "__main__":
    size = int(input("Enter the size of the queue: "))
    queue = Main(size)

    while True:
        command = input("Enter a command (insert, remove, peekFront, peekRear, getSize, isEmpty, isFull, print, or exit): ")
        if command.lower() == "exit":
            break

        parts = command.split()
        if len(parts) == 0:
            continue

        if parts[0].lower() == "insert":
            if len(parts) < 2:
                print("Error: Missing value for insert")
                continue
            value = int(parts[1])
            if queue.insert(value):
                print(f"Inserted: {value}")
            else:
                print("Main is full")
        #... (other cases for "remove", "peekFront", "peekRear", "getSize", "isEmpty", and "print")

    print("