from enum import Enum
from collections import defaultdict

class Bias(Enum):
    ADDS = "ADDS"
    REMOVALS = "REMOVALS"

class Element:
    def __init__(self, key, timestamp, bias):
        self.key = key
        self.timestamp = timestamp
        self.bias = bias

class Main:
    def __init__(self):
        self.add_set = {}
        self.remove_set = {}

    def add(self, e):
        self.add_set[e.key] = e

    def remove(self, e):
        if self.lookup(e):
            self.remove_set[e.key] = e

    def lookup(self, e):
        in_add_set = self.add_set.get(e.key)
        in_remove_set = self.remove_set.get(e.key)
        return in_add_set is not None and (in_remove_set is None or in_add_set.timestamp > in_remove_set.timestamp)

    def compare(self, other):
        return (set(other.add_set.keys()).issuperset(self.add_set.keys()) and
                set(other.remove_set.keys()).issuperset(self.remove_set.keys()))

    def merge(self, other):
        for e in other.add_set.values():
            if e.key not in self.add_set or self.compare_timestamps(self.add_set[e.key], e):
                self.add_set[e.key] = e

        for e in other.remove_set.values():
            if e.key not in self.remove_set or self.compare_timestamps(self.remove_set[e.key], e):
                self.remove_set[e.key] = e

    def compare_timestamps(self, e, other):
        if e.bias != other.bias:
            raise ValueError("Invalid bias value")
        bias = e.bias
        timestamp_comparison = (e.timestamp > other.timestamp) - (e.timestamp < other.timestamp)

        if timestamp_comparison == 0:
            return bias != Bias.ADDS
        return timestamp_comparison < 0

    def print_sets(self):
        print("Add Set:", list(self.add_set.keys()))
        print("Remove Set:", list(self.remove_set.keys()))

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    lww_set = Main()
    operations = int(data[0])

    for i in range(1, operations + 1):
        command, key, timestamp, bias = data[i].split()
        timestamp = int(timestamp)
        element = Element(key, timestamp, Bias[bias])
        
        if command == "ADD":
            lww_set.add(element)
        elif command == "REMOVE":
            lww_set.remove(element)

    lookup_count = int(data[operations + 1])
    for i in range(operations + 2, operations + 2 + lookup_count):
        key = data[i]
        lookup_element = Element(key, 0, Bias.ADDS)
        print(f"Lookup {key}: {lww_set.lookup(lookup_element)}")

    lww_set.print_sets()

# <END-OF-CODE>
