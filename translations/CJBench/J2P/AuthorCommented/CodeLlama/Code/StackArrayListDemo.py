
class EmptyStackException(Exception):
    pass


class Stack:
    def __init__(self):
        self.stack = []

    def push(self, value):
        self.stack.append(value)
        print("Pushed", value)

    def pop(self):
        if self.isEmpty():
            raise EmptyStackException("Stack is empty. Cannot pop.")
        removed = self.stack.pop()
        print("Popped", removed)
        return removed

    def peek(self):
        if self.isEmpty():
            raise EmptyStackException("Stack is empty. Cannot peek.")
        top = self.stack[-1]
        print("Top element:", top)
        return top

    def isEmpty(self):
        return len(self.stack) == 0

    def makeEmpty(self):
        self.stack = []
        print("Stack cleared.")

    def size(self):
        size = len(self.stack)
        print("Stack size:", size)
        return size


def main():
    scanner = input
    stack = Stack()

    operations = int(input())

    for i in range(operations):
        choice = int(input())

        if choice == 1:
            value = int(input())
            stack.push(value)
        elif choice == 2:
            try:
                stack.pop()
            except EmptyStackException as e:
                print(e)
        elif choice == 3:
            try:
                stack.peek()
            except EmptyStackException as e:
                print(e)
        elif choice == 4:
            stack.size()
        elif choice == 5:
            stack.makeEmpty()
        elif choice == 6:
            print("Is stack empty?", stack.isEmpty())
        else:
            print("Invalid choice. Try again.")


if __name__ == "__main__":
    main()

