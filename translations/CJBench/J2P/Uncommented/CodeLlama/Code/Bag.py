
class Node:
    def __init__(self, content, nextElement):
        self.content = content
        self.nextElement = nextElement

class Main:
    def __init__(self):
        self.firstElement = None
        self.size = 0

    def isEmpty(self):
        return self.size == 0

    def size(self):
        return self.size

    def add(self, element):
        newNode = Node(element, self.firstElement)
        self.firstElement = newNode
        self.size += 1

    def contains(self, element):
        for value in self:
            if value == element:
                return True
        return False

    def __iter__(self):
        return ListIterator(self.firstElement)

    def __next__(self):
        if self.firstElement is None:
            raise StopIteration
        element = self.firstElement.content
        self.firstElement = self.firstElement.nextElement
        return element

class ListIterator:
    def __init__(self, firstElement):
        self.currentElement = firstElement

    def __iter__(self):
        return self

    def __next__(self):
        if self.currentElement is None:
            raise StopIteration
        element = self.currentElement.content
        self.currentElement = self.currentElement.nextElement
        return element

if __name__ == "__main__":
    bag = Main()
    n = int(input("Enter number of elements: "))
    print("Enter elements:")
    for i in range(n):
        element = input()
        bag.add(element)
    print("Main contents:")
    for element in bag:
        print(element)
    checkElement = input("Enter an element to check for membership: ")
    print("Contains " + checkElement + ": " + str(bag.contains(checkElement)))
    print("Main size: " + str(bag.size()))
    print("Is bag empty: " + str(bag.isEmpty()))

