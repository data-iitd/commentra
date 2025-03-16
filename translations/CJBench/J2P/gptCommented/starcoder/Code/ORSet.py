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
        return {pair.element for pair in self.elements}

    # Method to add a new element to the set
    def add(self, element):
        # Generate a unique tag for the new element
        n = self.generateUniqueTag()
        # Create a pair and add it to the set
        self.effect(element, n)

    # Method to remove an element from the set
    def remove(self, element):
        # Prepare the pairs to be removed based on the element
        pairsToRemove = self.prepare(element)
        # Perform the removal effect
        self.effect(pairsToRemove)

    # Helper method to prepare a set of pairs to be removed
    def prepare(self, element):
        pairsToRemove = set()
        # Iterate through elements to find matches for removal
        for pair in self.elements:
            if pair.element == element:
                pairsToRemove.add(pair)
        return pairsToRemove

    # Helper method to add a new element with a unique tag
    def effect(self, element, n):
        pair = Pair(element, n)
        self.elements.add(pair)
        # Clean up any tombstones from the elements set
        self.elements.difference_update(self.tombstones)

    # Helper method to remove pairs and add them to tombstones
    def effect(self, pairsToRemove):
        self.elements.difference_update(pairsToRemove)
        self.tombstones.update(pairsToRemove)

    # Method to generate a unique tag using UUID
    def generateUniqueTag(self):
        return str(uuid.uuid4())

    # Inner class to represent a pair of an element and its unique tag
    class Pair:
        def __init__(self, element, uniqueTag):
            self.element = element
            self.uniqueTag = uniqueTag

# Main method to execute the program
if __name__ == "__main__":
    scanner = Scanner(System.in)
    orSet = Main()
    # Read the number of operations to perform
    operations = int(scanner.nextLine())
    
    # Loop through each operation
    for i in range(operations):
        input = scanner.nextLine().split(" ")
        operation = input[0]
        element = input[1]
        # Perform the corresponding operation based on user input
        if operation.equalsIgnoreCase("ADD"):
            orSet.add(element)
        elif operation.equalsIgnoreCase("REMOVE"):
            orSet.remove(element)
        else:
            print("Invalid operation: " + operation)
    
    # Check if a specific element is contained in the set
    checkElement = scanner.nextLine()
    print("Contains " + checkElement + ": " + orSet.contains(checkElement))
    # Display all elements in the set
    print("Elements in Main: " + orSet.elements())

