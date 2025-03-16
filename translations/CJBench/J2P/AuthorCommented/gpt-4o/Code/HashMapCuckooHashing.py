import math

class CuckooHashing:
    def __init__(self, table_size):
        self.table_size = table_size
        self.buckets = [None] * table_size
        self.empty_slot = float('-inf')
        self.size = 0
        self.thresh = int(math.log2(table_size)) + 2

    def hash_function1(self, key):
        hash_value = key % self.table_size
        return hash_value if hash_value >= 0 else hash_value + self.table_size

    def hash_function2(self, key):
        hash_value = key // self.table_size
        hash_value %= self.table_size
        return hash_value if hash_value >= 0 else hash_value + self.table_size

    def insert_key_to_hash_table(self, key):
        wrapped_int = key
        loop_counter = 0

        if self.is_full():
            print("Hash table is full, rehashing...")
            self.rehash_table_increases_size()

        while loop_counter <= self.thresh:
            loop_counter += 1
            hash_index = self.hash_function1(key)

            if self.buckets[hash_index] is None or self.buckets[hash_index] == self.empty_slot:
                self.buckets[hash_index] = wrapped_int
                self.size += 1
                return

            temp = self.buckets[hash_index]
            self.buckets[hash_index] = wrapped_int
            wrapped_int = temp

            hash_index = self.hash_function2(temp)
            if self.buckets[hash_index] is None or self.buckets[hash_index] == self.empty_slot:
                self.buckets[hash_index] = wrapped_int
                self.size += 1
                return

            temp = self.buckets[hash_index]
            self.buckets[hash_index] = wrapped_int
            wrapped_int = temp

        print("Infinite loop detected, rehashing...")
        self.rehash_table_increases_size()
        self.insert_key_to_hash_table(key)

    def rehash_table_increases_size(self):
        new_table = CuckooHashing(self.table_size * 2)
        for bucket in self.buckets:
            if bucket is not None and bucket != self.empty_slot:
                new_table.insert_key_to_hash_table(bucket)
        self.buckets = new_table.buckets
        self.table_size = new_table.table_size
        self.thresh = int(math.log2(self.table_size)) + 2

    def delete_key_from_hash_table(self, key):
        hash_index = self.hash_function1(key)
        if self.buckets[hash_index] == key:
            self.buckets[hash_index] = self.empty_slot
            self.size -= 1
            return

        hash_index = self.hash_function2(key)
        if self.buckets[hash_index] == key:
            self.buckets[hash_index] = self.empty_slot
            self.size -= 1
            return

        print(f"Key {key} not found.")

    def display_hash_table(self):
        for i in range(self.table_size):
            if self.buckets[i] is None or self.buckets[i] == self.empty_slot:
                print(f"Bucket {i}: Empty")
            else:
                print(f"Bucket {i}: {self.buckets[i]}")

    def is_full(self):
        return all(bucket is not None and bucket != self.empty_slot for bucket in self.buckets)

if __name__ == "__main__":
    initial_size = int(input())
    hash_map = CuckooHashing(initial_size)

    operations = int(input())
    for _ in range(operations):
        command = input().split()
        if command[0].upper() == "INSERT":
            hash_map.insert_key_to_hash_table(int(command[1]))
        elif command[0].upper() == "DELETE":
            hash_map.delete_key_from_hash_table(int(command[1]))
        elif command[0].upper() == "DISPLAY":
            hash_map.display_hash_table()
        else:
            print("Invalid command")

# <END-OF-CODE>
