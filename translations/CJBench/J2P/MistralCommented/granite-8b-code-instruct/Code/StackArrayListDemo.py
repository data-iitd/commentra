

class Stack:
    def __init__(self):
        self.stack = []
        print("Created a new stack.")

    def push(self, value):
        self.stack.append(value)
        print("Pushed", value)

    def pop(self):
        if self.is_empty():
            raise Exception("Stack is empty. Cannot pop.")
        removed = self.stack.pop()
        return removed

    def peek(self):
        if self.is_empty():
            raise Exception("Stack is empty. Cannot peek.")
        top = self.stack[-1]
        return top

    def is_empty(self):
        return len(self.stack) == 0

    def make_empty(self):
        self.stack.clear()
        print("Stack cleared.")

    def size(self):
        size = len(self.stack)
        print("Stack size:", size)
        return size

if __name__ == "__main__":
    operations = int(input("Number of operations: "))
    stack = Stack()

    for i in range(operations):
        choice = int(input("Enter choice: "))

        if choice == 1:
            value = int(input("Enter value: "))
            stack.push(value)
        elif choice == 2:
            try:
                stack.pop()
            except Exception as e:
                print(e)
        elif choice == 3:
            try:
                stack.peek()
            except Exception as e:
                print(e)
        elif choice == 4:
            stack.size()
        elif choice == 5:
            stack.make_empty()
        elif choice == 6:
            print("Is stack empty? ", stack.is_empty())
        else:
            print("Invalid choice. Try again.")

