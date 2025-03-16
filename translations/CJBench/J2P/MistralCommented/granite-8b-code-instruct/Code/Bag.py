

# Python code for the Main generic linked list

# Class definition for the Node class
class Node:
    def __init__(self, content=None, nextElement=None):
        self.content = content
        self.nextElement = nextElement

# Class definition for the Main generic linked list
class Main:
    # Constructor for the Main class, initializes firstElement and size to None and 0 respectively
    def __init__(self):
        self.firstElement = None
        self.size = 0

    # Check if the list is empty or not
    def isEmpty(self):
        # Return True if size is equal to 0, indicating an empty list
        return self.size == 0

    # Get the size of the list
    def size(self):
        # Return the current size of the list
        return self.size

    # Add an element to the list
    def add(self, element):
        # Create a new Node with the given element
        newNode = Node(element)

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
            # If the current element matches the given element, return True
            if value == element:
                return True

        # If no matching element is found, return False
        return False

    # Override the __iter__ method to return a ListIterator for the list
    def __iter__(self):
        # Create a new ListIterator instance with the firstElement as its initial value
        return ListIterator(self.firstElement)

# Class definition for the ListIterator
class ListIterator:
    # Constructor for the ListIterator, initializes currentElement with the given firstElement
    def __init__(self, firstElement):
        self.currentElement = firstElement

    # Check if there is a next element to iterate to
    def __next__(self):
        # If there is no next element, raise a StopIteration exception
        if self.currentElement is None:
            raise StopIteration("No more elements in the bag.")

        # Get the content of the currentElement and update currentElement to point to the next element
        element = self.currentElement.content
        self.currentElement = self.currentElement.nextElement

        # Return the next element
        return element

# Main method for testing the Main class
if __name__ == "__main__":
    # Create a new instance of the Main class for strings
    bag = Main()

    # Read the number of elements to add to the list from the console
    n = int(input("Enter the number of elements to add to the list: "))

    # Add each element to the list
    for i in range(n):
        element = input("Enter element " + str(i+1) + ": ")
        bag.add(element)

    # Print the contents of the list
    print("Main contents:")
    for element in bag:
        print(element)

    # Read a string from the console to check for existence in the list
    checkElement = input("Enter the element to check for existence in the list: ")

    # Print whether the given string is present in the list or not
    print("Contains " + checkElement + ": " + str(bag.contains(checkElement)))

    # Print the size of the list
    print("Main size: " + str(bag.size()))

    # Print whether the list is empty or not
    print("Is bag empty: " + str(bag.isEmpty()))

# End of code
