class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedListStack:
    def __init__(self):
        self.head = None  # Top of the stack
        self.size = 0  # Number of elements in the stack

    def push(self, x):
        new_node = Node(x)
        new_node.next = self.head
        self.head = new_node
        self.size += 1

    def pop(self):
        if self.size == 0:
            raise IndexError("Empty stack. Nothing to pop")
        value = self.head.data
        self.head = self.head.next
        self.size -= 1
        return value

    def peek(self):
        if self.size == 0:
            raise IndexError("Empty stack. Nothing to peek")
        return self.head.data

    def is_empty(self):
        return self.size == 0

    def get_size(self):
        return self.size

    def make_empty(self):
        self.head = None
        self.size = 0


def main():
    stack = LinkedListStack()
    operations = int(input("Enter number of operations: "))

    for _ in range(operations):
        choice = int(input("Enter choice (1: Push, 2: Pop, 3: Peek, 4: Size, 5: Is Empty, 6: Make Empty): "))
        if choice == 1:  # Push
            value = int(input("Enter value to push: "))
            stack.push(value)
            print(f"Pushed {value}")
        elif choice == 2:  # Pop
            try:
                popped = stack.pop()
                print(f"Popped {popped}")
            except IndexError as e:
                print(e)
        elif choice == 3:  # Peek
            try:
                peeked = stack.peek()
                print(f"Top element: {peeked}")
            except IndexError as e:
                print(e)
        elif choice == 4:  # Size
            print(f"Stack size: {stack.get_size()}")
        elif choice == 5:  # Is Empty
            print(f"Is stack empty? {stack.is_empty()}")
        elif choice == 6:  # Make Empty
            stack.make_empty()
            print("Stack cleared.")
        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
