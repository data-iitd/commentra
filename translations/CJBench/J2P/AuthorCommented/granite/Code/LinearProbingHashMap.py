

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
        if key is None or not self.contains(key):
            return None

        key_index = self.hash(key, self.hsize)
        while self.keys[key_index]!= key:
            key_index = (key_index + 1) % self.hsize

        return self.values[key_index]

    def delete(self, key):
        if key is None or not self.contains(key):
            return False

        key_index = self.hash(key, self.hsize)
        while self.keys[key_index]!= key:
            key_index = (key_index + 1) % self.hsize

        self.keys[key_index] = None
        self.values[key_index] = None

        key_index = (key_index + 1) % self.hsize
        while self.keys[key_index] is not None:
            key_to_rehash = self.keys[key_index]
            val_to_rehash = self.values[key_index]
            self.keys[key_index] = None
            self.values[key_index] = None
            self.size -= 1
            self.put(key_to_rehash, val_to_rehash)
            key_index = (key_index + 1) % self.hsize

        self.size -= 1
        if self.size > 0 and self.size <= self.hsize / 8:
            self.resize(self.hsize // 2)

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

    initial_size = int(input())
    hash_map = Main(initial_size)

    operations = int(input())
    sys.stdin.readline()  # Consume the newline character

    for _ in range(operations):
        command, *args = sys.stdin.readline().split()

        if command == "PUT":
            hash_map.put(args[0], args[1])
        elif command == "GET":
            value = hash_map.get(args[0])
            print(value if value is not None else "NOT FOUND")
        elif command == "DELETE":
            deleted = hash_map.delete(args[0])
            print("DELETED" if deleted else "NOT FOUND")
        elif command == "CONTAINS":
            print("YES" if hash_map.contains(args[0]) else "NO")
        elif command == "SIZE":
            print(hash_map.size())
        elif command == "KEYS":
            print(" ".join(hash_map.keys()))
        else:
            print("INVALID COMMAND")

