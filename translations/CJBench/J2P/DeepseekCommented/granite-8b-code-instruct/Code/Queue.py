
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
            raise RuntimeError("Main is empty, cannot remove element")
        removed_element = self.queue_array[self.front]
        self.queue_array[self.front] = None
        self.front = (self.front + 1) % self.max_size
        self.n_items -= 1
        return removed_element

    def peek_front(self):
        if self.is_empty():
            raise RuntimeError("Main is empty, cannot peek front")
        return self.queue_array[self.front]

    def peek_rear(self):
        if self.is_empty():
            raise RuntimeError("Main is empty, cannot peek rear")
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
        result = "["
        for i in range(self.n_items):
            index = (self.front + i) % self.max_size
            result += str(self.queue_array[index]) + ", "
        result = result[:-2] + "]"
        return result

if __name__ == "__main__":
    import sys
    size = int(input())
    queue = Main(size)
    while True:
        line = input().strip()
        if line.lower() == "exit":
            break
        try:
            parts = line.split()
            if parts[0].lower() == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                    continue
                value = int(parts[1])
                if queue.insert(value):
                    print("Inserted:", value)
                else:
                    print("Main is full")
            elif parts[0].lower() == "remove":
                print("Removed:", queue.remove())
            elif parts[0].lower() == "peekfront":
                print("Front:", queue.peek_front())
            elif parts[0].lower() == "peekrear":
                print("Rear:", queue.peek_rear())
            elif parts[0].lower() == "getsize":
                print("Size:", queue.get_size())
            elif parts[0].lower() == "isempty":
                print("Is empty:", queue.is_empty())
            elif parts[0].lower() == "print":
                print("Main:", queue)
            else:
                print("Unknown command:", parts[0])
        except Exception as e:
            print("Error:", e)

