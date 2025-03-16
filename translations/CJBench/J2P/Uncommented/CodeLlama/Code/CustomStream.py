import sys
import io

class Main:
    def __init__(self, list):
        self.list = list

    def filter(self, predicate):
        self.list = list(filter(predicate, self.list))
        return self

    def map(self, mapper):
        return Main(list(map(mapper, self.list)))

    def collectToList(self):
        return self.list

if __name__ == "__main__":
    n = int(input())
    list = []
    for i in range(n):
        x, y = map(int, input().split())
        list.append(Item(x, y))
    stream = Main(list)
    result = stream \
        .filter(lambda item: item.y > 10) \
        .map(lambda item: item.x) \
        .collectToList()
    print(result)

class Item:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return "Item{" + "x=" + str(self.x) + ", y=" + str(self.y) + "}"

    def __repr__(self):
        return str(self)

    @property
    def x(self):
        return self._x

    @x.setter
    def x(self, value):
        self._x = value

    @property
    def y(self):
        return self._y

    @y.setter
    def y(self, value):
        self._y = value

