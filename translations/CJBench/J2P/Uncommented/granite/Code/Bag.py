

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
    def __next__(self):
        if self.currentElement is None:
            raise StopIteration("No more elements in the bag.")
        element = self.currentElement.content
        self.currentElement = self.currentElement.nextElement
        return element
if __name__ == "__main__":
    import sys
    scanner = iter(sys.stdin.read().splitlines())
    n = int(next(scanner))
    print("Enter elements:")
    bag = Main()
    for i in range(n):
        element = next(scanner)
        bag.add(element)
    print("Main contents:")
    for element in bag:
        print(element)
    checkElement = next(scanner)
    print("Contains " + checkElement + ": " + str(bag.contains(checkElement)))
    print("Main size: " + str(bag.size()))
    print("Is bag empty: " + str(bag.isEmpty()))
