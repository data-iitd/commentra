

class Main:
    def __init__(self, capacity):
        if capacity <= 0:
            raise ValueError("Capacity must be greater than 0.")
        self.capacity = capacity
        self.data = {}
        self.head = None
        self.tail = None

    def get(self, key):
        if key not in self.data:
            return None
        entry = self.data[key]
        self._moveToLast(entry)
        return entry[1]

    def put(self, key, value):
        if key in self.data:
            entry = self.data[key]
            entry[1] = value
            self._moveToLast(entry)
            return
        if len(self.data) == self.capacity:
            del self.data[self.head[0]]
            self._remove(self.head)
        entry = [key, value]
        self._addLast(entry)
        self.data[key] = entry

    def _moveToLast(self, entry):
        if entry == self.tail:
            return
        self._remove(entry)
        self._addLast(entry)

    def _remove(self, entry):
        if entry[0] in self.data:
            del self.data[entry[0]]
        if entry[2] is not None:
            entry[2][3] = entry[3]
        else:
            self.head = entry[3]
        if entry[3] is not None:
            entry[3][2] = entry[2]
        else:
            self.tail = entry[2]

    def _addLast(self, entry):
        if self.tail is not None:
            entry[2] = self.tail
            self.tail[3] = entry
        else:
            self.head = entry
        self.tail = entry

if __name__ == "__main__":
    import sys
    capacity = int(sys.stdin.readline())
    operations = int(sys.stdin.readline())
    lruCache = Main(capacity)
    for i in range(operations):
        operation = sys.stdin.readline().strip()
        if operation == "PUT":
            key, value = map(int, sys.stdin.readline().split())
            lruCache.put(key, value)
            print("Added: ({}, {})".format(key, value))
        elif operation == "GET":
            key = int(sys.stdin.readline())
            result = lruCache.get(key)
            print("Retrieved: {}".format(result if result is not None else "null"))

