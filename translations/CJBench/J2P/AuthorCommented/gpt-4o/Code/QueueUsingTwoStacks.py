class QueueUsingStacks:
    def __init__(self):
        self.in_stack = []
        self.out_stack = []

    def insert(self, x):
        """Inserts an element at the rear of the queue."""
        self.in_stack.append(x)

    def remove(self):
        """Removes an element from the front of the queue."""
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
        if self.out_stack:
            return self.out_stack.pop()
        return "Queue is empty"

    def peek_front(self):
        """Peeks at the element from the front of the queue."""
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
        if self.out_stack:
            return self.out_stack[-1]
        return "Queue is empty"

    def peek_back(self):
        """Peeks at the element from the back of the queue."""
        if self.in_stack:
            return self.in_stack[-1]
        return "Queue is empty"

    def is_empty(self):
        """Returns true if the queue is empty."""
        return len(self.in_stack) == 0 and len(self.out_stack) == 0


if __name__ == "__main__":
    import sys

    queue = QueueUsingStacks()
    operations = int(sys.stdin.readline().strip())

    for _ in range(operations):
        command = sys.stdin.readline().strip().split()
        if command[0] == "INSERT":
            queue.insert(int(command[1]))
        elif command[0] == "REMOVE":
            print(queue.remove())
        elif command[0] == "PEEK_FRONT":
            print(queue.peek_front())
        elif command[0] == "PEEK_BACK":
            print(queue.peek_back())
        elif command[0] == "IS_EMPTY":
            print(queue.is_empty())
        else:
            print("Invalid command")

# <END-OF-CODE>
