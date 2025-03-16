
class Main:
    def __init__(self, size=16):
        self.hsize = size
        self.keys = [None] * size
        self.values = [None] * size
        self.size = 0

    def put(self, key, value):
        if key is None:
            return False

        if self.size > self.hsize // 2:
            self.resize(self.hsize * 2)

        key_index = self.hash(key, self.hsize)
        for i in range(self.hsize):
            if self.keys[key_index] is None:
                self.keys[key_index] = key
                self.values[key_index] = value
                self.size += 1
                return True
            elif self.keys[key_index] == key:
                self.values[key_index] = value
                return True
            key_index = (key_index + 1) % self.hsize

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

        key_index = self.hash(key, self.hsize)
        while self.keys[key_index] != key:
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
        if self.size > 0 and self.size <= self.hsize // 8:
            self.resize(self.hsize // 2)

        return True

    def contains(self, key):
        return self.get(key) is not None

    def size(self):
        return self.size

    def keys(self):
        list_of_keys = []
        for i in range(self.hsize):
            if self.keys[i] is not None:
                list_of_keys.append(self.keys[i])
        list_of_keys.sort(key=lambda x: x)
        return list_of_keys

    def hash(self, key, size):
        return (hash(key) & 0x7fffffff) % size

    def resize(self, new_size):
        tmp = Main(new_size)
        for i in range(self.hsize):
            if self.keys[i] is not None:
                tmp.put(self.keys[i], self.values[i])

        self.keys = tmp.keys
        self.values = tmp.values
        self.hsize = new_size

    def main(self):
        scanner = Scanner(sys.stdin)

        initial_size = scanner.nextInt()
        hash_map = Main(initial_size)

        operations = scanner.nextInt()
        scanner.nextLine()  # Consume the newline character

        for i in range(operations):
            input = scanner.nextLine().split(" ")
            command = input[0].upper()

            if command == "PUT":
                hash_map.put(input[1], input[2])
            elif command == "GET":
                value = hash_map.get(input[1])
                print(value if value is not None else "NOT FOUND")
            elif command == "DELETE":
                deleted = hash_map.delete(input[1])
                print("DELETED" if deleted else "NOT FOUND")
            elif command == "CONTAINS":
                print("YES" if hash_map.contains(input[1]) else "NO")
            elif command == "SIZE":
                print(hash_map.size())
            elif command == "KEYS":
                for key in hash_map.keys():
                    print(key, end=" ")
                print()
            else:
                print("INVALID COMMAND")

        scanner.close()

    if __name__ == "__main__":
        main()

