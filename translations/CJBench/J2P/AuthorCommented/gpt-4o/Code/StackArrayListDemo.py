class Stack:
    """
    A stack implementation backed by a list, offering dynamic resizing
    and LIFO (Last-In-First-Out) behavior.

    The stack grows dynamically as elements are added, and elements are removed
    in reverse order of their addition.
    """

    def __init__(self):
        """Constructs an empty stack."""
        self.stack = []

    def push(self, value):
        """Adds an element to the top of the stack."""
        self.stack.append(value)
        print(f"Pushed {value}")

    def pop(self):
        """Removes and returns the element from the top of the stack."""
        if self.is_empty():
            raise IndexError("pop from empty stack")
        removed = self.stack.pop()
        print(f"Popped {removed}")
        return removed

    def peek(self):
        """Returns the element at the top of the stack without removing it."""
        if self.is_empty():
            raise IndexError("peek from empty stack")
        top = self.stack[-1]
        print(f"Top element: {top}")
        return top

    def is_empty(self):
        """Checks if the stack is empty."""
        return len(self.stack) == 0

    def make_empty(self):
        """Empties the stack, removing all elements."""
        self.stack.clear()
        print("Stack cleared.")

    def size(self):
        """Returns the number of elements in the stack."""
        size = len(self.stack)
        print(f"Stack size: {size}")
        return size


def main():
    stack = Stack()
    operations = int(input("Enter number of operations: "))

    for _ in range(operations):
        choice = int(input("Enter choice (1-6): "))

        if choice == 1:
            value = int(input("Enter value to push: "))
            stack.push(value)
        elif choice == 2:
            try:
                stack.pop()
            except IndexError:
                print("Stack is empty. Cannot pop.")
        elif choice == 3:
            try:
                stack.peek()
            except IndexError:
                print("Stack is empty. Cannot peek.")
        elif choice == 4:
            stack.size()
        elif choice == 5:
            stack.make_empty()
        elif choice == 6:
            print("Is stack empty?", stack.is_empty())
        else:
            print("Invalid choice. Try again.")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
