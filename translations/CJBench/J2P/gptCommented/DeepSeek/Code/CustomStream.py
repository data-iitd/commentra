from typing import List, Generic, TypeVar, Callable, Iterable

T = TypeVar('T')
R = TypeVar('R')

class Main(Generic[T]):
    def __init__(self, items: List[T]):
        self.items = items
        self.actions = []

    def filter(self, predicate: Callable[[T], bool]) -> 'Main[T]':
        self.actions.append(lambda stream: stream.items.append([item for item in stream.items if predicate(item)]))
        return self

    def map(self, mapper: Callable[[T], R]) -> 'Main[R]':
        mapped_items = [mapper(item) for item in self.items]
        return Main(mapped_items)

    def collect_to_list(self) -> List[T]:
        for action in self.actions:
            action(self)
        return self.items

    @staticmethod
    def main():
        n = int(input())
        items = [Item(int(input()), int(input())) for _ in range(n)]
        stream = Main(items)
        result = stream.filter(lambda item: item.y > 10).map(lambda item: item.x).collect_to_list()
        print(result)

class Item:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y

    def get_x(self) -> int:
        return self.x

    def get_y(self) -> int:
        return self.y

    def __repr__(self):
        return f"Item(x={self.x}, y={self.y})"

Main.main()
