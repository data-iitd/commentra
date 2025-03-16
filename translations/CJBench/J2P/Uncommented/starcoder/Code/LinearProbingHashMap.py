
class Main:
    def __init__(self, size):
        self.hsize = size
        self.keys = [None] * size
        self.values = [None] * size
        self.size = 0

    def put(self, key, value):
        if key == None:
            return False
        if self.size > self.hsize / 2:
            self.resize(2 * self.hsize)
        keyIndex = self.hash(key, self.hsize)
        for i in range(keyIndex, self.hsize):
            if self.keys[i] == None:
                self.keys[i] = key
                self.values[i] = value
                self.size += 1
                return True
            if self.keys[i] == key:
                self.values[i] = value
                return True
        return False

    def get(self, key):
        if key == None:
            return None
        for i in range(self.hash(key, self.hsize), self.hsize):
            if self.keys[i] == key:
                return self.values[i]
        return None

    def delete(self, key):
        if key == None or not self.contains(key):
            return False
        i = self.hash(key, self.hsize)
        while self.keys[i]!= key:
            i = (i + 1) % self.hsize
        self.keys[i] = None
        self.values[i] = None
        i = (i + 1) % self.hsize
        while self.keys[i]!= None:
            keyToRehash = self.keys[i]
            valToRehash = self.values[i]
            self.keys[i] = None
            self.values[i] = None
            self.size -= 1
            self.put(keyToRehash, valToRehash)
            i = (i + 1) % self.hsize
        self.size -= 1
        if self.size > 0 and self.size <= self.hsize / 8:
            self.resize(self.hsize / 2)
        return True

    def contains(self, key):
        return self.get(key)!= None

    def size(self):
        return self.size

    def keys(self):
        listOfKeys = []
        for i in range(self.hsize):
            if self.keys[i]!= None:
                listOfKeys.append(self.keys[i])
        listOfKeys.sort()
        return listOfKeys

    def resize(self, newSize):
        tmp = Main(newSize)
        for i in range(self.hsize):
            if self.keys[i]!= None:
                tmp.put(self.keys[i], self.values[i])
        self.keys = tmp.keys
        self.values = tmp.values
        self.hsize = newSize

    def hash(self, key, size):
        return (key.hashCode() & 0x7fffffff) % size

    def main(self):
        import sys
        scanner = sys.stdin
        initialSize = int(scanner.readline())
        hashMap = Main(initialSize)
        operations = int(scanner.readline())
        for i in range(operations):
            input = scanner.readline().split(" ")
            command = input[0].upper()
            if command == "PUT":
                hashMap.put(input[1], input[2])
            elif command == "GET":
                value = hashMap.get(input[1])
                print(value if value!= None else "NOT FOUND")
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
        scanner.close()

# 