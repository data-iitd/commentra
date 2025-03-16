
# Class definition for the Main generic linked list
class Main:
    # Declare instance variables for the first element and size of the list
    firstElement = None
    size = 0

    # Constructor for the Main class, initializes firstElement and size to null and 0 respectively
    def __init__(self):
        self.firstElement = None
        self.size = 0

    # Check if the list is empty or not
    def isEmpty(self):
        # Return true if size is equal to 0, indicating an empty list
        return self.size == 0

    # Get the size of the list
    def size(self):
        # Return the current size of the list
        return self.size

    # Add an element to the list
    def add(self, element):
        # Create a new Node with the given element
        newNode = Node()
        newNode.content = element

        # Set the nextElement of the new Node to the current firstElement
        newNode.nextElement = self.firstElement

        # Update the firstElement to point to the new Node
        self.firstElement = newNode

        # Increment the size of the list
        self.size += 1

    # Check if an element exists in the list
    def contains(self, element):
        # Iterate through each element in the list using the iterator
        for value in self:
            # If the current element matches the given element, return true
            if value.equals(element):
                return True

        # If no matching element is found, return false
        return False

    # Override the iterator() method to return a ListIterator for the list
    def iterator(self):
        # Create a new ListIterator instance with the firstElement as its initial value
        return ListIterator(self.firstElement)

    # Inner class definition for the ListIterator
    class ListIterator:
        # Declare an instance variable for the currentElement
        currentElement = None

        # Constructor for the ListIterator, initializes currentElement with the given firstElement
        def __init__(self, firstElement):
            self.currentElement = firstElement

        # Check if there is a next element to iterate to
        def hasNext(self):
            # Return true if currentElement is not null, indicating there is a next element
            return self.currentElement is not None

        # Get the next element in the list
        def next(self):
            # If there is no next element, throw a NoSuchElementException
            if not self.hasNext():
                raise NoSuchElementException("No more elements in the bag.")

            # Get the content of the currentElement and update currentElement to point to the next element
            element = self.currentElement.content
            self.currentElement = self.currentElement.nextElement

            # Return the next element
            return element

# Main method for testing the Main class
def main():
    # Create a new Scanner instance for reading input from the console
    scanner = Scanner(System.in)

    # Create a new instance of the Main class for strings
    bag = Main()

    # Read the number of elements to add to the list from the console
    n = scanner.nextInt()
    scanner.nextLine() # Consume the newline character left after reading int

    # Add each element to the list
    for i in range(n):
        element = scanner.nextLine()
        bag.add(element)

    # Print the contents of the list
    print("Main contents:")
    for element in bag:
        print(element)

    # Read a string from the console to check for existence in the list
    checkElement = scanner.nextLine()

    # Print whether the given string is present in the list or not
    print("Contains " + checkElement + ": " + bag.contains(checkElement))

    # Print the size of the list
    print("Main size: " + bag.size())

    # Print whether the list is empty or not
    print("Is bag empty: " + bag.isEmpty())

    # Close the Scanner instance
    scanner.close()

if __name__ == "__main__":
    main()

