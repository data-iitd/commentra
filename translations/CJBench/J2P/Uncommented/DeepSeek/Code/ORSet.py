from typing import Generic, Set, TypeVar
import uuid

T = TypeVar('T')

class Main(Generic[T]):
    def __init__(self):
        self.elements: Set[Pair[T]] = set()
        self.tombstones: Set[Pair[T]] = set()

    def contains(self, element: T) -> bool:
        return any(pair.element == element for pair in self.elements)

    def elements(self) -> Set[T]:
        result: Set[T] = set()
        for pair in self.elements:
            result.add(pair.element)
        return result

    def add(self, element: T):
        n = self.generate_unique_tag()
        self.effect(element, n)

    def remove(self, element: T):
        pairs_to_remove = self.prepare(element)
        self.effect(pairs_to_remove)

    def prepare(self, element: T) -> Set[Pair[T]]:
        pairs_to_remove: Set[Pair[T]] = set()
        for pair in self.elements:
            if pair.element == element:
                pairs_to_remove.add(pair)
        return pairs_to_remove

    def effect(self, element: T, n: str):
        pair = Pair(element, n)
        self.elements.add(pair)
        self.elements.difference_update(self.tombstones)

    def effect(self, pairs_to_remove: Set[Pair[T]]):
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
    or_set = Main[str]()
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
