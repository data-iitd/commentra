
import sys

class Main:
    def __init__(self, list):
        self.list = list
        self.actions = []

    def filter(self, predicate):
        self.actions.append(lambda stream: {
            item for item in stream.list if predicate(item)
        })
        return self

    def map(self, mapper):
        return Main([mapper(item) for item in self.list])

    def collectToList(self):
        for action in self.actions:
            self.list = action(self)
        return self.list

if __name__ == "__main__":
    n = int(input())
    list = []
    for _ in range(n):
        x, y = map(int, input().split())
        list.append((x, y))

    stream = Main(list)

    result = stream \
       .filter(lambda item: item[1] > 10) \
       .map(lambda item: item[0]) \
       .collectToList()

    print(result)

