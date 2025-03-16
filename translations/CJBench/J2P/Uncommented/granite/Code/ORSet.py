

class Main:
    def __init__(self):
        self.elements = set()
        self.tombstones = set()
    def contains(self, element):
        return any(pair.element == element for pair in self.elements)
    def elements(self):
        return {pair.element for pair in self.elements}
    def add(self, element):
        n = self.generate_unique_tag()
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
        self.elements -= self.tombstones
    def effect(self, pairs_to_remove):
        self.elements -= pairs_to_remove
        self.tombstones |= pairs_to_remove
    def generate_unique_tag(self):
        return str(uuid.uuid4())
    class Pair:
        def __init__(self, element, unique_tag):
            self.element = element
            self.unique_tag = unique_tag
if __name__ == "__main__":
    operations = int(input())
    or_set = Main()
    for _ in range(operations):
        operation, element = input().split()
        if operation.upper() == "ADD":
            or_set.add(element)
        elif operation.upper() == "REMOVE":
            or_set.remove(element)
        else:
            print("Invalid operation: " + operation)
    check_element = input()
    print("Contains " + check_element + ": " + str(or_set.contains(check_element)))
    print("Elements in Main: " + str(or_set.elements()))
