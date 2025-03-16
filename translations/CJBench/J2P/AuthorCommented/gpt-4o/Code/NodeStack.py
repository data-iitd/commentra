class Node:
    """Node class representing each element in the stack."""
    def __init__(self, data):
        self.data = data
        self.previous = None


class Stack:
    """A stack implementation using linked nodes, supporting unlimited size."""
    
    def __init__(self):
        """Constructs an empty Stack."""
        self.head = None
        self.size = 0

    def push(self, item):
        """Pushes an item onto the stack."""
        new_node = Node(item)
        new_node.previous = self.head
        self.head = new_node
        self.size += 1

    def pop(self):
        """Removes and returns the item at the top of the stack."""
        if self.is_empty():
            raise Exception("Cannot pop from an empty stack.")
        data = self.head.data
        self.head = self.head.previous
        self.size -= 1
        return data

    def peek(self):
        """Returns the item at the top of the stack without removing it."""
        if self.is_empty():
            raise Exception("Cannot peek from an empty stack.")
        return self.head.data

    def is_empty(self):
        """Checks whether the stack is empty."""
        return self.head is None

    def get_size(self):
        """Returns the number of elements currently in the stack."""
        return self.size


def main():
    stack = Stack()
    print("Enter commands (push <value>, pop, peek, size, isEmpty, exit):")
    
    while True:
        command = input().strip()
        if command.lower() == "exit":
            break

        try:
            parts = command.split()
            if parts[0] == "push":
                if len(parts) < 2:
                    print("Error: Missing value for push")
                    continue
                value = int(parts[1])
                stack.push(value)
                print(f"Pushed: {value}")

            elif parts[0] == "pop":
                print(f"Popped: {stack.pop()}")

            elif parts[0] == "peek":
                print(f"Top: {stack.peek()}")

            elif parts[0] == "size":
                print(f"Size: {stack.get_size()}")

            elif parts[0] == "isEmpty":
                print(f"Is empty: {stack.is_empty()}")

            else:
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e}")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
