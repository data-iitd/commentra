import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.Queue;
import java.util.Scanner;
class Main:
    def __init__(self):
        self.mainQueue = LinkedList()
        self.tempQueue = LinkedList()
    def push(self, item):
        self.tempQueue.add(item)
        while not self.mainQueue.isEmpty():
            self.tempQueue.add(self.mainQueue.remove())
        swap = self.mainQueue
        self.mainQueue = self.tempQueue
        self.tempQueue = swap
    def pop(self):
        if self.mainQueue.isEmpty():
            raise NoSuchElementException("Stack is empty")
        return self.mainQueue.remove()
    def peek(self):
        if self.mainQueue.isEmpty():
            return None
        return self.mainQueue.peek()
    def isEmpty(self):
        return self.mainQueue.isEmpty()
    def size(self):
        return self.mainQueue.size()
if __name__ == "__main__":
    stack = Main()
    scanner = Scanner(System.in)
    n = scanner.nextInt()
    for i in range(n):
        operation = scanner.next()
        if operation == "push":
            value = scanner.nextInt()
            stack.push(value)
            print("Pushed: " + str(value))
        elif operation == "pop":
            try:
                print("Popped: " + str(stack.pop()))
            except NoSuchElementException as e:
                print("Error: " + e.getMessage())
        elif operation == "peek":
            top = stack.peek()
            if top!= None:
                print("Top element: " + str(top))
            else:
                print("Stack is empty")
        elif operation == "isEmpty":
            print("Is stack empty? " + str(stack.isEmpty()))
        elif operation == "size":
            print("Stack size: " + str(stack.size()))
        else:
            print("Invalid operation")
    scanner.close()
