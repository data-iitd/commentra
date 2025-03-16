class Stack:
    def __init__(self):
        self.stack = []

    def push(self, value):
        self.stack.append(value)
        print(f"Pushed {value}")

    def pop(self):
        if self.is_empty():
            raise IndexError("Stack is empty. Cannot pop.")
        removed = self.stack.pop()
        print(f"Popped {removed}")
        return removed

    def peek(self):
        if self.is_empty():
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


def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    stack = Stack()
    operations = int(data[0])
    
    for i in range(1, operations + 1):
        choice = int(data[i])
        if choice == 1:
            value = int(data[i + 1])
            stack.push(value)
            i += 1
        elif choice == 2:
            try:
                stack.pop()
            except IndexError as e:
                print(e)
        elif choice == 3:
            try:
                stack.peek()
            except IndexError as e:
                print(e)
        elif choice == 4:
            stack.size()
        elif choice == 5:
            stack.make_empty()
        elif choice == 6:
            print(f"Is stack empty? {stack.is_empty()}")
        else:
            print("Invalid choice. Try again.")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
