class Main:
    def __init__(self, table_size):
        self.table_size = table_size
        self.buckets = [None] * table_size
        self.empty_slot = float('-inf')  # Sentinel value for empty slots
        self.size = 0
        self.thresh = int(math.log(table_size, 2)) + 2  # Calculate threshold for rehashing

    def hash_function_1(self, key):
        hash_value = key % self.table_size
        return hash_value if hash_value >= 0 else hash_value + self.table_size

    def hash_function_2(self, key):
        hash_value = key // self.table_size
        hash_value %= self.table_size
        return hash_value if hash_value >= 0 else hash_value + self.table_size

    def insert_key_2_hash_table(self, key):
        wrapped_int = key
        temp = None
        hash_value = None
        loop_counter = 0
        if self.is_full():
            print("Hash table is full, rehashing...")
            self.re_hash_table_increases_table_size()
        while loop_counter <= self.thresh:
            loop_counter += 1
            hash_value = self.hash_function_1(key)
            if self.buckets[hash_value] is None or self.buckets[hash_value] == self.empty_slot:
                self.buckets[hash_value] = wrapped_int
                self.size += 1
                return
            temp = self.buckets[hash_value]
            self.buckets[hash_value] = wrapped_int
            wrapped_int = temp
            hash_value = self.hash_function_2(temp)
            if self.buckets[hash_value] is None or self.buckets[hash_value] == self.empty_slot:
                self.buckets[hash_value] = wrapped_int
                self.size += 1
                return
            temp = self.buckets[hash_value]
            self.buckets[hash_value] = wrapped_int
            wrapped_int = temp
        print("Infinite loop detected, rehashing...")
        self.re_hash_table_increases_table_size()
        self.insert_key_2_hash_table(key)

    def re_hash_table_increases_table_size(self):
        new_t = Main(self.table_size * 2)
        for i in range(self.table_size):
            if self.buckets[i] is not None and self.buckets[i] != self.empty_slot:
                new_t.insert_key_2_hash_table(self.buckets[i])
        self.buckets = new_t.buckets
        self.table_size = new_t.table_size
        self.thresh = int(math.log(self.table_size, 2)) + 2

    def delete_key_from_hash_table(self, key):
        hash_value = self.hash_function_1(key)
        if self.buckets[hash_value] == key:
            self.buckets[hash_value] = self.empty_slot
            self.size -= 1
            return
        hash_value = self.hash_function_2(key)
        if self.buckets[hash_value] == key:
            self.buckets[hash_value] = self.empty_slot
            self.size -= 1
            return
        print(f"Key {key} not found.")

    def display_hashtable(self):
        for i in range(self.table_size):
            if self.buckets[i] is None or self.buckets[i] == self.empty_slot:
                print(f"Bucket {i}: Empty")
            else:
                print(f"Bucket {i}: {self.buckets[i]}")

    def is_full(self):
        return all(bucket is not None and bucket != self.empty_slot for bucket in self.buckets)


if __name__ == "__main__":
    import sys
    input_data = sys.stdin.read().splitlines()
    initial_size = int(input_data[0])
    hash_map = Main(initial_size)
    operations = int(input_data[1])
    for i in range(2, operations + 2):
        command = input_data[i].split()
        if command[0].upper() == "INSERT":
            hash_map.insert_key_2_hash_table(int(command[1]))
        elif command[0].upper() == "DELETE":
            hash_map.delete_key_from_hash_table(int(command[1]))
        elif command[0].upper() == "DISPLAY":
            hash_map.display_hashtable()
        else:
            print("Invalid command")
