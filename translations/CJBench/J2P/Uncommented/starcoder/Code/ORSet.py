
import uuid
class Main:
    def __init__(self):
        self.elements = set()
        self.tombstones = set()
    def contains(self, element):
        return any(pair.element == element for pair in self.elements)
    def elements(self):
        return {pair.element for pair in self.elements}
    def add(self, element):
        n = self.generateUniqueTag()
        self.effect(element, n)
    def remove(self, element):
        pairsToRemove = self.prepare(element)
        self.effect(pairsToRemove)
    def prepare(self, element):
        return {pair for pair in self.elements if pair.element == element}
    def effect(self, element, n):
        pair = Pair(element, n)
        self.elements.add(pair)
        self.elements.difference_update(self.tombstones)
    def effect(self, pairsToRemove):
        self.elements.difference_update(pairsToRemove)
        self.tombstones.update(pairsToRemove)
    def generateUniqueTag(self):
        return str(uuid.uuid4())
    class Pair:
        def __init__(self, element, uniqueTag):
            self.element = element
            self.uniqueTag = uniqueTag
if __name__ == "__main__":
    main = Main()
    operations = int(input())
    for i in range(operations):
        input = input().split(" ")
        operation = input[0]
        element = input[1]
        if operation.lower() == "add":
            main.add(element)
        elif operation.lower() == "remove":
            main.remove(element)
        else:
            print("Invalid operation: " + operation)
    checkElement = input()
    print("Contains " + checkElement + ": " + str(main.contains(checkElement)))
    print("Elements in Main: " + str(main.elements()))

