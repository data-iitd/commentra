import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.Scanner;
class Main:
    def __init__(self):
        self.stack = []

    def push(self, value):
        self.stack.append(value)
        print("Pushed " + str(value))

    def pop(self):
        if self.isEmpty():
            raise EmptyStackException()
        removed = self.stack.pop()
        print("Popped " + str(removed))
        return removed

    def peek(self):
        if self.isEmpty():
            raise EmptyStackException()
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
    scanner = Scanner(System.in)
    stack = Main()
    operations = scanner.nextInt()
    for i in range(operations):
        choice = scanner.nextInt()
        if choice == 1:
            value = scanner.nextInt()
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
    scanner.close()

