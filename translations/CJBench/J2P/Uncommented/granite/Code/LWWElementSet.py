
import sys
class Element:
    def __init__(self, key, timestamp, bias):
        self.key = key
        self.timestamp = timestamp
        self.bias = bias
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
        return (inAddSet is not None and (inRemoveSet is None or inAddSet.timestamp > inRemoveSet.timestamp))
    def compare(self, other):
        return other.addSet.keys() >= self.addSet.keys() and other.removeSet.keys() >= self.removeSet.keys()
    def merge(self, other):
        for e in other.addSet.values():
            if self.addSet.get(e.key) is None or self.compareTimestamps(self.addSet[e.key], e):
                self.addSet[e.key] = e
        for e in other.removeSet.values():
            if self.removeSet.get(e.key) is None or self.compareTimestamps(self.removeSet[e.key], e):
                self.removeSet[e.key] = e
    def compareTimestamps(self, e, other):
        if e.bias!= other.bias:
            raise ValueError("Invalid bias value")
        bias = e.bias
        timestampComparison = e.timestamp - other.timestamp
        if timestampComparison == 0:
            return bias!= Element.Bias.ADDS
        return timestampComparison < 0
    def printSets(self):
        print("Add Set: " + str(self.addSet.keys()))
        print("Remove Set: " + str(self.removeSet.keys()))
if __name__ == "__main__":
    operations = int(input())
    lwwSet = Main()
    for i in range(operations):
        command, key, timestamp, bias = input().split()
        element = Element(key, int(timestamp), Element.Bias[bias])
        if command == "ADD":
            lwwSet.add(element)
        elif command == "REMOVE":
            lwwSet.remove(element)
    lookupCount = int(input())
    for i in range(lookupCount):
        key = input()
        lookupElement = Element(key, 0, Element.Bias.ADDS)
        print("Lookup " + key + ": " + str(lwwSet.lookup(lookupElement)))
    lwwSet.printSets()