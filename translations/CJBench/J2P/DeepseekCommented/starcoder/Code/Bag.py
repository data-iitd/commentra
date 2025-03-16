
class Main:
    # The first element of the list
    firstElement = None
    # The number of elements in the list
    size = 0

    # Constructor to initialize an empty list
    def __init__(self):
        self.firstElement = None
        self.size = 0

    # Returns true if the list is empty, false otherwise
    def isEmpty(self):
        return self.size == 0

    # Returns the number of elements in the list
    def size(self):
        return self.size

    # Adds a new element to the front of the list
    def add(self, element):
        newNode = Node()
        newNode.content = element
        newNode.nextElement = self.firstElement
        self.firstElement = newNode
        self.size += 1

    # Checks if the list contains a specific element
    def contains(self, element):
        # Iterate through the list to check for the element
        for value in self:
            if value == element:
                return True
        return False

    # Returns an iterator for the list
    def __iter__(self):
        return ListIterator(self.firstElement)

    # Inner class to implement the iterator for the list
    class ListIterator:
        # The current node in the iteration
        currentElement = None

        # Constructor to initialize the iterator with the first node
        def __init__(self, firstElement):
            self.currentElement = firstElement

        # Returns true if there is a next element in the iteration
        def hasNext(self):
            return self.currentElement!= None

        # Returns the next element in the iteration
        def next(self):
            if not self.hasNext():
                raise NoSuchElementException("No more elements in the bag.")
            element = self.currentElement.content
            self.currentElement = self.currentElement.nextElement
            return element

# Main method to run the program
if __name__ == "__main__":
    scanner = Scanner(System.in)
    bag = Main()
    n = scanner.nextInt()
    scanner.nextLine()
    # Read n elements and add them to the list
    for i in range(n):
        element = scanner.nextLine()
        bag.add(element)
    # Print all elements in the list
    print("Main contents:")
    for element in bag:
        print(element)
    # Read an element to check if it is in the list
    checkElement = scanner.nextLine()
    print("Contains " + checkElement + ": " + bag.contains(checkElement))
    print("Main size: " + bag.size())
    print("Is bag empty: " + bag.isEmpty())

