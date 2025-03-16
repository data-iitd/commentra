
class Main:
    def __init__(self):
        self.firstElement = None
        self.size = 0
    def isEmpty(self):
        return self.size == 0
    def size(self):
        return self.size
    def add(self, element):
        newNode = Node()
        newNode.content = element
        newNode.nextElement = self.firstElement
        self.firstElement = newNode
        self.size += 1
    def contains(self, element):
        for value in self:
            if value == element:
                return True
        return False
    def __iter__(self):
        return ListIterator(self.firstElement)
    class Node:
        def __init__(self):
            self.content = None
            self.nextElement = None
    class ListIterator:
        def __init__(self, firstElement):
            self.currentElement = firstElement
        def hasNext(self):
            return self.currentElement!= None
        def next(self):
            if not self.hasNext():
                raise NoSuchElementException("No more elements in the bag.")
            element = self.currentElement.content
            self.currentElement = self.currentElement.nextElement
            return element

