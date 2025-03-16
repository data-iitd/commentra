
import collections
import sys

class Main:
    def __init__(self, capacity):
        if capacity <= 0:
            raise ValueError("Capacity must be greater than 0.")
        self.capacity = capacity
        self.data = collections.OrderedDict()

    def get(self, key):
        if key not in self.data:
            return None
        value = self.data[key]
        del self.data[key]
        self.data[key] = value
        return value

    def put(self, key, value):
        if key in self.data:
            del self.data[key]
        elif len(self.data) == self.capacity:
            self.data.popitem(last=False)
        self.data[key] = value

if __name__ == "__main__":
    main = Main(int(sys.stdin.readline()))
    for _ in range(int(sys.stdin.readline())):
        operation = sys.stdin.readline().strip()
        if operation.startswith("GET"):
            key = int(operation.split()[1])
            print(main.get(key))
        else:
            key, value = map(int, operation.split()[1:])
            main.put(key, value)

