from enum import Enum
from collections import defaultdict

# Enum representing the type of operation: addition or removal
class Bias(Enum):
    ADDS = 1
    REMOVALS = 2

# Class representing an element with a key, timestamp, and bias
class Element:
    def __init__(self, key, timestamp, bias):
        self.key = key  # Unique identifier for the element
        self.timestamp = timestamp  # Timestamp indicating the time of the operation
        self.bias = bias  # Bias indicating whether the operation is an addition or removal

# Main class implementing the Last Write Wins (LWW) set
class LWWSet:
    def __init__(self):
        self.add_set = {}  # Dictionary to store added elements
        self.remove_set = {}  # Dictionary to store removed elements

    # Method to add an element to the add set
    def add(self, e):
        self.add_set[e.key] = e  # Store the element in the add set

    # Method to remove an element from the remove set if it exists in the add set
    def remove(self, e):
        if self.lookup(e):  # Check if the element exists in the add set
            self.remove_set[e.key] = e  # Store the element in the remove set

    # Method to check if an element is present in the add set and not removed
    def lookup(self, e):
        in_add_set = self.add_set.get(e.key)  # Get the element from the add set
        in_remove_set = self.remove_set.get(e.key)  # Get the element from the remove set
        # Return true if the element is in the add set and either not in the remove set or has a later timestamp
        return (in_add_set is not None and (in_remove_set is None or in_add_set.timestamp > in_remove_set.timestamp))

    # Method to compare the current LWW set with another LWW set
    def compare(self, other):
        # Check if the other set contains all keys from the current add and remove sets
        return (set(other.add_set.keys()).issuperset(self.add_set.keys()) and
                set(other.remove_set.keys()).issuperset(self.remove_set.keys()))

    # Method to merge another LWW set into the current set
    def merge(self, other):
        # Merge elements from the other add set
        for e in other.add_set.values():
            # Add the element if it's not present or has a later timestamp
            if e.key not in self.add_set or self.compare_timestamps(self.add_set[e.key], e):
                self.add_set[e.key] = e
        # Merge elements from the other remove set
        for e in other.remove_set.values():
            # Add the element if it's not present or has a later timestamp
            if e.key not in self.remove_set or self.compare_timestamps(self.remove_set[e.key], e):
                self.remove_set[e.key] = e

    # Method to compare timestamps of two elements
    def compare_timestamps(self, e, other):
        # Check if the biases of the two elements are the same
        if e.bias != other.bias:
            raise ValueError("Invalid bias value")  # Raise an exception if biases differ
        bias = e.bias  # Get the bias of the first element
        timestamp_comparison = (e.timestamp > other.timestamp) - (e.timestamp < other.timestamp)  # Compare timestamps
        # If timestamps are equal, return false for ADDS bias, true for REMOVALS bias
        if timestamp_comparison == 0:
            return bias != Bias.ADDS
        # Return true if the first element's timestamp is less than the second's
        return timestamp_comparison < 0

    # Method to print the contents of the add and remove sets
    def print_sets(self):
        print("Add Set:", list(self.add_set.keys()))  # Print keys of the add set
        print("Remove Set:", list(self.remove_set.keys()))  # Print keys of the remove set

# Main execution
if __name__ == "__main__":
    lww_set = LWWSet()  # Create an instance of the LWW set
    operations = int(input())  # Read the number of operations

    # Process each operation
    for _ in range(operations):
        command, key, timestamp, bias = input().split()
        timestamp = int(timestamp)  # Convert timestamp to integer
        bias = Bias[bias]  # Convert bias to Bias enum
        element = Element(key, timestamp, bias)  # Create a new Element

        # Execute the command based on its type
        if command == "ADD":
            lww_set.add(element)  # Add the element to the set
        elif command == "REMOVE":
            lww_set.remove(element)  # Remove the element from the set

    # Read the number of lookups to perform
    lookup_count = int(input())

    # Perform each lookup
    for _ in range(lookup_count):
        key = input()  # Read the key to lookup
        lookup_element = Element(key, 0, Bias.ADDS)  # Create a lookup Element
        # Print the result of the lookup
        print(f"Lookup {key}: {lww_set.lookup(lookup_element)}")

    # Print the contents of the add and remove sets
    lww_set.print_sets()
