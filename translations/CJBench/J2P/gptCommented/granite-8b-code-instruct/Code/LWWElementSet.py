
import sys

# Class representing an element with a key, timestamp, and bias
class Element:
    def __init__(self, key, timestamp, bias):
        self.key = key
        self.timestamp = timestamp
        self.bias = bias

# Enum representing the type of operation: addition or removal
class Bias:
    ADDS = 1
    REMOVALS = 2

# Main class implementing the Last Write Wins (LWW) set
class Main:
    def __init__(self):
        self.add_set = {} # Initialize the add set
        self.remove_set = {} # Initialize the remove set

    # Method to add an element to the add set
    def add(self, e):
        self.add_set[e.key] = e # Store the element in the add set

    # Method to remove an element from the remove set if it exists in the add set
    def remove(self, e):
        if self.lookup(e): # Check if the element exists in the add set
            self.remove_set[e.key] = e # Store the element in the remove set

    # Method to check if an element is present in the add set and not removed
    def lookup(self, e):
        in_add_set = self.add_set.get(e.key) # Get the element from the add set
        in_remove_set = self.remove_set.get(e.key) # Get the element from the remove set
        # Return true if the element is in the add set and either not in the remove set or has a later timestamp
        return in_add_set is not None and (in_remove_set is None or in_add_set.timestamp > in_remove_set.timestamp)

    # Method to compare the current LWW set with another LWW set
    def compare(self, other):
        # Check if the other set contains all keys from the current add and remove sets
        return set(other.add_set.keys()).issubset(self.add_set.keys()) and set(other.remove_set.keys()).issubset(self.remove_set.keys())

    # Method to merge another LWW set into the current set
    def merge(self, other):
        # Merge elements from the other add set
        for e in other.add_set.values():
            # Add the element if it's not present or has a later timestamp
            if self.add_set.get(e.key) is None or self.compare_timestamps(self.add_set[e.key], e):
                self.add_set[e.key] = e
        # Merge elements from the other remove set
        for e in other.remove_set.values():
            # Add the element if it's not present or has a later timestamp
            if self.remove_set.get(e.key) is None or self.compare_timestamps(self.remove_set[e.key], e):
                self.remove_set[e.key] = e

    # Method to compare timestamps of two elements
    def compare_timestamps(self, e, other):
        # Check if the biases of the two elements are the same
        if e.bias!= other.bias:
            raise ValueError("Invalid bias value") # Throw an exception if biases differ
        bias = e.bias # Get the bias of the first element
        timestamp_comparison = e.timestamp < other.timestamp # Compare timestamps
        # If timestamps are equal, return false for ADDS bias, true for REMOVALS bias
        if timestamp_comparison == 0:
            return bias!= Bias.ADDS
        # Return true if the first element's timestamp is less than the second's
        return timestamp_comparison

    # Method to print the contents of the add and remove sets
    def print_sets(self):
        print("Add Set:", self.add_set.keys()) # Print keys of the add set
        print("Remove Set:", self.remove_set.keys()) # Print keys of the remove set

# Main method to execute the program
def main():
    operations = int(input()) # Read the number of operations
    for _ in range(operations):
        command = input().split() # Read the command (ADD or REMOVE) and the remaining arguments
        if command[0] == "ADD":
            key, timestamp, bias = command[1], int(command[2]), Bias[command[3]] # Extract the arguments
            element = Element(key, timestamp, bias) # Create a new Element
            lww_set.add(element) # Add the element to the set
        elif command[0] == "REMOVE":
            key, timestamp, bias = command[1], int(command[2]), Bias[command[3]] # Extract the arguments
            element = Element(key, timestamp, bias) # Create a new Element
            lww_set.remove(element) # Remove the element from the set
    lookup_count = int(input()) # Read the number of lookups to perform
    for _ in range(lookup_count):
        key = input() # Read the key to lookup
        lookup_element = Element(key, 0, Bias.ADDS) # Create a lookup Element
        # Print the result of the lookup
        print("Lookup", key, ":", lww_set.lookup(lookup_element))
    lww_set.print_sets() # Print the contents of the add and remove sets

if __name__ == "__main__":
    main() # Execute the main method

