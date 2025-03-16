class Element:
    def __init__(self, key, timestamp, bias):
        self.key = key
        self.timestamp = timestamp
        self.bias = bias


class Bias(Enum):
    ADDS = 1
    REMOVALS = 2


class Main:
    def __init__(self):
        self.addSet = {}
        self.removeSet = {}

    def add(self, e):
        self.addSet[e.key] = e

    def remove(self, e):
        if self.lookup(e):
            self.removeSet[e.key] = e

    def lookup(self, e):
        inAddSet = self.addSet.get(e.key)
        inRemoveSet = self.removeSet.get(e.key)
        return inAddSet is not None and (inRemoveSet is None or inAddSet.timestamp > inRemoveSet.timestamp)

    def compare(self, other):
        return set(self.addSet.keys()).issubset(other.addSet.keys()) and set(self.removeSet.keys()).issubset(other.removeSet.keys())

    def merge(self, other):
        for e in other.addSet.values():
            if e.key not in self.addSet or self.compareTimestamps(self.addSet[e.key], e):
                self.addSet[e.key] = e
        for e in other.removeSet.values():
            if e.key not in self.removeSet or self.compareTimestamps(self.removeSet.get(e.key), e):
                self.removeSet[e.key] = e

    def compareTimestamps(self, e, other):
        if e.bias != other.bias:
            raise ValueError("Invalid bias value")
        bias = e.bias
        timestampComparison = e.timestamp - other.timestamp
        if timestampComparison == 0:
            return bias != Bias.ADDS
        return timestampComparison < 0

    def printSets(self):
        print("Add Set:", list(self.addSet.keys()))
        print("Remove Set:", list(self.removeSet.keys()))


if __name__ == "__main__":
    import sys
    input = sys.stdin.readline
    lwwSet = Main()
    operations = int(input())

    for _ in range(operations):
        command, key, timestamp, bias = input().split()
        timestamp = int(timestamp)
        element = Element(key, timestamp, Bias[bias])
        if command == "ADD":
            lwwSet.add(element)
        elif command == "REMOVE":
            lwwSet.remove(element)

    lookupCount = int(input())
    for _ in range(lookupCount):
        key = input().strip()
        lookupElement = Element(key, 0, Bias.ADDS)
        print(f"Lookup {key}: {lwwSet.lookup(lookupElement)}")

    lwwSet.printSets()
