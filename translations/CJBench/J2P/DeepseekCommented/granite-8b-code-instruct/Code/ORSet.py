
import uuid

class Main:
    def __init__(self):
        self.elements = set()  # Initialize sets for elements and tombstones
        self.tombstones = set()

    def contains(self, element):
        # Check if the element is present in the elements set
        return any(pair.element == element for pair in self.elements)

    def elements(self):
        # Return a set of all elements present in the elements set
        return {pair.element for pair in self.elements}

    def add(self, element):
        # Add a new element to the elements set by generating a unique tag
        n = self.generate_unique_tag()
        self.effect(element, n)

    def remove(self, element):
        # Remove an element from the elements set and add it to the tombstones set
        pairs_to_remove = self.prepare(element)
        self.effect(pairs_to_remove)

    def prepare(self, element):
        # Prepare a set of pairs to be removed from the elements set
        pairs_to_remove = set()
        for pair in self.elements:
            if pair.element == element:
                pairs_to_remove.add(pair)
        return pairs_to_remove

    def effect(self, element, n):
        # Add a new pair to the elements set and remove tombstones
        pair = Pair(element, n)
        self.elements.add(pair)
        self.elements -= self.tombstones

    def effect(self, pairs_to_remove):
        # Remove pairs from the elements set and add them to the tombstones set
        self.elements -= pairs_to_remove
        self.tombstones |= pairs_to_remove

    def generate_unique_tag(self):
        # Generate a unique tag using uuid
        return str(uuid.uuid4())

class Pair:
    # Nested class to hold an element and a unique tag
    def __init__(self, element, unique_tag):
        self.element = element
        self.unique_tag = unique_tag

if __name__ == "__main__":
    # Main method to read input operations and elements, perform operations, and print results
    operations = int(input())
    or_set = Main()
    for _ in range(operations):
        operation, element = input().split()
        if operation.upper() == "ADD":
            or_set.add(element)
        elif operation.upper() == "REMOVE":
            or_set.remove(element)
        else:
            print(f"Invalid operation: {operation}")
    check_element = input()
    print(f"Contains {check_element}: {or_set.contains(check_element)}")
    print(f"Elements in Main: {or_set.elements()}")

