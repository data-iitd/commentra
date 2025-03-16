class Node:
    def __init__(self, content):
        self.content = content  # The content of the node
        self.next_element = None  # Reference to the next node


class Main:
    def __init__(self):
        self.first_element = None  # Initially, there are no elements
        self.size = 0  # Size is zero

    def is_empty(self):
        return self.size == 0  # Returns True if size is zero

    def get_size(self):
        return self.size  # Returns the current size

    def add(self, element):
        new_node = Node(element)  # Create a new node
        new_node.next_element = self.first_element  # Link the new node to the first element
        self.first_element = new_node  # Update the first element to the new node
        self.size += 1  # Increment the size of the linked list

    def contains(self, element):
        current = self.first_element  # Start from the first element
        while current is not None:  # Iterate through the linked list
            if current.content == element:  # Check if the current value matches the element
                return True  # Return True if found
            current = current.next_element  # Move to the next element
        return False  # Return False if not found

    def __iter__(self):
        return ListIterator(self.first_element)  # Return a new ListIterator starting from the first element


class ListIterator:
    def __init__(self, first_element):
        self.current_element = first_element  # Set the current element to the first

    def __iter__(self):
        return self  # Return the iterator itself

    def __next__(self):
        if self.current_element is None:  # Check if there are no more elements
            raise StopIteration("No more elements in the bag.")  # Raise StopIteration if no elements left
        element = self.current_element.content  # Get the content of the current element
        self.current_element = self.current_element.next_element  # Move to the next element
        return element  # Return the current element


if __name__ == "__main__":
    import sys

    bag = Main()  # Create a new instance of Main (linked list)
    n = int(sys.stdin.readline().strip())  # Read the number of elements to add

    # Loop to read elements and add them to the linked list
    for _ in range(n):
        element = sys.stdin.readline().strip()  # Read each element
        bag.add(element)  # Add the element to the linked list

    # Print the contents of the linked list
    print("Main contents:")
    for element in bag:  # Iterate through the linked list
        print(element)  # Print each element

    # Check if a specific element is contained in the linked list
    check_element = sys.stdin.readline().strip()  # Read the element to check
    print(f"Contains {check_element}: {bag.contains(check_element)}")  # Print the result

    # Print the size of the linked list
    print(f"Main size: {bag.get_size()}")  # Print the size

    # Check if the linked list is empty
    print(f"Is bag empty: {bag.is_empty()}")  # Print whether the bag is empty

# <END-OF-CODE>
