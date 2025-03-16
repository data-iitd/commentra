
class Stack:
    def __init__(self):
        self.stack = []

    def push(self, value):
        self.stack.append(value)
        print(f"Pushed {value}")

    def pop(self):
        if len(self.stack) == 0:
            raise IndexError("Stack is empty. Cannot pop.")
        removed = self.stack.pop()
        print(f"Popped {removed}")
        return removed

    def peek(self):
        if len(self.stack) == 0:
            raise IndexError("Stack is empty. Cannot peek.")
        top = self.stack[-1]
        print(f"Top element: {top}")
        return top

    def is_empty(self):
        return len(self.stack) == 0

    def make_empty(self):
        self.stack.clear()
        print("Stack cleared.")

    def size(self):
        size = len(self.stack)
        print(f"Stack size: {size}")
        return size

if __name__ == "__main__":
    import sys
    operations = int(input())
    stack = Stack()
    for _ in range(operations):
        choice = int(input())
        if choice == 1:
            value = int(input())
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
            print(f"Is stack empty? {stack.is_empty()}")
        else:
            print("Invalid choice. Try again.")

