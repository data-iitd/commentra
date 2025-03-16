
import uuid

class Pair:
    def __init__(self, element, unique_tag):
        self.element = element
        self.unique_tag = unique_tag

class Main:
    def __init__(self):
        self.elements = set()
        self.tombstones = set()

    def contains(self, element):
        return any(pair.element == element for pair in self.elements)

    def elements(self):
        result = set()
        for pair in self.elements:
            result.add(pair.element)
        return result

    def add(self, element):
        n = str(uuid.uuid4())
        self.effect(element, n)

    def remove(self, element):
        pairs_to_remove = self.prepare(element)
        self.effect(pairs_to_remove)

    def prepare(self, element):
        pairs_to_remove = set()
        for pair in self.elements:
            if pair.element == element:
                pairs_to_remove.add(pair)
        return pairs_to_remove

    def effect(self, element, n):
        pair = Pair(element, n)
        self.elements.add(pair)
        self.elements.difference_update(self.tombstones)

    def effect(self, pairs_to_remove):
        self.elements.difference_update(pairs_to_remove)
        self.tombstones.update(pairs_to_remove)

    def generate_unique_tag(self):
        return str(uuid.uuid4())

if __name__ == "__main__":
    or_set = Main()

    operations = int(input())

    for _ in range(operations):
        operation, element = input().split()

        if operation == "ADD":
            or_set.add(element)
        elif operation == "REMOVE":
            or_set.remove(element)
        else:
            print("Invalid operation:", operation)

    check_element = input()

    print("Contains", check_element, ":", or_set.contains(check_element))
    print("Elements in Main:", or_set.elements())

