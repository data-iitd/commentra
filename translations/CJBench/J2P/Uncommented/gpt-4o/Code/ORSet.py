import uuid

class Pair:
    def __init__(self, element, unique_tag):
        self.element = element
        self.unique_tag = unique_tag

    def get_element(self):
        return self.element

class Main:
    def __init__(self):
        self.elements = set()
        self.tombstones = set()

    def contains(self, element):
        return any(pair.get_element() == element for pair in self.elements)

    def elements(self):
        return {pair.get_element() for pair in self.elements}

    def add(self, element):
        n = self.generate_unique_tag()
        self.effect(element, n)

    def remove(self, element):
        pairs_to_remove = self.prepare(element)
        self.effect(pairs_to_remove)

    def prepare(self, element):
        return {pair for pair in self.elements if pair.get_element() == element}

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
    import sys
    input = sys.stdin.read
    data = input().strip().splitlines()
    
    or_set = Main()
    operations = int(data[0])
    
    for i in range(1, operations + 1):
        operation, element = data[i].split()
        if operation.upper() == "ADD":
            or_set.add(element)
        elif operation.upper() == "REMOVE":
            or_set.remove(element)
        else:
            print(f"Invalid operation: {operation}")

    check_element = data[operations + 1]
    print(f"Contains {check_element}: {or_set.contains(check_element)}")
    print(f"Elements in Main: {or_set.elements()}")

# <END-OF-CODE>
