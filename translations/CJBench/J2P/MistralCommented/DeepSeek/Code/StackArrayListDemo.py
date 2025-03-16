class Main:
    def __init__(self):
        self.stack = []
        print("Created a new stack.")

    def push(self, value):
        self.stack.append(value)
        print(f"Pushed {value}")

    def pop(self):
        if self.is_empty():
            raise IndexError("Stack is empty. Cannot pop.")
        removed = self.stack.pop()
        return removed

    def peek(self):
        if self.is_empty():
            raise IndexError("Stack is empty. Cannot peek.")
        top = self.stack[-1]
        return top

    def is_empty(self):
        return not self.stack

    def make_empty(self):
        self.stack.clear()
        print("Stack cleared.")

    def size(self):
        size = len(self.stack)
        print(f"Stack size: {size}")
        return size

    @staticmethod
    def main():
        scanner = Scanner()
        stack = Main()
        operations = int(scanner.readline())
        print(f"Number of operations: {operations}")

        for _ in range(operations):
            choice = int(scanner.readline())

            try:
                if choice == 1:
                    value = int(scanner.readline())
                    stack.push(value)
                elif choice == 2:
                    stack.pop()
                elif choice == 3:
                    stack.peek()
                elif choice == 4:
                    stack.size()
                elif choice == 5:
                    stack.make_empty()
                elif choice == 6:
                    print("Is stack empty? " + str(stack.is_empty()))
                else:
                    print("Invalid choice. Try again.")
            except IndexError as e:
                print(str(e))

        scanner.close()

