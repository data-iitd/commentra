class Stack:
    def __init__(self):
        self.stack = []

    def push(self, value):
        self.stack.append(value)
        print(f"Pushed {value}")

    def pop(self):
        if self.is_empty():
            raise IndexError("pop from empty stack")
        removed = self.stack.pop()
        print(f"Popped {removed}")
        return removed

    def peek(self):
        if self.is_empty():
            raise IndexError("peek from empty stack")
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


def main():
    stack = Stack()
    import sys
    input = sys.stdin.read
    data = input().split()
    index = 0

    operations = int(data[index])
    index += 1

    for _ in range(operations):
        choice = int(data[index])
        index += 1
        if choice == 1:
            value = int(data[index])
            index += 1
            stack.push(value)
        elif choice == 2:
            try:
                stack.pop()
            except IndexError as e:
                print("Stack is empty. Cannot pop.")
        elif choice == 3:
            try:
                stack.peek()
            except IndexError as e:
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
