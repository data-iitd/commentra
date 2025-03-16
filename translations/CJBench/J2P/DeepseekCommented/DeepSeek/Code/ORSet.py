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
        return {pair for pair in self.elements if pair.element == element}

    def effect(self, element, n):
        pair = Pair(element, n)
        self.elements.add(pair)
        self.elements.difference_update(self.tombstones)

    def effect(self, pairs_to_remove):
        self.elements.difference_update(pairs_to_remove)
        self.tombstones.update(pairs_to_remove)

    def generate_unique_tag(self):
        import uuid
        return str(uuid.uuid4())


class Pair:
    def __init__(self, element, unique_tag):
        self.element = element
        self.unique_tag = unique_tag


if __name__ == "__main__":
    or_set = Main()
    import sys
    input_lines = sys.stdin.readlines()
    operations = int(input_lines[0].strip())
    for i in range(1, operations + 1):
        operation, element = input_lines[i].strip().split()
        if operation.upper() == "ADD":
            or_set.add(element)
        elif operation.upper() == "REMOVE":
            or_set.remove(element)
        else:
            print(f"Invalid operation: {operation}")
    check_element = input_lines[-1].strip()
    print(f"Contains {check_element}: {or_set.contains(check_element)}")
    print(f"Elements in Main: {or_set.elements()}")
