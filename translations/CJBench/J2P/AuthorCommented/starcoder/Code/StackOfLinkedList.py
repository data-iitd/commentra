
# A stack implementation using a singly linked list.
#
# This class provides methods to push, pop, and peek elements in a Last-In-First-Out (LIFO) manner.
# It keeps track of the number of elements in the stack and allows checking if the stack is empty.
#
# This implementation does not allow null elements to be pushed onto the stack.

class Main:

    def main(self):
        stack = LinkedListStack()
        scanner = Scanner(System.in)

        operations = scanner.nextInt()

        for i in range(operations):
            choice = scanner.nextInt()
            if choice == 1: # Push
                value = scanner.nextInt()
                stack.push(value)
                print("Pushed " + value)
            elif choice == 2: # Pop
                try:
                    popped = stack.pop()
                    print("Popped " + popped)
                except NoSuchElementException as e:
                    print(e.getMessage())
            elif choice == 3: # Peek
                try:
                    peeked = stack.peek()
                    print("Top element: " + peeked)
                except NoSuchElementException as e:
                    print(e.getMessage())
            elif choice == 4: # Size
                print("Stack size: " + stack.getSize())
            elif choice == 5: # Is Empty
                print("Is stack empty? " + stack.isEmpty())
            elif choice == 6: # Make Empty
                stack.makeEmpty()
                print("Stack cleared.")
            else:
                print("Invalid choice.")
        scanner.close()

class LinkedListStack:

    def __init__(self):
        self.head = None
        self.size = 0

    def push(self, x):
        newNode = Node(x)
        newNode.next = self.head
        self.head = newNode
        self.size += 1

    def pop(self):
        if self.size == 0:
            raise NoSuchElementException("Empty stack. Nothing to pop")
        value = self.head.data
        self.head = self.head.next
        self.size -= 1
        return value

    def peek(self):
        if self.size == 0:
            raise NoSuchElementException("Empty stack. Nothing to peek")
        return self.head.data

    def isEmpty(self):
        return self.size == 0

    def getSize(self):
        return self.size

    def makeEmpty(self):
        self.head = None
        self.size = 0

class Node:

    def __init__(self, data):
        self.data = data
        self.next = None

# 