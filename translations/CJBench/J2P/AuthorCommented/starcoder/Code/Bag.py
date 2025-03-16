
import sys

# Node class representing each element in the bag
class Node:
    def __init__(self, content, nextElement):
        self.content = content
        self.nextElement = nextElement


# A generic collection that allows adding and iterating over elements but does not support
# element removal. This class implements a simple bag data structure, which can hold duplicate
# elements and provides operations to check for membership and the size of the collection.
class Main:
    def __init__(self):
        self.firstElement = None
        self.size = 0

    # Checks if the bag is empty.
    def isEmpty(self):
        return self.size == 0

    # Returns the number of elements in the bag.
    def size(self):
        return self.size

    # Adds an element to the bag.
    #
    # This method adds the specified element to the bag. Duplicates are allowed, and the
    # bag will maintain the order in which elements are added.
    def add(self, element):
        newNode = Node(element, self.firstElement)
        self.firstElement = newNode
        self.size += 1

    # Checks if the bag contains a specific element.
    #
    # This method uses the `equals` method of the element to determine membership.
    def contains(self, element):
        for value in self:
            if value == element:
                return True
        return False

    # Returns an iterator over the elements in this bag.
    #
    # The iterator provides a way to traverse the elements in the order they were added.
    def __iter__(self):
        return ListIterator(self.firstElement)


# Private class for iterating over elements
class ListIterator:
    def __init__(self, firstElement):
        self.currentElement = firstElement

    # Checks if there are more elements to iterate over.
    def hasNext(self):
        return self.currentElement is not None

    # Returns the next element in the iteration.
    def next(self):
        if not self.hasNext():
            raise StopIteration("No more elements in the bag.")
        element = self.currentElement.content
        self.currentElement = self.currentElement.nextElement
        return element


if __name__ == "__main__":
    bag = Main()

    n = int(sys.stdin.readline())
    sys.stdin.readline()  # Consume newline

    print("Enter elements:")
    for i in range(n):
        element = sys.stdin.readline()
        bag.add(element)

    print("Main contents:")
    for element in bag:
        print(element)

    print("Enter an element to check for membership:")
    checkElement = sys.stdin.readline()
    print("Contains " + checkElement + ": " + str(bag.contains(checkElement)))

    print("Main size: " + str(bag.size()))
    print("Is bag empty: " + str(bag.isEmpty()))

