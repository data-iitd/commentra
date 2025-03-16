from typing import List, Callable, Generic, TypeVar
from abc import ABC, abstractmethod

T = TypeVar('T')
R = TypeVar('R')

class Action(ABC, Generic[T]):
    @abstractmethod
    def apply(self, stream: 'Main[T]'):
        pass

class Main(Generic[T]):
    def __init__(self, list: List[T]):
        self.list = list
        self.actions: List[Action[T]] = []

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
    def main():
        import sys
        input = sys.stdin.read
        data = input().split()
        n = int(data[0])
        items = []
        for i in range(1, n + 1):
            x = int(data[i * 2])
            y = int(data[i * 2 + 1])
            items.append(Item(x, y))
        stream = Main(items)
        result = stream.filter(lambda item: item.y > 10).map(lambda item: item.x).collect_to_list()
        print(result)

    class Item:
        def __init__(self, x: int, y: int):
            self.x = x
            self.y = y

        @property
        def x(self) -> int:
            return self._x

        @x.setter
        def x(self, value: int):
            self._x = value

        @property
        def y(self) -> int:
            return self._y

        @y.setter
        def y(self, value: int):
            self._y = value

        def __repr__(self):
            return f"Item(x={self.x}, y={self.y})"

Main.main()
