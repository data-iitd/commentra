
import sys

# Class representing an element with a key, timestamp, and bias
class Element:
    def __init__(self, key, timestamp, bias):
        self.key = key
        self.timestamp = timestamp
        self.bias = bias

# Enum representing the type of operation: addition or removal
class Bias(Enum):
    ADDS = 1
    REMOVALS = 2

# Main class implementing the Last Write Wins (LWW) set
class Main:
    def __init__(self):
        self.addSet = {} # Initialize the add set
        self.removeSet = {} # Initialize the remove set

    # Method to add an element to the add set
    def add(self, e):
        self.addSet[e.key] = e # Store the element in the add set

    # Method to remove an element from the remove set if it exists in the add set
    def remove(self, e):
        if self.lookup(e): # Check if the element exists in the add set
            self.removeSet[e.key] = e # Store the element in the remove set

    # Method to check if an element is present in the add set and not removed
    def lookup(self, e):
        inAddSet = self.addSet.get(e.key) # Get the element from the add set
        inRemoveSet = self.removeSet.get(e.key) # Get the element from the remove set
        # Return true if the element is in the add set and either not in the remove set or has a later timestamp
        return (inAddSet is not None and (inRemoveSet is None or inAddSet.timestamp > inRemoveSet.timestamp))

    # Method to compare the current LWW set with another LWW set
    def compare(self, other):
        # Check if the other set contains all keys from the current add and remove sets
        return other.addSet.keys() >= self.addSet.keys() and other.removeSet.keys() >= self.removeSet.keys()

    # Method to merge another LWW set into the current set
    def merge(self, other):
        # Merge elements from the other add set
        for e in other.addSet.values():
            # Add the element if it's not present or has a later timestamp
            if not self.addSet.get(e.key) or self.compareTimestamps(self.addSet.get(e.key), e):
                self.addSet[e.key] = e
        # Merge elements from the other remove set
        for e in other.removeSet.values():
            # Add the element if it's not present or has a later timestamp
            if not self.removeSet.get(e.key) or self.compareTimestamps(self.removeSet.get(e.key), e):
                self.removeSet[e.key] = e

    # Method to compare timestamps of two elements
    def compareTimestamps(self, e, other):
        # Check if the biases of the two elements are the same
        if e.bias != other.bias:
            raise ValueError("Invalid bias value") # Throw an exception if biases differ
        bias = e.bias # Get the bias of the first element
        timestampComparison = e.timestamp - other.timestamp # Compare timestamps
        # If timestamps are equal, return false for ADDS bias, true for REMOVALS bias
        if timestampComparison == 0:
            return bias != Bias.ADDS
        # Return true if the first element's timestamp is less than the second's
        return timestampComparison < 0

    # Method to print the contents of the add and remove sets
    def printSets(self):
        print("Add Set: " + str(self.addSet.keys())) # Print keys of the add set
        print("Remove Set: " + str(self.removeSet.keys())) # Print keys of the remove set

# Main method to execute the program
def main():
    scanner = sys.stdin # Create a scanner for input
    lwwSet = Main() # Create an instance of the LWW set
    operations = int(scanner.readline()) # Read the number of operations

    # Process each operation
    for i in range(operations):
        command, key, timestamp, bias = scanner.readline().split() # Read the command (ADD or REMOVE), key, timestamp, and bias
        element = Element(key, int(timestamp), Bias[bias]) # Create a new Element

        # Execute the command based on its type
        if command == "ADD":
            lwwSet.add(element) # Add the element to the set
        elif command == "REMOVE":
            lwwSet.remove(element) # Remove the element from the set

    # Read the number of lookups to perform
    lookupCount = int(scanner.readline())

    # Perform each lookup
    for i in range(lookupCount):
        key = scanner.readline().strip() # Read the key to lookup
        lookupElement = Element(key, 0, Bias.ADDS) # Create a lookup Element
        # Print the result of the lookup
        print("Lookup " + key + ": " + str(lwwSet.lookup(lookupElement)))

    # Print the contents of the add and remove sets
    lwwSet.printSets()
    scanner.close() # Close the scanner

if __name__ == "__main__":
    main()
