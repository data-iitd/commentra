from typing import List, Callable, TypeVar, Generic

T = TypeVar('T')
R = TypeVar('R')

class Main(Generic[T]):
    def __init__(self, lst: List[T]):
        self.lst = lst
        self.actions: List[Callable[['Main[T]'], None]] = []

    def filter(self, predicate: Callable[[T], bool]) -> 'Main[T]':
        self.actions.append(lambda stream: stream._apply_filter(predicate))
        return self

    def _apply_filter(self, predicate: Callable[[T], bool]) -> None:
        self.lst = [item for item in self.lst if predicate(item)]

    def map(self, mapper: Callable[[T], R]) -> 'Main[R]':
        mapped_list = [mapper(item) for item in self.lst]
        return Main(mapped_list)

    def collect_to_list(self) -> List[T]:
        for action in self.actions:
            action(self)
        return self.lst

class Item:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y

    def get_x(self) -> int:
        return self.x

    def get_y(self) -> int:
        return self.y

    def __repr__(self) -> str:
        return f"Item(x={self.x}, y={self.y})"

if __name__ == "__main__":
    n = int(input())
    lst = []
    for _ in range(n):
        x, y = map(int, input().split())
        lst.append(Item(x, y))
    
    stream = Main(lst)
    result = stream.filter(lambda item: item.get_y() > 10) \
                   .map(Item.get_x) \
                   .collect_to_list()
    
    print(result)

# <END-OF-CODE>
