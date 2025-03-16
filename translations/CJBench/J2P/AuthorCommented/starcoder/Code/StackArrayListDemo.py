
import sys

class Main:
    def __init__(self):
        self.stack = []

    def push(self, value):
        self.stack.append(value)
        print("Pushed " + str(value))

    def pop(self):
        if self.isEmpty():
            raise Exception("Stack is empty. Cannot pop.")
        removed = self.stack.pop()
        print("Popped " + str(removed))
        return removed

    def peek(self):
        if self.isEmpty():
            raise Exception("Stack is empty. Cannot peek.")
        top = self.stack[len(self.stack) - 1]
        print("Top element: " + str(top))
        return top

    def isEmpty(self):
        return len(self.stack) == 0

    def makeEmpty(self):
        self.stack = []
        print("Stack cleared.")

    def size(self):
        size = len(self.stack)
        print("Stack size: " + str(size))
        return size

if __name__ == "__main__":
    stack = Main()
    operations = int(sys.stdin.readline())

    for i in range(operations):
        choice = int(sys.stdin.readline())

        if choice == 1:
            value = int(sys.stdin.readline())
            stack.push(value)
        elif choice == 2:
            try:
                stack.pop()
            except Exception as e:
                print("Stack is empty. Cannot pop.")
        elif choice == 3:
            try:
                stack.peek()
            except Exception as e:
                print("Stack is empty. Cannot peek.")
        elif choice == 4:
            stack.size()
        elif choice == 5:
            stack.makeEmpty()
        elif choice == 6:
            print("Is stack empty? " + str(stack.isEmpty()))
        else:
            print("Invalid choice. Try again.")

