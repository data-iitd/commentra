
import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.Scanner;

class Main:
    # Initialize an empty ArrayList to represent the stack
    def __init__(self):
        self.stack = ArrayList()
        print("Created a new stack.")

    def push(self, value):
        # Add the given value to the stack
        self.stack.add(value)
        print("Pushed " + value)

    def pop(self):
        # Check if the stack is empty before attempting to pop
        if self.isEmpty():
            raise EmptyStackException()
            print("Stack is empty. Cannot pop.")

        # Remove and return the last element of the stack
        removed = self.stack.remove(self.stack.size() - 1)
        return removed

    def peek(self):
        # Check if the stack is empty before attempting to peek
        if self.isEmpty():
            raise EmptyStackException()
            print("Stack is empty. Cannot peek.")

        # Get and return the last element of the stack without removing it
        top = self.stack.get(self.stack.size() - 1)
        return top

    def isEmpty(self):
        # Check if the stack is empty and print a message accordingly
        return self.stack.isEmpty()
        print("Is stack empty? " + self.stack.isEmpty())

    def makeEmpty(self):
        # Clear the stack and print a message
        self.stack.clear()
        print("Stack cleared.")

    def size(self):
        # Get the size of the stack and print a message
        size = self.stack.size()
        print("Stack size: " + size)
        return size

    def main(self):
        # Initialize a Scanner to read input from the console
        scanner = Scanner(System.in)

        # Create a new instance of the Main class to represent the stack
        stack = Main()

        # Read the number of operations from the console
        operations = scanner.nextInt()
        print("Number of operations: " + operations)

        # Process each operation
        for i in range(operations):
            choice = scanner.nextInt()

            # Switch on the choice and perform the corresponding operation
            if choice == 1:
                value = scanner.nextInt()
                stack.push(value)
            elif choice == 2:
                try:
                    stack.pop()
                except EmptyStackException e:
                    print("Stack is empty. Cannot pop.")
            elif choice == 3:
                try:
                    stack.peek()
                except EmptyStackException e:
                    print("Stack is empty. Cannot peek.")
            elif choice == 4:
                stack.size()
            elif choice == 5:
                stack.makeEmpty()
            elif choice == 6:
                print("Is stack empty? " + stack.isEmpty())
            else:
                print("Invalid choice. Try again.")

        # Close the Scanner
        scanner.close()

# 