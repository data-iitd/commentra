from typing import List, Callable, TypeVar

T = TypeVar('T')
R = TypeVar('R')

class Main:
    def __init__(self, items: List[T]):
        self.items = items
        self.actions: List[Callable[['Main'], None]] = []

    def filter(self, predicate: Callable[[T], bool]) -> 'Main':
        self.actions.append(lambda stream: stream._apply_filter(predicate))
        return self

    def _apply_filter(self, predicate: Callable[[T], bool]):
        self.items = [item for item in self.items if predicate(item)]

    def map(self, mapper: Callable[[T], R]) -> 'Main[R]':
        mapped_list = [mapper(item) for item in self.items]
        return Main(mapped_list)

    def collect_to_list(self) -> List[T]:
        for action in self.actions:
            action(self)
        return self.items

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

def main():
    n = int(input("Enter the number of items: "))
    items = []

    for _ in range(n):
        x, y = map(int, input("Enter x and y: ").split())
        items.append(Item(x, y))

    stream = Main(items)

    result = stream.filter(lambda item: item.get_y() > 10) \
                   .map(lambda item: item.get_x()) \
                   .collect_to_list()

    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
