class Node:
    """Node class representing each element in the bag."""
    def __init__(self, content):
        self.content = content
        self.next_element = None


class Bag:
    """A generic collection that allows adding and iterating over elements but does not support
    element removal. This class implements a simple bag data structure, which can hold duplicate
    elements and provides operations to check for membership and the size of the collection.
    """

    def __init__(self):
        """Constructs an empty bag."""
        self.first_element = None
        self.size = 0

    def is_empty(self):
        """Checks if the bag is empty."""
        return self.size == 0

    def get_size(self):
        """Returns the number of elements in the bag."""
        return self.size

    def add(self, element):
        """Adds an element to the bag."""
        if element is None:
            raise ValueError("Element must not be None")
        new_node = Node(element)
        new_node.next_element = self.first_element
        self.first_element = new_node
        self.size += 1

    def contains(self, element):
        """Checks if the bag contains a specific element."""
        current = self.first_element
        while current is not None:
            if current.content == element:
                return True
            current = current.next_element
        return False

    def __iter__(self):
        """Returns an iterator over the elements in this bag."""
        current = self.first_element
        while current is not None:
            yield current.content
            current = current.next_element


def main():
    bag = Bag()

    n = int(input("Enter number of elements: "))
    print("Enter elements:")
    for _ in range(n):
        element = input()
        bag.add(element)

    print("Bag contents:")
    for element in bag:
        print(element)

    check_element = input("Enter an element to check for membership: ")
    print(f"Contains {check_element}: {bag.contains(check_element)}")

    print(f"Bag size: {bag.get_size()}")
    print(f"Is bag empty: {bag.is_empty()}")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
