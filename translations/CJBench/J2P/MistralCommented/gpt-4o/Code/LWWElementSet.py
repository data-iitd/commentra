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
class LWWSet:
    def __init__(self):
        # Initialize addSet and removeSet as empty dictionaries
        self.add_set = {}
        self.remove_set = {}

    # Method to add an element to the addSet
    def add(self, e):
        self.add_set[e.key] = e

    # Method to remove an element from the addSet
    def remove(self, e):
        if self.lookup(e):
            self.remove_set[e.key] = e
            del self.add_set[e.key]

    # Method to check if an element exists in the addSet or removeSet
    def lookup(self, e):
        in_add_set = self.add_set.get(e.key)
        in_remove_set = self.remove_set.get(e.key)
        return in_add_set is not None and (in_remove_set is None or in_add_set.timestamp > in_remove_set.timestamp)

    # Method to compare two LWWSet objects based on their add and remove sets
    def compare(self, other):
        return (set(other.add_set.keys()).issubset(set(self.add_set.keys())) and
                set(other.remove_set.keys()).issubset(set(self.remove_set.keys())))

    # Method to merge two LWWSet objects
    def merge(self, other):
        for e in other.add_set.values():
            if e.key not in self.add_set or self.compare_timestamps(self.add_set[e.key], e):
                self.add_set[e.key] = e
        for e in other.remove_set.values():
            if e.key not in self.remove_set or self.compare_timestamps(self.remove_set[e.key], e):
                self.remove_set[e.key] = e

    # Method to compare the timestamps of two Elements
    def compare_timestamps(self, e, other):
        if e.bias != other.bias:
            raise ValueError("Invalid bias value")
        timestamp_comparison = (e.timestamp > other.timestamp) - (e.timestamp < other.timestamp)
        return (e.bias != Bias.ADDS or timestamp_comparison > 0) and timestamp_comparison != 0

    # Method to print the addSet and removeSet
    def print_sets(self):
        print("Add Set:", list(self.add_set.keys()))
        print("Remove Set:", list(self.remove_set.keys()))

# Main method for testing the LWW Set implementation
if __name__ == "__main__":
    import sys

    # Create a new instance of the LWWSet class
    lww_set = LWWSet()

    # Read the number of operations from the input
    operations = int(sys.stdin.readline().strip())

    # Process each operation
    for _ in range(operations):
        command, key, timestamp, bias = sys.stdin.readline().strip().split()
        timestamp = int(timestamp)
        bias = Bias[bias]

        # Create a new Element based on the given command, key, timestamp, and bias
        element = Element(key, timestamp, bias)

        # Based on the command, add or remove the Element from the LWW Set
        if command == "ADD":
            lww_set.add(element)
        elif command == "REMOVE":
            lww_set.remove(element)

    # Read the number of lookups from the input
    lookup_count = int(sys.stdin.readline().strip())

    # Process each lookup
    for _ in range(lookup_count):
        key = sys.stdin.readline().strip()
        lookup_element = Element(key, 0, Bias.ADDS)

        # Perform a lookup on the LWW Set with the given key
        result = lww_set.lookup(lookup_element)
        # Print the result of the lookup
        print(f"Lookup {key}: {result}")

    # Print the addSet and removeSet
    lww_set.print_sets()

