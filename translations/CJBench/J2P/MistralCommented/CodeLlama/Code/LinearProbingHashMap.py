
class Main:

    # Declare instance variables
    def __init__(self, size):
        self.hsize = size
        # Initialize keys and values arrays with specified size
        self.keys = [None] * size
        self.values = [None] * size
        self.size = 0

    # Put method to add a key-value pair to the hash map
    def put(self, key, value):
        if key is None:
            # Return false if key is null
            return False
        if self.size > self.hsize // 2:
            # If size is more than half of hash map size, resize the hash map
            self.resize(self.hsize * 2)
        key_index = self.hash(key, self.hsize)
        # Search for the index where the key already exists
        for i in range(key_index, self.hsize):
            if self.keys[i] is None:
                # If key doesn't exist, add it to the hash map and increment size
                self.keys[i] = key
                self.values[i] = value
                self.size += 1
                return True
            if key == self.keys[i]:
                # If key already exists, update its value and return true
                self.values[i] = value
                return True
        # If key doesn't exist, add it to the hash map and increment size
        self.keys[key_index] = key
        self.values[key_index] = value
        self.size += 1
        return True

    # Get method to retrieve the value associated with a key
    def get(self, key):
        if key is None:
            # Return null if key is null
            return None
        for i in range(self.hash(key, self.hsize), self.hsize):
            if self.keys[i] == key:
                # If key is found, return its value
                return self.values[i]
        # If key is not found, return null
        return None

    # Delete method to remove a key-value pair from the hash map
    def delete(self, key):
        if key is None or not self.contains(key):
            # Return false if key is null or not found in the hash map
            return False
        key_index = self.hash(key, self.hsize)
        # Find the index of the key in the hash map
        while self.keys[key_index] != key:
            key_index = (key_index + 1) % self.hsize
        # Set keys and values at the index to null and increment i
        self.keys[key_index] = None
        self.values[key_index] = None
        key_index = (key_index + 1) % self.hsize
        # Rehash the deleted key and its corresponding value
        while self.keys[key_index] is not None:
            key_to_rehash = self.keys[key_index]
            val_to_rehash = self.values[key_index]
            self.keys[key_index] = None
            self.values[key_index] = None
            self.size -= 1
            # Put the rehashed key-value pair back into the hash map
            self.put(key_to_rehash, val_to_rehash)
            key_index = (key_index + 1) % self.hsize
        self.size -= 1
        # If size is less than or equal to one-eighth of the hash map size, resize it
        if self.size > 0 and self.size <= self.hsize // 8:
            self.resize(self.hsize // 2)
        # Return true if the key was successfully deleted
        return True

    # Check if a key exists in the hash map
    def contains(self, key):
        # Return true if the get method returns a non-null value
        return self.get(key) is not None

    # Get the size of the hash map
    def size(self):
        # Return the size instance variable
        return self.size

    # Get an iterable of all the keys in the hash map
    def keys(self):
        # Create an ArrayList to store the keys
        list_of_keys = []
        # Iterate through each index in the hash map and add the keys to the ArrayList
        for i in range(self.hsize):
            if self.keys[i] is not None:
                list_of_keys.append(self.keys[i])
        # Sort the keys in the ArrayList and return it
        list_of_keys.sort(key=lambda x: x)
        return list_of_keys

    # Increment the index based on the hash map size
    def increment(self, i):
        return (i + 1) % self.hsize

    # Resize the hash map with a new size
    def resize(self, new_size):
        # Create a new Main object with the new size
        tmp = Main(new_size)
        # Iterate through each index in the old hash map and put the keys and values into the new hash map
        for i in range(self.hsize):
            if self.keys[i] is not None:
                tmp.put(self.keys[i], self.values[i])
        # Replace the old hash map instance variables with the new ones
        self.keys = tmp.keys
        self.values = tmp.values
        self.hsize = new_size

    # Hash a key based on its hash code and the hash map size
    def hash(self, key, size):
        return (hash(key) & 0x7fffffff) % size

    # Main method to read input and perform hash map operations
    def main():
        initial_size = int(input())
        # Create a new Main object with the initial size
        hash_map = Main(initial_size)
        operations = int(input())
        for i in range(operations):
            input_ = input().split(" ")
            command = input_[0].upper()
            if command == "PUT":
                hash_map.put(input_[1], input_[2])
            elif command == "GET":
                value = hash_map.get(input_[1])
                print(value if value is not None else "NOT FOUND")
            elif command == "DELETE":
                deleted = hash_map.delete(input_[1])
                print("DELETED" if deleted else "NOT FOUND")
            elif command == "CONTAINS":
                print("YES" if hash_map.contains(input_[1]) else "NO")
            elif command == "SIZE":
                print(hash_map.size())
            elif command == "KEYS":
                for key in hash_map.keys():
                    print(key, end=" ")
                print()
            else:
                print("INVALID COMMAND")

    # Run the main method
    if __name__ == "__main__":
        main()

