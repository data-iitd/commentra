
import uuid

class Main:
    # Initialize two empty sets for storing elements and tombstones
    elements = set()
    tombstones = set()

    def __init__(self):
        # Constructor initializes the elements and tombstones as empty sets
        pass

    def contains(self, element):
        # Check if the given element exists in the elements set
        return any(pair.element == element for pair in self.elements)

    def elements(self):
        # Create a new set and add all elements from the elements set to it
        result = set()
        for pair in self.elements:
            result.add(pair.element)
        # Return the result set containing all elements from the elements set
        return result

    def add(self, element):
        # Generate a unique tag for the new element
        n = self.generate_unique_tag()
        # Add the new element-tag pair to the elements set and remove all tombstones with the same element
        self.effect(element, n)
        # Print a message to the console indicating the addition of the new element
        print("Added " + element)

    def remove(self, element):
        # Find all elements in the elements set with the given element
        pairs_to_remove = self.prepare(element)
        # Remove the found elements and their tombstones from the sets
        self.effect(pairs_to_remove)
        # Print a message to the console indicating the removal of the element
        print("Removed " + element)

    def prepare(self, element):
        # Create an empty set to store the pairs to be removed
        pairs_to_remove = set()
        # Iterate through all pairs in the elements set and remove the ones with the given element
        for pair in self.elements:
            if pair.element == element:
                pairs_to_remove.add(pair)
        # Return the pairs_to_remove set
        return pairs_to_remove

    def effect(self, element, n):
        # Create a new pair with the given element and tag
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

    class Pair:
        # Initialize the element and uniqueTag fields
        def __init__(self, element, uniqueTag):
            self.element = element
            self.uniqueTag = uniqueTag

        # Getter method for the element field
        def get_element(self):
            return self.element


if __name__ == "__main__":
    # Initialize a Scanner object for reading input from the console
    scanner = input()
    # Create a new instance of the Main class for strings
    or_set = Main()
    # Read the number of operations from the console
    operations = int(input())
    # Iterate through the operations and perform the corresponding ADD or REMOVE operation
    for i in range(operations):
        operation, element = input().split()
        if operation == "ADD":
            or_set.add(element)
        elif operation == "REMOVE":
            or_set.remove(element)
        else:
            # Print an error message for invalid operations
            print("Invalid operation: " + operation)
    # Read the element to check from the console
    check_element = input()
    # Print the result of the contains() method call for the given element
    print("Contains " + check_element + ": " + str(or_set.contains(check_element)))
    # Print the elements in the Main set
    print("Elements in Main: " + str(or_set.elements()))
    # Close the Scanner object
    scanner.close()

