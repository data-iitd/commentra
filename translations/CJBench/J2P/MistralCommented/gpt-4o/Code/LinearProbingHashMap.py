class HashMap:
    def __init__(self, size=16):
        self.hsize = size
        self.keys = [None] * size
        self.values = [None] * size
        self.size = 0

    def put(self, key, value):
        if key is None:
            return False
        if self.size > self.hsize // 2:
            self.resize(2 * self.hsize)
        key_index = self.hash(key, self.hsize)
        while self.keys[key_index] is not None:
            if self.keys[key_index] == key:
                self.values[key_index] = value
                return True
            key_index = self.increment(key_index)
        self.keys[key_index] = key
        self.values[key_index] = value
        self.size += 1
        return True

    def get(self, key):
        if key is None:
            return None
        for i in range(self.hash(key, self.hsize), self.hsize):
            if self.keys[i] is None:
                break
            if self.keys[i] == key:
                return self.values[i]
        return None

    def delete(self, key):
        if key is None or not self.contains(key):
            return False
        i = self.hash(key, self.hsize)
        while self.keys[i] != key:
            i = self.increment(i)
        self.keys[i] = None
        self.values[i] = None
        i = self.increment(i)
        while self.keys[i] is not None:
            key_to_rehash = self.keys[i]
            val_to_rehash = self.values[i]
            self.keys[i] = None
            self.values[i] = None
            self.size -= 1
            self.put(key_to_rehash, val_to_rehash)
            i = self.increment(i)
        self.size -= 1
        if self.size > 0 and self.size <= self.hsize // 8:
            self.resize(self.hsize // 2)
        return True

    def contains(self, key):
        return self.get(key) is not None

    def size(self):
        return self.size

    def keys(self):
        return [key for key in self.keys if key is not None]

    def increment(self, i):
        return (i + 1) % self.hsize

    def resize(self, new_size):
        tmp = HashMap(new_size)
        for i in range(self.hsize):
            if self.keys[i] is not None:
                tmp.put(self.keys[i], self.values[i])
        self.keys = tmp.keys
        self.values = tmp.values
        self.hsize = new_size

    def hash(self, key, size):
        return hash(key) % size

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    initial_size = int(data[0])
    hash_map = HashMap(initial_size)
    operations = int(data[1])
    
    for i in range(2, 2 + operations):
        command = data[i].split()
        cmd = command[0].upper()
        if cmd == "PUT":
            hash_map.put(command[1], command[2])
        elif cmd == "GET":
            value = hash_map.get(command[1])
            print(value if value is not None else "NOT FOUND")
        elif cmd == "DELETE":
            deleted = hash_map.delete(command[1])
            print("DELETED" if deleted else "NOT FOUND")
        elif cmd == "CONTAINS":
            print("YES" if hash_map.contains(command[1]) else "NO")
        elif cmd == "SIZE":
            print(hash_map.size)
        elif cmd == "KEYS":
            print(" ".join(hash_map.keys()))
        else:
            print("INVALID COMMAND")
# <END-OF-CODE>
