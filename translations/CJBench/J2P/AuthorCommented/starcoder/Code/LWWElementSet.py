import java.util.*;
import java.util.HashMap;

class Element:
    def __init__(self, key, timestamp, bias):
        self.key = key
        self.timestamp = timestamp
        self.bias = bias

class Main:
    def __init__(self):
        self.addSet = HashMap()
        self.removeSet = HashMap()

    def add(self, e):
        self.addSet.put(e.key, e)

    def remove(self, e):
        if self.lookup(e):
            self.removeSet.put(e.key, e)

    def lookup(self, e):
        inAddSet = self.addSet.get(e.key)
        inRemoveSet = self.removeSet.get(e.key)
        return (inAddSet!= None and (inRemoveSet == None or inAddSet.timestamp > inRemoveSet.timestamp))

    def compare(self, other):
        return other.addSet.keySet().containsAll(self.addSet.keySet()) and other.removeSet.keySet().containsAll(self.removeSet.keySet())

    def merge(self, other):
        for e in other.addSet.values():
            if not self.addSet.containsKey(e.key) or self.compareTimestamps(self.addSet.get(e.key), e):
                self.addSet.put(e.key, e)

        for e in other.removeSet.values():
            if not self.removeSet.containsKey(e.key) or self.compareTimestamps(self.removeSet.get(e.key), e):
                self.removeSet.put(e.key, e)

    def compareTimestamps(self, e, other):
        if e.bias!= other.bias:
            raise IllegalArgumentException("Invalid bias value")
        bias = e.bias
        timestampComparison = Integer.compare(e.timestamp, other.timestamp)

        if timestampComparison == 0:
            return bias!= Bias.ADDS
        return timestampComparison < 0

    def printSets(self):
        print("Add Set: " + self.addSet.keySet())
        print("Remove Set: " + self.removeSet.keySet())

if __name__ == "__main__":
    scanner = Scanner(System.in)
    lwwSet = Main()

    operations = scanner.nextInt()
    scanner.nextLine() # Consume newline

    for i in range(operations):
        command = scanner.next()
        key = scanner.next()
        timestamp = scanner.nextInt()
        bias = Bias.valueOf(scanner.next())
        element = Element(key, timestamp, bias)

        if command.equals("ADD"):
            lwwSet.add(element)
        else if command.equals("REMOVE"):
            lwwSet.remove(element)

    lookupCount = scanner.nextInt()
    scanner.nextLine() # Consume newline
    for i in range(lookupCount):
        key = scanner.next()
        lookupElement = Element(key, 0, Bias.ADDS)
        print("Lookup " + key + ": " + lwwSet.lookup(lookupElement))

    lwwSet.printSets()
    scanner.close()

