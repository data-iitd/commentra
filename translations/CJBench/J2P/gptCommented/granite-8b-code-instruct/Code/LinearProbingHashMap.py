
class Main:
    def __init__(self, size=16):
        self.hsize = size
        self.keys = [None] * size
        self.values = [None] * size
        self.size = 0

    def put(self, key, value):
        if key is None:
            return False
        if self.size > self.hsize / 2:
            self.resize(2 * self.hsize)
        key_index = self.hash(key, self.hsize)
        while self.keys[key_index] is not None:
            if self.keys[key_index] == key:
                self.values[key_index] = value
                return True
            key_index = (key_index + 1) % self.hsize
        self.keys[key_index] = key
        self.values[key_index] = value
        self.size += 1
        return True

    def get(self, key):
        if key is None:
            return None
        i = self.hash(key, self.hsize)
        while self.keys[i] is not None:
            if self.keys[i] == key:
                return self.values[i]
            i = (i + 1) % self.hsize
        return None

    def delete(self, key):
        if key is None or not self.contains(key):
            return False
        i = self.hash(key, self.hsize)
        while self.keys[i]!= key:
            i = (i + 1) % self.hsize
        self.keys[i] = None
        self.values[i] = None
        i = (i + 1) % self.hsize
        while self.keys[i] is not None:
            key_to_rehash = self.keys[i]
            val_to_rehash = self.values[i]
            self.keys[i] = None
            self.values[i] = None
            self.size -= 1
            self.put(key_to_rehash, val_to_rehash)
            i = (i + 1) % self.hsize
        self.size -= 1
        if self.size > 0 and self.size <= self.hsize / 8:
            self.resize(self.hsize / 2)
        return True

    def contains(self, key):
        return self.get(key) is not None

    def size(self):
        return self.size

    def keys(self):
        keys_list = []
        for i in range(self.hsize):
            if self.keys[i] is not None:
                keys_list.append(self.keys[i])
        keys_list.sort()
        return keys_list

    def increment(self, i):
        return (i + 1) % self.hsize

    def resize(self, new_size):
        tmp = Main(new_size)
        for i in range(self.hsize):
            if self.keys[i] is not None:
                tmp.put(self.keys[i], self.values[i])
        self.keys = tmp.keys
        self.values = tmp.values
        self.hsize = new_size

    def hash(self, key, size):
        return (hash(key) & 0x7fffffff) % size

if __name__ == "__main__":
    import sys
    scanner = iter(sys.stdin.read().splitlines())
    initial_size = int(next(scanner))
    hash_map = Main(initial_size)
    operations = int(next(scanner))
    for _ in range(operations):
        input_line = next(scanner).split()
        command = input_line[0].upper()
        if command == "PUT":
            hash_map.put(input_line[1], input_line[2])
        elif command == "GET":
            value = hash_map.get(input_line[1])
            print(value if value is not None else "NOT FOUND")
        elif command == "DELETE":
            deleted = hash_map.delete(input_line[1])
            print("DELETED" if deleted else "NOT FOUND")
        elif command == "CONTAINS":
            print("YES" if hash_map.contains(input_line[1]) else "NO")
        elif command == "SIZE":
            print(hash_map.size())
        elif command == "KEYS":
            print(" ".join(hash_map.keys()))
        else:
            print("INVALID COMMAND")

