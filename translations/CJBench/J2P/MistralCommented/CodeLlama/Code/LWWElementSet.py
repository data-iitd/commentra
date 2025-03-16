
import sys

# Class representing an element with a key, timestamp, and bias
class Element:
    def __init__(self, key, timestamp, bias):
        self.key = key
        self.timestamp = timestamp
        self.bias = bias

# Enum representing the bias type (ADDS or REMOVALS)
class Bias(Enum):
    ADDS = 1
    REMOVALS = 2

# Main class for LWW Set implementation
class Main:
    # Private instance variables for add and remove sets
    def __init__(self):
        # Initialize addSet and removeSet as empty dictionaries
        self.addSet = {}
        self.removeSet = {}

    # Method to add an element to the addSet
    def add(self, e):
        # Add the given element to the addSet with the given key as the key
        self.addSet[e.key] = e

    # Method to remove an element from the addSet
    def remove(self, e):
        # Check if the given element exists in the addSet
        if self.lookup(e):
            # If it exists, add it to the removeSet with the same key
            self.removeSet[e.key] = e
            # Remove it from the addSet
            del self.addSet[e.key]

    # Method to check if an element exists in the addSet or removeSet
    def lookup(self, e):
        # Get the Element with the given key from the addSet
        inAddSet = self.addSet.get(e.key)
        # Get the Element with the given key from the removeSet
        inRemoveSet = self.removeSet.get(e.key)
        # Return true if the Element exists only in the addSet or if it exists in both sets but the one in the addSet has a later timestamp
        return (inAddSet is not None and (inRemoveSet is None or inAddSet.timestamp > inRemoveSet.timestamp))

    # Method to compare two Main objects based on their add and remove sets
    def compare(self, other):
        # Check if both sets have the same keys
        return other.addSet.keys() <= self.addSet.keys() and other.removeSet.keys() <= self.removeSet.keys()

    # Method to merge two Main objects
    def merge(self, other):
        # Iterate through each Element in other.addSet
        for e in other.addSet.values():
            # If the given key doesn't exist in the current Main object's addSet or if the given Element has a later timestamp
            if not self.addSet.get(e.key) or self.compareTimestamps(self.addSet.get(e.key), e):
                # Add the given Element to the current Main object's addSet
                self.addSet[e.key] = e
        # Iterate through each Element in other.removeSet
        for e in other.removeSet.values():
            # If the given key doesn't exist in the current Main object's removeSet or if the given Element has a later timestamp
            if not self.removeSet.get(e.key) or self.compareTimestamps(self.removeSet.get(e.key), e):
                # Add the given Element to the current Main object's removeSet
                self.removeSet[e.key] = e

    # Method to compare the timestamps of two Elements
    def compareTimestamps(self, e, other):
        # Throw an IllegalArgumentException if the bias values don't match
        if e.bias != other.bias:
            raise ValueError("Invalid bias value")
        # Compare the timestamps of the two Elements
        bias = e.bias
        timestampComparison = e.timestamp - other.timestamp
        # Return true if the Elements have different biases or if the current Element has an earlier timestamp and the same bias
        return (bias != Bias.ADDS or timestampComparison > 0) and (timestampComparison != 0)

    # Method to print the addSet and removeSet
    def printSets(self):
        # Print the keys of the addSet and removeSet
        print("Add Set: " + str(self.addSet.keys()))
        print("Remove Set: " + str(self.removeSet.keys()))

    # Main method for testing the LWW Set implementation
    def main(self):
        # Create a new instance of the Main class
        lwwSet = Main()

        # Read the number of operations from the input
        operations = int(input())

        # Process each operation
        for i in range(operations):
            command, key, timestamp, bias = input().split()
            # Create a new Element based on the given command, key, timestamp, and bias
            element = Element(key, int(timestamp), Bias[bias])

            # Based on the command, add or remove the Element from the LWW Set
            if command == "ADD":
                lwwSet.add(element)
            elif command == "REMOVE":
                lwwSet.remove(element)

        # Read the number of lookups from the input
        lookupCount = int(input())

        # Process each lookup
        for i in range(lookupCount):
            key = input()
            lookupElement = Element(key, 0, Bias.ADDS)

            # Perform a lookup on the LWW Set with the given key
            result = lwwSet.lookup(lookupElement)
            # Print the result of the lookup
            print("Lookup " + key + ": " + str(result))

        # Print the addSet and removeSet
        lwwSet.printSets()

# Main method for testing the LWW Set implementation
if __name__ == "__main__":
    Main().main()

