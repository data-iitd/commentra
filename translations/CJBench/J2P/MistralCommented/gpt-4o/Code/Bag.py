class Node:
    def __init__(self, content=None):
        self.content = content
        self.next_element = None


class Main:
    def __init__(self):
        self.first_element = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def get_size(self):
        return self.size

    def add(self, element):
        new_node = Node(content=element)
        new_node.next_element = self.first_element
        self.first_element = new_node
        self.size += 1

    def contains(self, element):
        for value in self:
            if value == element:
                return True
        return False

    def __iter__(self):
        return ListIterator(self.first_element)


class ListIterator:
    def __init__(self, first_element):
        self.current_element = first_element

    def __iter__(self):
        return self

    def __next__(self):
        if self.current_element is None:
            raise StopIteration("No more elements in the bag.")
        element = self.current_element.content
        self.current_element = self.current_element.next_element
        return element


if __name__ == "__main__":
    import sys

    # Create a new instance of the Main class for strings
    bag = Main()

    # Read the number of elements to add to the list from the console
    n = int(input())
    
    # Add each element to the list
    for _ in range(n):
        element = input().strip()
        bag.add(element)

    # Print the contents of the list
    print("Main contents:")
    for element in bag:
        print(element)

    # Read a string from the console to check for existence in the list
    check_element = input().strip()

    # Print whether the given string is present in the list or not
    print(f"Contains {check_element}: {bag.contains(check_element)}")

    # Print the size of the list
    print(f"Main size: {bag.get_size()}")

    # Print whether the list is empty or not
    print(f"Is bag empty: {bag.is_empty()}")

