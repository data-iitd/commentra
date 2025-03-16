
class LinkedListStack:
    def __init__(self):
        self.head = None
        self.size = 0

    def push(self, x):
        new_node = Node(x)
        new_node.next = self.head
        self.head = new_node
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

class NoSuchElementException(Exception):
    pass

# Test the LinkedListStack class
stack = LinkedListStack()

# Test push()
stack.push(1)
stack.push(2)
stack.push(3)
print(stack.getSize())

# Test pop()
print(stack.pop())
print(stack.pop())
print(stack.pop())
print(stack.getSize())

# Test peek()
stack.push(4)
print(stack.peek())
print(stack.peek())
print(stack.pop())
print(stack.peek())

# Test isEmpty()
print(stack.isEmpty())
stack.push(5)
print(stack.isEmpty())

# Test makeEmpty()
stack.makeEmpty()
print(stack.getSize())
print(stack.isEmpty())

# Test NoSuchElementException
try:
    stack.pop()
except NoSuchElementException as e:
    print(e)

# Test NoSuchElementException
try:
    stack.peek()
except NoSuchElementException as e:
    print(e)

# 