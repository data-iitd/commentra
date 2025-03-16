import collections
import enum

# Class representing an element with a key, timestamp, and bias
class Element:
    def __init__(self, key, timestamp, bias):
        self.key = key
        self.timestamp = timestamp
        self.bias = bias

# Enum representing the type of operation: addition or removal
class Bias(enum.Enum):
    ADDS = 1
    REMOVALS = 2

# Main class implementing the Last Write Wins (LWW) set
class Main:
    def __init__(self):
        self.add_set = collections.defaultdict(Element)
        self.remove_set = collections.defaultdict(Element)

    # Method to add an element to the add set
    def add(self, e):
        self.add_set[e.key] = e

    # Method to remove an element from the remove set if it exists in the add set
    def remove(self, e):
        if self.lookup(e):
            self.remove_set[e.key] = e

    # Method to check if an element is present in the add set and not removed
    def lookup(self, e):
        in_add_set = self.add_set[e.key]
        in_remove_set = self.remove_set[e.key]
        # Return true if the element is in the add set and either not in the remove set or has a later timestamp
        return (in_add_set!= None and (in_remove_set == None or in_add_set.timestamp > in_remove_set.timestamp))

    # Method to compare the current LWW set with another LWW set
    def compare(self, other):
        # Check if the other set contains all keys from the current add and remove sets
        return other.add_set.keys() >= self.add_set.keys() and other.remove_set.keys() >= self.remove_set.keys()

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
        if e.bias!= other.bias:
            raise ValueError("Invalid bias value") # Throw an exception if biases differ
        bias = e.bias
        timestamp_comparison = e.timestamp - other.timestamp
        # If timestamps are equal, return false for ADDS bias, true for REMOVALS bias
        if timestamp_comparison == 0:
            return bias!= Bias.ADDS
        # Return true if the first element's timestamp is less than the second's
        return timestamp_comparison < 0

    # Method to print the contents of the add and remove sets
    def print_sets(self):
        print("Add Set: " + str(self.add_set.keys()))
        print("Remove Set: " + str(self.remove_set.keys()))

    # Main method to execute the program
    def main():
        scanner = input()
        lww_set = Main()
        operations = int(scanner.next())
        scanner.next()

        # Process each operation
        for i in range(operations):
            command = scanner.next()
            key = scanner.next()
            timestamp = int(scanner.next())
            bias = Bias[scanner.next()]
            element = Element(key, timestamp, bias)

            # Execute the command based on its type
            if command == "ADD":
                lww_set.add(element)
            elif command == "REMOVE":
                lww_set.remove(element)

        # Read the number of lookups to perform
        lookup_count = int(scanner.next())
        scanner.next()

        # Perform each lookup
        for i in range(lookup_count):
            key = scanner.next()
            lookup_element = Element(key, 0, Bias.ADDS)
            # Print the result of the lookup
            print("Lookup " + key + ": " + str(lww_set.lookup(lookup_element)))

        # Print the contents of the add and remove sets
        lww_set.print_sets()
        scanner.close()

# 