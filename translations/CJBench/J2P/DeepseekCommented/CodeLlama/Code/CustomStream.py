import sys

class Main:
    def __init__(self, list):
        self.list = list
        self.actions = []

    def filter(self, predicate):
        self.actions.append(lambda stream: {
            result = []
            for item in stream.list:
                if predicate(item):
                    result.append(item)
            stream.list = result
        })
        return self

    def map(self, mapper):
        mapped_list = []
        for item in self.list:
            mapped_list.append(mapper(item))
        return Main(mapped_list)

    def collect_to_list(self):
        for action in self.actions:
            action(self)
        return self.list

def main():
    scanner = sys.stdin
    n = int(scanner.readline())
    list = []
    for i in range(n):
        x, y = map(int, scanner.readline().split())
        list.append(Item(x, y))
    stream = Main(list)
    result = stream \
        .filter(lambda item: item.y > 10) \
        .map(lambda item: item.x) \
        .collect_to_list()
    print(result)

class Item:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def get_x(self):
        return self.x

    def get_y(self):
        return self.y

    def __str__(self):
        return f"Item{{x={self.x}, y={self.y}}}"

if __name__ == "__main__":
    main()

