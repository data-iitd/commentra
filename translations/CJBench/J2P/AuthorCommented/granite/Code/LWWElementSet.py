
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
        return inAddSet and (not inRemoveSet or inAddSet.timestamp > inRemoveSet.timestamp)

    def compare(self, other):
        return other.addSet.keys() <= self.addSet.keys() and other.removeSet.keys() <= self.removeSet.keys()

    def merge(self, other):
        for e in other.addSet.values():
            if not self.addSet.get(e.key) or self.compareTimestamps(self.addSet[e.key], e):
                self.addSet[e.key] = e

        for e in other.removeSet.values():
            if not self.removeSet.get(e.key) or self.compareTimestamps(self.removeSet[e.key], e):
                self.removeSet[e.key] = e

    def compareTimestamps(self, e, other):
        if e.bias!= other.bias:
            raise ValueError("Invalid bias value")
        bias = e.bias
        timestampComparison = e.timestamp < other.timestamp
        if timestampComparison == 0:
            return bias!= "ADDS"
        return timestampComparison

    def printSets(self):
        print("Add Set:", self.addSet.keys())
        print("Remove Set:", self.removeSet.keys())

if __name__ == "__main__":
    operations = int(input())
    main = Main()

    for _ in range(operations):
        command, key, timestamp, bias = input().split()
        element = Element(key, int(timestamp), bias)

        if command == "ADD":
            main.add(element)
        elif command == "REMOVE":
            main.remove(element)

    lookupCount = int(input())
    for _ in range(lookupCount):
        key = input()
        lookupElement = Element(key, 0, "ADDS")
        print("Lookup", key, ":", main.lookup(lookupElement))

    main.printSets()

