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

    def insert(self, value):
        if self.is_full():
            return False
        self.rear = (self.rear + 1) % self.max_size
        self.queue_array[self.rear] = value
        self.n_items += 1
        return True

    def remove(self):
        if self.is_empty():
            return None
        value = self.queue_array[self.front]
        self.front = (self.front + 1) % self.max_size
        self.n_items -= 1
        return value

    def peek_front(self):
        if self.is_empty():
            return None
        return self.queue_array[self.front]

    def peek_rear(self):
        if self.is_empty():
            return None
        return self.queue_array[self.rear]

    def is_empty(self):
        return self.n_items == 0

    def is_full(self):
        return self.n_items == self.max_size

    def get_size(self):
        return self.n_items

    def print_queue(self):
        if self.is_empty():
            print("Queue is empty")
            return
        index = self.front
        for _ in range(self.n_items):
            print(self.queue_array[index], end=" ")
            index = (index + 1) % self.max_size
        print()


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    size = int(data[0])
    queue = Main(size)

    i = 1
    while i < len(data):
        command = data[i].strip()
        i += 1

        if command == "exit":
            break

        if command == "insert":
            if i >= len(data):
                print("Error: Missing value for insert")
                continue
            value = int(data[i])
            i += 1
            if queue.insert(value):
                print(f"Inserted: {value}")
            else:
                print("Main is full")
        # ... (other cases for "remove", "peekFront", "peekRear", "getSize", "isEmpty", and "print")


if __name__ == "__main__":
    main()
