import uuid

class Main:
    # Set to store unique elements
    elements = set()
    # Set to store tombstones for removed elements
    tombstones = set()

    # Constructor to initialize the sets
    def __init__(self):
        self.elements = set()
        self.tombstones = set()

    # Method to check if an element exists in the set
    def contains(self, element):
        return any(pair.element == element for pair in self.elements)

    # Method to retrieve all elements in the set
    def elements(self):
        result = set()
        for pair in self.elements:
            result.add(pair.element)
        return result

    # Method to add a new element to the set
    def add(self, element):
        # Generate a unique tag for the new element
        n = self.generate_unique_tag()
        # Create a pair and add it to the set
        self.effect(element, n)

    # Method to remove an element from the set
    def remove(self, element):
        # Prepare the pairs to be removed based on the element
        pairs_to_remove = self.prepare(element)
        # Perform the removal effect
        self.effect(pairs_to_remove)

    # Helper method to prepare a set of pairs to be removed
    def prepare(self, element):
        pairs_to_remove = set()
        # Iterate through elements to find matches for removal
        for pair in self.elements:
            if pair.element == element:
                pairs_to_remove.add(pair)
        return pairs_to_remove

    # Helper method to add a new element with a unique tag
    def effect(self, element, n):
        pair = Pair(element, n)
        self.elements.add(pair)
        # Clean up any tombstones from the elements set
        self.elements.difference_update(self.tombstones)

    # Helper method to remove pairs and add them to tombstones
    def effect(self, pairs_to_remove):
        self.elements.difference_update(pairs_to_remove)
        self.tombstones.update(pairs_to_remove)

    # Method to generate a unique tag using UUID
    def generate_unique_tag(self):
        return str(uuid.uuid4())

    # Inner class to represent a pair of an element and its unique tag
    class Pair:
        def __init__(self, element, unique_tag):
            self.element = element
            self.unique_tag = unique_tag

# Main method to execute the program
def main():
    # Read the number of operations to perform
    operations = int(input())
    or_set = Main()

    # Loop through each operation
    for i in range(operations):
        operation, element = input().split()
        # Perform the corresponding operation based on user input
        if operation == "ADD":
            or_set.add(element)
        elif operation == "REMOVE":
            or_set.remove(element)
        else:
            print("Invalid operation:", operation)

    # Check if a specific element is contained in the set
    check_element = input()
    print("Contains", check_element, ":", or_set.contains(check_element))
    # Display all elements in the set
    print("Elements in Main:", or_set.elements())

if __name__ == "__main__":
    main()

