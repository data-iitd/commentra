class PriorityQueue:
    def __init__(self, size):
        self.max_size = size + 1  # +1 to accommodate the unused index 0
        self.queue_array = [0] * self.max_size  # Initialize the queue array
        self.n_items = 0  # Start with zero items

    def swim(self, pos):
        while pos > 1 and (self.queue_array[pos // 2] < self.queue_array[pos]):
            # Swap the current node with its parent
            self.queue_array[pos], self.queue_array[pos // 2] = self.queue_array[pos // 2], self.queue_array[pos]
            pos = pos // 2  # Move up to the parent's position

    def sink(self, pos):
        while 2 * pos <= self.n_items:
            current = 2 * pos  # Left child position
            # Check if the right child exists and is greater than the left child
            if current < self.n_items and self.queue_array[current] < self.queue_array[current + 1]:
                current += 1  # Move to the right child
            # If the current node is greater than or equal to the largest child, break
            if self.queue_array[pos] >= self.queue_array[current]:
                break
            # Swap the current node with the largest child
            self.queue_array[pos], self.queue_array[current] = self.queue_array[current], self.queue_array[pos]
            pos = current  # Move down to the child's position

    def insert(self, value):
        if self.is_full():
            raise RuntimeError("Queue is full")
        else:
            self.n_items += 1
            self.queue_array[self.n_items] = value
            self.swim(self.n_items)

    def remove(self):
        if self.is_empty():
            raise RuntimeError("Queue is Empty")
        else:
            max_value = self.queue_array[1]
            # Swap the root with the last element
            self.queue_array[1], self.queue_array[self.n_items] = self.queue_array[self.n_items], self.queue_array[1]
            self.n_items -= 1
            self.queue_array[self.n_items + 1] = 0  # Remove the last element
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
    import sys
    input = sys.stdin.read
    data = input().strip().splitlines()
    
    size = int(data[0])  # Read the size of the queue from input
    pq = PriorityQueue(size)  # Create a new priority queue

    for command in data[1:]:
        command = command.strip()  # Read the command
        if command.lower() == "exit":
            break  # Exit the loop if the command is "exit"
        try:
            parts = command.split()  # Split the command into parts
            if parts[0] == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                    continue
                value = int(parts[1])  # Parse the value to insert
                pq.insert(value)  # Insert the value into the queue
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
                print("Error: Unknown command")
        except Exception as e:
            print(f"Error: {e}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
