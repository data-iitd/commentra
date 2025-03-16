
import math

class Main:
    def __init__(self, table_size):
        self.buckets = [None] * table_size
        self.table_size = table_size
        self.empty_slot = -1  # Marker for empty slots
        self.size = 0
        self.thresh = math.ceil(math.log2(table_size)) + 2  # Calculate threshold for rehashing

    def hash_function_1(self, key):
        hash = key % self.table_size
        return hash if hash >= 0 else hash + self.table_size

    def hash_function_2(self, key):
        hash = key // self.table_size
        hash %= self.table_size
        return hash if hash >= 0 else hash + self.table_size

    def insert_key_to_hash_table(self, key):
        wrapped_int = key
        temp = None
        hash = self.hash_function_1(key)
        while self.size > self.thresh:
            print("Hash table is full, rehashing...")
            self.rehash_table_increases_table_size()
        while True:
            if self.buckets[hash] is None or self.buckets[hash] == self.empty_slot:
                self.buckets[hash] = wrapped_int
                self.size += 1
                return
            temp = self.buckets[hash]
            self.buckets[hash] = wrapped_int
            wrapped_int = temp
            hash = self.hash_function_2(temp)
            if self.buckets[hash] is None or self.buckets[hash] == self.empty_slot:
                self.buckets[hash] = wrapped_int
                self.size += 1
                return
            temp = self.buckets[hash]
            self.buckets[hash] = wrapped_int
            wrapped_int = temp

    def rehash_table_increases_table_size(self):
        new_t = Main(self.table_size * 2)
        for i in range(self.table_size):
            if self.buckets[i] is not None and self.buckets[i]!= self.empty_slot:
                new_t.insert_key_to_hash_table(self.buckets[i])
        self.buckets = new_t.buckets
        self.table_size = new_t.table_size
        self.thresh = math.ceil(math.log2(self.table_size)) + 2

    def delete_key_from_hash_table(self, key):
        hash = self.hash_function_1(key)
        if self.buckets[hash] == key:
            self.buckets[hash] = self.empty_slot
            self.size -= 1
            return
        hash = self.hash_function_2(key)
        if self.buckets[hash] == key:
            self.buckets[hash] = self.empty_slot
            self.size -= 1
            return
        print("Key", key, "not found.")

    def display_hashtable(self):
        for i in range(self.table_size):
            if self.buckets[i] is None or self.buckets[i] == self.empty_slot:
                print("Bucket", i, ": Empty")
            else:
                print("Bucket", i, ":", self.buckets[i])

    def is_full(self):
        for bucket in self.buckets:
            if bucket is None or bucket == self.empty_slot:
                return False
        return True

if __name__ == "__main__":
    initial_size = int(input())
    hash_map = Main(initial_size)
    operations = int(input())
    for _ in range(operations):
        command = input().split()
        if command[0].upper() == "INSERT":
            hash_map.insert_key_to_hash_table(int(command[1]))
        elif command[0].upper() == "DELETE":
            hash_map.delete_key_from_hash_table(int(command[1]))
        elif command[0].upper() == "DISPLAY":
            hash_map.display_hashtable()
        else:
            print("Invalid command")

