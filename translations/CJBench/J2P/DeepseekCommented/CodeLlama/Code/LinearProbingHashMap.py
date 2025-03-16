import sys

class Main:
    def __init__(self, size):
        self.hsize = size
        self.keys = [None] * size
        self.values = [None] * size
        self.size = 0

    def put(self, key, value):
        if key is None:
            return False
        if self.size > self.hsize // 2:
            self.resize(2 * self.hsize)
        keyIndex = self.hash(key, self.hsize)
        for i in range(self.hsize):
            if self.keys[keyIndex] is None:
                self.keys[keyIndex] = key
                self.values[keyIndex] = value
                self.size += 1
                return True
            if key == self.keys[keyIndex]:
                self.values[keyIndex] = value
                return True
            keyIndex = (keyIndex + 1) % self.hsize
        return False

    def get(self, key):
        if key is None:
            return None
        for i in range(self.hsize):
            if self.keys[i] == key:
                return self.values[i]
        return None

    def delete(self, key):
        if key is None or not self.contains(key):
            return False
        keyIndex = self.hash(key, self.hsize)
        while self.keys[keyIndex] != key:
            keyIndex = (keyIndex + 1) % self.hsize
        self.keys[keyIndex] = None
        self.values[keyIndex] = None
        keyIndex = (keyIndex + 1) % self.hsize
        while self.keys[keyIndex] is not None:
            keyToRehash = self.keys[keyIndex]
            valToRehash = self.values[keyIndex]
            self.keys[keyIndex] = None
            self.values[keyIndex] = None
            self.size -= 1
            self.put(keyToRehash, valToRehash)
            keyIndex = (keyIndex + 1) % self.hsize
        self.size -= 1
        if self.size > 0 and self.size <= self.hsize // 8:
            self.resize(self.hsize // 2)
        return True

    def contains(self, key):
        return self.get(key) is not None

    def size(self):
        return self.size

    def keys(self):
        listOfKeys = []
        for i in range(self.hsize):
            if self.keys[i] is not None:
                listOfKeys.append(self.keys[i])
        listOfKeys.sort()
        return listOfKeys

    def hash(self, key, size):
        return (hash(key) & 0x7fffffff) % size

    def resize(self, newSize):
        tmp = Main(newSize)
        for i in range(self.hsize):
            if self.keys[i] is not None:
                tmp.put(self.keys[i], self.values[i])
        self.keys = tmp.keys
        self.values = tmp.values
        self.hsize = newSize

if __name__ == "__main__":
    initialSize = int(sys.stdin.readline())
    hashMap = Main(initialSize)
    operations = int(sys.stdin.readline())
    for i in range(operations):
        input = sys.stdin.readline().split()
        command = input[0].upper()
        if command == "PUT":
            hashMap.put(input[1], input[2])
        elif command == "GET":
            value = hashMap.get(input[1])
            print(value if value is not None else "NOT FOUND")
        elif command == "DELETE":
            deleted = hashMap.delete(input[1])
            print("DELETED" if deleted else "NOT FOUND")
        elif command == "CONTAINS":
            print("YES" if hashMap.contains(input[1]) else "NO")
        elif command == "SIZE":
            print(hashMap.size())
        elif command == "KEYS":
            for key in hashMap.keys():
                print(key, end=" ")
            print()
        else:
            print("INVALID COMMAND")

