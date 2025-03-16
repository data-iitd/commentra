class Main:
    def __init__(self, items):
        self.items = items
        self.actions = []

    def filter(self, predicate):
        self.actions.append(lambda stream: stream.items = [item for item in stream.items if predicate(item)])
        return self

    def map(self, mapper):
        mapped_items = [mapper(item) for item in self.items]
        return Main(mapped_items)

    def collect_to_list(self):
        for action in self.actions:
            action(self)
        return self.items

    @staticmethod
    def main():
        import sys
        input = sys.stdin.read
        data = input().split()

        n = int(data[0])
        items = []

        for i in range(1, n + 1):
            x = int(data[i * 2 - 1])
            y = int(data[i * 2])
            items.append(Item(x, y))

        stream = Main(items)

        result = stream.filter(lambda item: item.y > 10).map(lambda item: item.x).collect_to_list()

        print(result)


class Item:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        return f"Item(x={self.x}, y={self.y})"


if __name__ == "__main__":
    Main.main()
