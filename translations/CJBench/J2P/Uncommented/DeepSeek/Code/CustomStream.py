from typing import List, Generic, TypeVar, Callable, Iterable

T = TypeVar('T')
R = TypeVar('R')

class Main(Generic[T]):
    def __init__(self, list: List[T]):
        self.list = list
        self.actions: List[Callable[[Main[T]], None]] = []

    def filter(self, predicate: Callable[[T], bool]) -> 'Main[T]':
        self.actions.append(lambda stream: stream.list.extend([item for item in stream.list if predicate(item)]))
        return self

    def map(self, mapper: Callable[[T], R]) -> 'Main[R]':
        mapped_list = [mapper(item) for item in self.list]
        return Main(mapped_list)

    def collect_to_list(self) -> List[T]:
        for action in self.actions:
            action(self)
        return self.list

    @staticmethod
    def main(args: List[str]):
        import sys
        input = sys.stdin.readline
        n = int(input())
        items = [Item(int(x), int(y)) for x, y in zip(input().split(), input().split())]
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
        return f"Item{{x={self.x}, y={self.y}}}"

Main.main([])  # Call the main method
