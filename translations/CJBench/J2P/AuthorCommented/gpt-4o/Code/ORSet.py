import uuid

class Main:
    """
    Main (Observed-Removed Set) is a state-based CRDT (Conflict-free Replicated Data Type)
    that supports both addition and removal of elements. This particular implementation follows
    the Add-Wins strategy, meaning that in case of conflicting add and remove operations,
    the add operation takes precedence. The merge operation of two OR-Sets ensures that
    elements added at any replica are eventually observed at all replicas. Removed elements,
    once observed, are never reintroduced.
    This OR-Set implementation provides methods for adding elements, removing elements,
    checking for element existence, retrieving the set of elements, comparing with other OR-Sets,
    and merging with another OR-Set to create a new OR-Set containing all unique elements
    from both sets.
    """

    class Pair:
        def __init__(self, element, unique_tag):
            self.element = element
            self.unique_tag = unique_tag

        def get_element(self):
            return self.element

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
        pair = self.Pair(element, n)
        self.elements.add(pair)
        self.elements.difference_update(self.tombstones)

    def effect(self, pairs_to_remove):
        self.elements.difference_update(pairs_to_remove)
        self.tombstones.update(pairs_to_remove)

    def generate_unique_tag(self):
        return str(uuid.uuid4())

if __name__ == "__main__":
    import sys

    or_set = Main()

    operations = int(sys.stdin.readline().strip())

    for _ in range(operations):
        input_line = sys.stdin.readline().strip().split(" ")
        operation = input_line[0]
        element = input_line[1]

        if operation.upper() == "ADD":
            or_set.add(element)
        elif operation.upper() == "REMOVE":
            or_set.remove(element)
        else:
            print(f"Invalid operation: {operation}")

    check_element = sys.stdin.readline().strip()

    print(f"Contains {check_element}: {or_set.contains(check_element)}")
    print(f"Elements in Main: {or_set.elements()}")

# <END-OF-CODE>
