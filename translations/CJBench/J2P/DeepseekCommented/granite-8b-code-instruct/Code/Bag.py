
class Main:
    # The first element of the list
    first_element = None
    # The number of elements in the list
    size = 0

    # Constructor to initialize an empty list
    def __init__(self):
        self.first_element = None
        self.size = 0

    # Returns true if the list is empty, false otherwise
    def is_empty(self):
        return self.size == 0

    # Returns the number of elements in the list
    def size(self):
        return self.size

    # Adds a new element to the front of the list
    def add(self, element):
        new_node = Node(element, self.first_element)
        self.first_element = new_node
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
        return ListIterator(self.first_element)

# Inner class to represent a node in the list
class Node:
    # The content stored in the node
    content = None
    # Reference to the next node in the list
    next_element = None

    # Constructor to initialize a node with content and next element
    def __init__(self, content, next_element):
        self.content = content
        self.next_element = next_element

# Inner class to implement the iterator for the list
class ListIterator:
    # The current node in the iteration
    current_element = None

    # Constructor to initialize the iterator with the first node
    def __init__(self, first_element):
        self.current_element = first_element

    # Returns true if there is a next element in the iteration
    def has_next(self):
        return self.current_element is not None

    # Returns the next element in the iteration
    def next(self):
        if not self.has_next():
            raise StopIteration("No more elements in the bag.")
        element = self.current_element.content
        self.current_element = self.current_element.next_element
        return element

# Main method to run the program
if __name__ == "__main__":
    import sys
    n = int(input())
    bag = Main()
    # Read n elements and add them to the list
    for i in range(n):
        element = input()
        bag.add(element)
    # Print all elements in the list
    print("Main contents:")
    for element in bag:
        print(element)
    # Read an element to check if it is in the list
    check_element = input()
    print("Contains " + check_element + ": " + str(bag.contains(check_element)))
    print("Main size: " + str(bag.size()))
    print("Is bag empty: " + str(bag.is_empty()))

