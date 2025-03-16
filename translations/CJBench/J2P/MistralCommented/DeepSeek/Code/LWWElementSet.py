from enum import Enum
from collections import defaultdict

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
    # Constructor for Main class
    def __init__(self):
        # Initialize addSet and removeSet as empty defaultdict instances
        self.addSet = defaultdict(list)
        self.removeSet = defaultdict(list)

    # Method to add an element to the addSet
    def add(self, e):
        # Add the given element to the addSet with the given key as the key
        self.addSet[e.key].append(e)

    # Method to remove an element from the addSet
    def remove(self, e):
        # Check if the given element exists in the addSet
        if self.lookup(e):
            # If it exists, add it to the removeSet with the same key
            self.removeSet[e.key].append(e)
            # Remove it from the addSet
            self.addSet[e.key].remove(e)

    # Method to check if an element exists in the addSet or removeSet
    def lookup(self, e):
        # Get the Element with the given key from the addSet
        inAddSet = self.addSet[e.key]
        # Get the Element with the given key from the removeSet
        inRemoveSet = self.removeSet[e.key]
        # Return true if the Element exists only in the addSet or if it exists in both sets but the one in the addSet has a later timestamp
        if inAddSet and (not inRemoveSet or inAddSet[-1].timestamp > inRemoveSet[-1].timestamp):
            return True
        return False

    # Method to compare two Main objects based on their add and remove sets
    def compare(self, other):
        # Check if both sets have the same keys
        return set(self.addSet.keys()) == set(other.addSet.keys()) and set(self.removeSet.keys()) == set(other.removeSet.keys())

    # Method to merge two Main objects
    def merge(self, other):
        # Iterate through each Element in other.addSet
        for e in other.addSet.values():
            # If the given key doesn't exist in the current Main object's addSet or if the given Element has a later timestamp
            if not self.addSet[e.key] or self.compareTimestamps(self.addSet[e.key][-1], e):
                # Add the given Element to the current Main object's addSet
                self.addSet[e.key].append(e)
        # Iterate through each Element in other.removeSet
        for e in other.removeSet.values():
            # If the given key doesn't exist in the current Main object's removeSet or if the given Element has a later timestamp
            if not self.removeSet[e.key] or self.compareTimestamps(self.removeSet[e.key][-1], e):
                # Add the given Element to the current Main object's removeSet
                self.removeSet[e.key].append(e)

    # Method to compare the timestamps of two Elements
    def compareTimestamps(self, e, other):
        # Throw an ValueError if the bias values don't match
        if e.bias != other.bias:
            raise ValueError("Invalid bias value")
        # Compare the timestamps of the two Elements
        bias = e.bias
        timestampComparison = other.timestamp - e.timestamp
        # Return true if the Elements have different biases or if the current Element has an earlier timestamp and the same bias
        return (bias != Bias.ADDS or timestampComparison > 0) and (timestampComparison != 0)

    # Method to print the addSet and removeSet
    def printSets(self):
        # Print the keys of the addSet and removeSet
        print("Add Set:", list(self.addSet.keys()))
        print("Remove Set:", list(self.removeSet.keys()))

    # Main method for testing the LWW Set implementation
    @staticmethod
    def main():
        import sys
        input = sys.stdin.readline

        # Create a new instance of the Main class
        lwwSet = Main()

        # Read the number of operations from the input
        operations = int(input())

        # Process each operation
        for _ in range(operations):
            command, key, timestamp, bias = input().split()
            timestamp = int(timestamp)
            bias = Bias[bias]

            # Create a new Element based on the given command, key, timestamp, and bias
            element = Element(key, timestamp, bias)

            # Based on the command, add or remove the Element from the LWW Set
            if command == "ADD":
                lwwSet.add(element)
            elif command == "REMOVE":
                lwwSet.remove(element)

        # Read the number of lookups from the input
        lookupCount = int(input())

        # Process each lookup
        for _ in range(lookupCount):
            key = input().strip()
            lookupElement = Element(key, 0, Bias.ADDS)

            # Perform a lookup on the LWW Set with the given key
            result = lwwSet.lookup(lookupElement)
            # Print the result of the lookup
            print(f"Lookup {key}: {result}")

        # Print the addSet and removeSet
        lwwSet.printSets()
