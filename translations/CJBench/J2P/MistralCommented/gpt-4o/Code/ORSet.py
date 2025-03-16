import uuid

class Pair:
    def __init__(self, element, unique_tag):
        self.element = element
        self.unique_tag = unique_tag

    def get_element(self):
        return self.element

class Main:
    def __init__(self):
        self.elements = set()  # Initialize an empty set for storing elements
        self.tombstones = set()  # Initialize an empty set for storing tombstones

    def contains(self, element):
        # Check if the given element exists in the elements set
        return any(pair.get_element() == element for pair in self.elements)

    def elements_set(self):
        # Return a set of all elements from the elements set
        return {pair.get_element() for pair in self.elements}

    def add(self, element):
        # Generate a unique tag for the new element
        n = self.generate_unique_tag()
        # Add the new element-tag pair to the elements set and remove all tombstones with the same element
        self.effect(element, n)
        print(f"Added {element}")

    def remove(self, element):
        # Find all elements in the elements set with the given element
        pairs_to_remove = self.prepare(element)
        # Remove the found elements and their tombstones from the sets
        self.effect(pairs_to_remove)
        print(f"Removed {element}")

    def prepare(self, element):
        # Create a set to store the pairs to be removed
        pairs_to_remove = set()
        # Iterate through all pairs in the elements set and remove the ones with the given element
        for pair in self.elements:
            if pair.get_element() == element:
                pairs_to_remove.add(pair)
        return pairs_to_remove

    def effect(self, element, n):
        # Create a new Pair with the given element and tag
        pair = Pair(element, n)
        # Add the new pair to the elements set and remove all tombstones with the same element
        self.elements.add(pair)
        self.elements.difference_update(self.tombstones)

    def effect(self, pairs_to_remove):
        # Remove the given pairs from the elements set and add them to the tombstones set
        self.elements.difference_update(pairs_to_remove)
        self.tombstones.update(pairs_to_remove)

    def generate_unique_tag(self):
        # Generate a unique tag using uuid.uuid4() method
        return str(uuid.uuid4())

if __name__ == "__main__":
    import sys

    # Initialize a Main instance for strings
    or_set = Main()
    # Read the number of operations from the console
    operations = int(input())
    # Iterate through the operations and perform the corresponding ADD or REMOVE operation
    for _ in range(operations):
        input_line = input().split(" ")
        operation = input_line[0]
        element = input_line[1]
        if operation.upper() == "ADD":
            or_set.add(element)
        elif operation.upper() == "REMOVE":
            or_set.remove(element)
        else:
            # Print an error message for invalid operations
            print(f"Invalid operation: {operation}")

    # Read the element to check from the console
    check_element = input()
    # Print the result of the contains() method call for the given element
    print(f"Contains {check_element}: {or_set.contains(check_element)}")
    # Print the elements in the Main set
    print(f"Elements in Main: {or_set.elements_set()}")

# <END-OF-CODE>
