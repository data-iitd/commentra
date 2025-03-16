import collections

class Element:
    def __init__(self, key, timestamp, bias):
        self.key = key
        self.timestamp = timestamp
        self.bias = bias

class Main:
    def __init__(self):
        self.addSet = collections.defaultdict(Element)
        self.removeSet = collections.defaultdict(Element)

    def add(self, e):
        self.addSet[e.key] = e

    def remove(self, e):
        if self.lookup(e):
            self.removeSet[e.key] = e

    def lookup(self, e):
        inAddSet = self.addSet[e.key]
        inRemoveSet = self.removeSet[e.key]
        return (inAddSet!= None and (inRemoveSet == None or inAddSet.timestamp > inRemoveSet.timestamp))

    def compare(self, other):
        return other.addSet.keys() >= self.addSet.keys() and other.removeSet.keys() >= self.removeSet.keys()

    def merge(self, other):
        for e in other.addSet.values():
            if not self.addSet.has_key(e.key) or self.compareTimestamps(self.addSet[e.key], e):
                self.addSet[e.key] = e

        for e in other.removeSet.values():
            if not self.removeSet.has_key(e.key) or self.compareTimestamps(self.removeSet[e.key], e):
                self.removeSet[e.key] = e

    def compareTimestamps(self, e, other):
        if e.bias!= other.bias:
            raise ValueError("Invalid bias value")
        bias = e.bias
        timestampComparison = cmp(e.timestamp, other.timestamp)
        if timestampComparison == 0:
            return bias!= Bias.ADDS
        return timestampComparison < 0

    def printSets(self):
        print "Add Set: " + self.addSet.keys()
        print "Remove Set: " + self.removeSet.keys()

    def main(self):
        scanner = raw_input()
        operations = int(scanner.next())
        for i in range(operations):
            command = scanner.next()
            key = scanner.next()
            timestamp = int(scanner.next())
            bias = Bias.valueOf(scanner.next())
            element = Element(key, timestamp, bias)
            if command.equals("ADD"):
                self.add(element)
            else if command.equals("REMOVE"):
                self.remove(element)
        lookupCount = int(scanner.next())
        for i in range(lookupCount):
            key = scanner.next()
            lookupElement = Element(key, 0, Bias.ADDS)
            print "Lookup " + key + ": " + self.lookup(lookupElement)
        self.printSets()
        scanner.close()

# 