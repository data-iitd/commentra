
class EmptyStackException(Exception):
    pass

class Stack:
    def __init__(self):
        self.stack = []
        print("Created a new stack.")

    def push(self, value):
        self.stack.append(value)
        print("Pushed " + str(value))

    def pop(self):
        if self.isEmpty():
            raise EmptyStackException
            print("Stack is empty. Cannot pop.")
        else:
            return self.stack.pop()

    def peek(self):
        if self.isEmpty():
            raise EmptyStackException
            print("Stack is empty. Cannot peek.")
        else:
            return self.stack[-1]

    def isEmpty(self):
        return len(self.stack) == 0
        print("Is stack empty? " + str(len(self.stack) == 0))

    def makeEmpty(self):
        self.stack = []
        print("Stack cleared.")

    def size(self):
        return len(self.stack)
        print("Stack size: " + str(len(self.stack)))

if __name__ == "__main__":
    # Initialize a Scanner to read input from the console
    scanner = input()

    # Create a new instance of the Stack class to represent the stack
    stack = Stack()

    # Read the number of operations from the console
    operations = int(input())
    print("Number of operations: " + str(operations))

    # Process each operation
    for i in range(operations):
        choice = int(input())

        # Switch on the choice and perform the corresponding operation
        if choice == 1:
            value = int(input())
            stack.push(value)
        elif choice == 2:
            try:
                stack.pop()
            except EmptyStackException:
                print("Stack is empty. Cannot pop.")
        elif choice == 3:
            try:
                stack.peek()
            except EmptyStackException:
                print("Stack is empty. Cannot peek.")
        elif choice == 4:
            stack.size()
        elif choice == 5:
            stack.makeEmpty()
        elif choice == 6:
            print("Is stack empty? " + str(stack.isEmpty()))
        else:
            print("Invalid choice. Try again.")

    # Close the Scanner
    scanner.close()

