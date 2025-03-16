
import uuid

class Main:
    # Initialize two empty HashSets for storing elements and tombstones
    def __init__(self):
        self.elements = set()
        self.tombstones = set()
        # Constructor initializes the elements and tombstones as empty HashSets

    def contains(self, element):
        # Check if the given element exists in the elements HashSet
        return any(pair.element == element for pair in self.elements)

    def elements(self):
        # Create a new HashSet and add all elements from the elements HashSet to it
        result = set()
        for pair in self.elements:
            result.add(pair.element)
        # Return the result HashSet containing all elements from the elements HashSet
        return result

    def add(self, element):
        # Generate a unique tag for the new element
        n = self.generateUniqueTag()
        # Add the new element-tag pair to the elements HashSet and remove all tombstones with the same element
        self.effect(element, n)
        # Print a message to the console indicating the addition of the new element
        print("Added " + element)

    def remove(self, element):
        # Find all elements in the elements HashSet with the given element
        pairsToRemove = self.prepare(element)
        # Remove the found elements and their tombstones from the HashSets
        self.effect(pairsToRemove)
        # Print a message to the console indicating the removal of the element
        print("Removed " + element)

    def prepare(self, element):
        # Create an empty HashSet to store the pairs to be removed
        pairsToRemove = set()
        # Iterate through all pairs in the elements HashSet and remove the ones with the given element
        for pair in self.elements:
            if pair.element == element:
                pairsToRemove.add(pair)
        # Return the pairsToRemove HashSet
        return pairsToRemove

    def effect(self, element, n):
        # Create a new Pair with the given element and tag
        pair = Pair(element, n)
        # Add the new pair to the elements HashSet and remove all tombstones with the same element
        self.elements.add(pair)
        self.elements.difference_update(self.tombstones)

    def effect(self, pairsToRemove):
        # Remove the given pairs from the elements HashSet and add them to the tombstones HashSet
        self.elements.difference_update(pairsToRemove)
        self.tombstones.update(pairsToRemove)

    def generateUniqueTag(self):
        # Generate a unique tag using uuid.uuid4() method
        return str(uuid.uuid4())

    class Pair:
        # Initialize the element and uniqueTag fields
        def __init__(self, element, uniqueTag):
            self.element = element
            self.uniqueTag = uniqueTag

        # Getter method for the element field
        def getElement(self):
            return self.element

if __name__ == "__main__":
    # Initialize a Scanner object for reading input from the console
    scanner = Scanner(System.in)
    # Create a new instance of the Main class for strings
    orSet = Main()
    # Read the number of operations from the console
    operations = int(scanner.nextLine())
    # Iterate through the operations and perform the corresponding ADD or REMOVE operation
    for i in range(operations):
        input = scanner.nextLine().split(" ")
        operation = input[0]
        element = input[1]
        if operation.equalsIgnoreCase("ADD"):
            orSet.add(element)
        else if operation.equalsIgnoreCase("REMOVE"):
            orSet.remove(element)
        else:
            # Print an error message for invalid operations
            print("Invalid operation: " + operation)
    # Read the element to check from the console
    checkElement = scanner.nextLine()
    # Print the result of the contains() method call for the given element
    print("Contains " + checkElement + ": " + orSet.contains(checkElement))
    # Print the elements in the Main HashSet
    print("Elements in Main: " + orSet.elements())
    # Close the Scanner object
    scanner.close()

