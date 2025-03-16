class PriorityQueue:
    def __init__(self, size):
        self.max_size = size + 1
        self.queue_array = [0] * self.max_size
        self.n_items = 0

    def swim(self, pos):
        while pos > 1 and (self.queue_array[pos // 2] < self.queue_array[pos]):
            self.queue_array[pos], self.queue_array[pos // 2] = self.queue_array[pos // 2], self.queue_array[pos]
            pos = pos // 2

    def sink(self, pos):
        while 2 * pos <= self.n_items:
            current = 2 * pos
            if current < self.n_items and self.queue_array[current] < self.queue_array[current + 1]:
                current += 1
            if self.queue_array[pos] >= self.queue_array[current]:
                break
            self.queue_array[pos], self.queue_array[current] = self.queue_array[current], self.queue_array[pos]
            pos = current

    def insert(self, value):
        if self.is_full():
            raise RuntimeError("Queue is full")
        else:
            self.queue_array[self.n_items + 1] = value
            self.n_items += 1
            self.swim(self.n_items)

    def remove(self):
        if self.is_empty():
            raise RuntimeError("Queue is Empty")
        else:
            max_value = self.queue_array[1]
            self.queue_array[1], self.queue_array[self.n_items] = self.queue_array[self.n_items], self.queue_array[1]
            self.n_items -= 1
            self.queue_array[self.n_items + 1] = 0
            self.sink(1)
            return max_value

    def peek(self):
        if self.is_empty():
            raise RuntimeError("Queue is Empty")
        return self.queue_array[1]

    def is_empty(self):
        return self.n_items == 0

    def is_full(self):
        return self.n_items == self.max_size - 1

    def get_size(self):
        return self.n_items


def main():
    size = int(input("Enter the size of the priority queue: "))
    pq = PriorityQueue(size)
    print("Enter commands (insert <value>, remove, peek, getSize, isEmpty, exit):")
    while True:
        command = input().strip()
        if command.lower() == "exit":
            break
        try:
            parts = command.split()
            if parts[0] == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                    continue
                value = int(parts[1])
                pq.insert(value)
                print(f"Inserted: {value}")
            elif parts[0] == "remove":
                print(f"Removed: {pq.remove()}")
            elif parts[0] == "peek":
                print(f"Peek: {pq.peek()}")
            elif parts[0] == "getSize":
                print(f"Size: {pq.get_size()}")
            elif parts[0] == "isEmpty":
                print(f"Is empty: {pq.is_empty()}")
            else:
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e}")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
