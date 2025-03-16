import uuid
from typing import Set, Generic, TypeVar, Tuple

T = TypeVar('T')

class Main:

    def __init__(self):
        self.elements: Set[Tuple[T, str]] = set()
        self.tombstones: Set[Tuple[T, str]] = set()

    def contains(self, element: T) -> bool:
        return any(pair[0] == element for pair in self.elements)

    def elements(self) -> Set[T]:
        result: Set[T] = set()
        for pair in self.elements:
            if pair not in self.tombstones:
                result.add(pair[0])
        return result

    def add(self, element: T):
        n = self.generate_unique_tag()
        self.effect(element, n)

    def remove(self, element: T):
        pairs_to_remove = self.prepare(element)
        self.effect(pairs_to_remove)

    def prepare(self, element: T) -> Set[Tuple[T, str]]:
        return {pair for pair in self.elements if pair[0] == element}

    def effect(self, element: T, unique_tag: str):
        pair = (element, unique_tag)
        self.elements.add(pair)
        self.elements.difference_update(self.tombstones)

    def effect(self, pairs_to_remove: Set[Tuple[T, str]]):
        self.elements.difference_update(pairs_to_remove)
        self.tombstones.update(pairs_to_remove)

    def generate_unique_tag(self) -> str:
        return str(uuid.uuid4())

    class Pair(Generic[T]):
        def __init__(self, element: T, unique_tag: str):
            self.element = element
            self.unique_tag = unique_tag

        def get_element(self) -> T:
            return self.element

if __name__ == "__main__":
    or_set = Main()
    import sys
    input = sys.stdin.readline
    operations = int(input().strip())

    for _ in range(operations):
        operation, element = input().strip().split()
        if operation.upper() == "ADD":
            or_set.add(element)
        elif operation.upper() == "REMOVE":
            or_set.remove(element)
        else:
            print(f"Invalid operation: {operation}")

    check_element = input().strip()
    print(f"Contains {check_element}: {or_set.contains(check_element)}")
    print(f"Elements in Main: {or_set.elements()}")

