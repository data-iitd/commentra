
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

# 