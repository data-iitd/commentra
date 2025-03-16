
class Main:
    # The first element of the linked list
    first_element = None
    # The size of the linked list
    size = 0

    # Inner class representing a node in the linked list
    class Node:
        def __init__(self, content, next_element=None):
            self.content = content
            self.next_element = next_element

    # Constructor to initialize the linked list
    def __init__(self):
        self.first_element = None
        self.size = 0

    # Method to check if the linked list is empty
    def is_empty(self):
        return self.size == 0

    # Method to get the size of the linked list
    def size(self):
        return self.size

    # Method to add an element to the linked list
    def add(self, element):
        new_node = Main.Node(element, self.first_element)
        self.first_element = new_node
        self.size += 1

    # Method to check if the linked list contains a specific element
    def contains(self, element):
        for value in self:
            if value == element:
                return True
        return False

    # Method to return an iterator for the linked list
    def __iter__(self):
        return ListIterator(self.first_element)

# Inner class implementing the iterator for the linked list
class ListIterator:
    def __init__(self, first_element):
        self.current_element = first_element

    def __next__(self):
        if self.current_element is None:
            raise StopIteration("No more elements in the bag.")
        element = self.current_element.content
        self.current_element = self.current_element.next_element
        return element

# Main method to run the program
if __name__ == "__main__":
    import sys

    n = int(input())  # Read the number of elements to add
    bag = Main()  # Create a new instance of Main (linked list)

    # Loop to read elements and add them to the linked list
    for _ in range(n):
        element = input()  # Read each element
        bag.add(element)  # Add the element to the linked list

    # Print the contents of the linked list
    print("Main contents:")
    for element in bag:  # Iterate through the linked list
        print(element)  # Print each element

    # Check if a specific element is contained in the linked list
    check_element = input()  # Read the element to check
    print(f"Contains {check_element}: {bag.contains(check_element)}")  # Print the result

    # Print the size of the linked list
    print(f"Main size: {bag.size()}")  # Print the size

    # Check if the linked list is empty
    print(f"Is bag empty: {bag.is_empty()}")  # Print whether the bag is empty

