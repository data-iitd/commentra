from enum import Enum
from collections import defaultdict
import sys

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
        self.addSet = defaultdict(list)
        self.removeSet = defaultdict(list)

    def add(self, e):
        self.addSet[e.key].append(e)

    def remove(self, e):
        if self.lookup(e):
            self.removeSet[e.key].append(e)

    def lookup(self, e):
        add_elements = self.addSet[e.key]
        remove_elements = self.removeSet[e.key]
        if add_elements and (not remove_elements or add_elements[-1].timestamp > remove_elements[-1].timestamp):
            return True
        return False

    def compare(self, other):
        return set(self.addSet.keys()).issubset(set(other.addSet.keys())) and set(self.removeSet.keys()).issubset(set(other.removeSet.keys()))

    def merge(self, other):
        for key, elements in other.addSet.items():
            if not self.addSet[key] or self.compare_timestamps(self.addSet[key][-1], elements[-1]):
                self.addSet[key].extend(elements)

        for key, elements in other.removeSet.items():
            if not self.removeSet[key] or self.compare_timestamps(self.removeSet[key][-1], elements[-1]):
                self.removeSet[key].extend(elements)

    def compare_timestamps(self, e, other):
        if e.bias != other.bias:
            raise ValueError("Invalid bias value")
        bias = e.bias
        timestamp_comparison = other.timestamp - e.timestamp

        if timestamp_comparison == 0:
            return bias == Bias.REMOVALS
        return timestamp_comparison < 0

    def print_sets(self):
        print("Add Set:", list(self.addSet.keys()))
        print("Remove Set:", list(self.removeSet.keys()))

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    lwwSet = Main()
    index = 0
    operations = int(data[index])
    index += 1

    for _ in range(operations):
        command = data[index]
        index += 1
        key = data[index]
        index += 1
        timestamp = int(data[index])
        index += 1
        bias = Bias(data[index])
        index += 1
        element = Element(key, timestamp, bias)

        if command == "ADD":
            lwwSet.add(element)
        elif command == "REMOVE":
            lwwSet.remove(element)

    lookup_count = int(data[index])
    index += 1
    for _ in range(lookup_count):
        key = data[index]
        index += 1
        lookup_element = Element(key, 0, Bias.ADDS)
        print("Lookup", key + ":", lwwSet.lookup(lookup_element))

    lwwSet.print_sets()
