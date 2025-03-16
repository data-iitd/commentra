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

    def effect(self, element_or_pairs, unique_tag=None):
        if unique_tag is not None:
            pair = Pair(element_or_pairs, unique_tag)
            self.elements.add(pair)
            self.elements.difference_update(self.tombstones)
        else:
            self.elements.difference_update(element_or_pairs)
            self.tombstones.update(element_or_pairs)

    def generate_unique_tag(self):
        import uuid
        return str(uuid.uuid4())

    def main(self):
        import sys
        input_lines = sys.stdin.readlines()
        operations = int(input_lines[0].strip())
        for i in range(1, operations + 1):
            operation, element = input_lines[i].strip().split()
            if operation.upper() == "ADD":
                self.add(element)
            elif operation.upper() == "REMOVE":
                self.remove(element)
            else:
                print(f"Invalid operation: {operation}")
        check_element = input_lines[-1].strip()
        print(f"Contains {check_element}: {self.contains(check_element)}")
        print(f"Elements in Main: {self.elements()}")


if __name__ == "__main__":
    main_instance = Main()
    main_instance.main()
