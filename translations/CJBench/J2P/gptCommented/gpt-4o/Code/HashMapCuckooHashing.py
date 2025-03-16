import math

class HashTable:
    def __init__(self, table_size):
        self.table_size = table_size  # Size of the hash table
        self.buckets = [None] * table_size  # Array to store the hash table entries
        self.empty_slot = float('-inf')  # Placeholder for deleted slots
        self.size = 0  # Current number of elements in the hash table
        self.thresh = int(math.log(table_size, 2)) + 2  # Threshold for rehashing

    def hash_function1(self, key):
        hash_index = key % self.table_size  # Basic modulo operation for hash
        return hash_index if hash_index >= 0 else hash_index + self.table_size  # Ensure non-negative index

    def hash_function2(self, key):
        hash_index = key // self.table_size  # Compute an alternative hash
        hash_index %= self.table_size  # Ensure it fits within the table size
        return hash_index if hash_index >= 0 else hash_index + self.table_size  # Ensure non-negative index

    def insert_key_to_hash_table(self, key):
        wrapped_int = key  # Wrap the key as an integer
        temp = None  # Temporary variable for swapping
        loop_counter = 0  # Counter to track the number of attempts

        # Check if the hash table is full and rehash if necessary
        if self.is_full():
            print("Hash table is full, rehashing...")
            self.rehash_table_increases_table_size()

        # Attempt to insert the key using open addressing
        while loop_counter <= self.thresh:
            loop_counter += 1  # Increment the loop counter
            hash_index = self.hash_function1(key)  # Compute the hash using function 1

            # Check if the computed bucket is empty or marked as deleted
            if self.buckets[hash_index] is None or self.buckets[hash_index] == self.empty_slot:
                self.buckets[hash_index] = wrapped_int  # Insert the key
                self.size += 1  # Increment the size of the hash table
                return  # Exit the method after successful insertion

            # Handle collision by swapping and trying the second hash function
            temp = self.buckets[hash_index]  # Store the existing value
            self.buckets[hash_index] = wrapped_int  # Place the new key in the bucket
            wrapped_int = temp  # Update wrapped_int to the old value
            hash_index = self.hash_function2(temp)  # Compute the second hash index

            # Check if the new computed bucket is empty or marked as deleted
            if self.buckets[hash_index] is None or self.buckets[hash_index] == self.empty_slot:
                self.buckets[hash_index] = wrapped_int  # Insert the key
                self.size += 1  # Increment the size of the hash table
                return  # Exit the method after successful insertion

            # Handle collision again by swapping
            temp = self.buckets[hash_index]  # Store the existing value
            self.buckets[hash_index] = wrapped_int  # Place the new key in the bucket
            wrapped_int = temp  # Update wrapped_int to the old value

        # If the loop exceeds the threshold, rehash and try to insert again
        print("Infinite loop detected, rehashing...")
        self.rehash_table_increases_table_size()
        self.insert_key_to_hash_table(key)  # Retry inserting the key

    def rehash_table_increases_table_size(self):
        new_table = HashTable(self.table_size * 2)  # Create a new hash table with double the size
        # Reinsert all existing keys into the new hash table
        for bucket in self.buckets:
            if bucket is not None and bucket != self.empty_slot:
                new_table.insert_key_to_hash_table(bucket)  # Insert each key into the new table
        # Update the current hash table to the new one
        self.buckets = new_table.buckets
        self.table_size = new_table.table_size  # Update the size
        # Recalculate the threshold for the new table size
        self.thresh = int(math.log(self.table_size, 2)) + 2

    def delete_key_from_hash_table(self, key):
        hash_index = self.hash_function1(key)  # Compute the hash index using function 1
        # Check if the key is present in the computed bucket
        if self.buckets[hash_index] == key:
            self.buckets[hash_index] = self.empty_slot  # Mark the bucket as deleted
            self.size -= 1  # Decrement the size of the hash table
            return  # Exit the method after successful deletion
        # Check the second hash function for the key
        hash_index = self.hash_function2(key)
        if self.buckets[hash_index] == key:
            self.buckets[hash_index] = self.empty_slot  # Mark the bucket as deleted
            self.size -= 1  # Decrement the size of the hash table
            return  # Exit the method after successful deletion
        # If the key is not found, print a message
        print(f"Key {key} not found.")

    def display_hash_table(self):
        for i in range(self.table_size):
            # Check if the bucket is empty or marked as deleted
            if self.buckets[i] is None or self.buckets[i] == self.empty_slot:
                print(f"Bucket {i}: Empty")  # Print empty bucket
            else:
                print(f"Bucket {i}: {self.buckets[i]}")  # Print the key in the bucket

    def is_full(self):
        for bucket in self.buckets:
            # If any bucket is empty or marked as deleted, the table is not full
            if bucket is None or bucket == self.empty_slot:
                return False
        return True  # All buckets are filled

# Main function to run the hash table operations
if __name__ == "__main__":
    initial_size = int(input())  # Read the initial size of the hash table
    hash_map = HashTable(initial_size)  # Create a new hash table instance
    operations = int(input())  # Read the number of operations to perform
    input()  # Consume the newline character

    # Loop through the number of operations
    for _ in range(operations):
        command = input().split(" ")  # Read the command
        if command[0].upper() == "INSERT":
            hash_map.insert_key_to_hash_table(int(command[1]))  # Insert the key
        elif command[0].upper() == "DELETE":
            hash_map.delete_key_from_hash_table(int(command[1]))  # Delete the key
        elif command[0].upper() == "DISPLAY":
            hash_map.display_hash_table()  # Display the hash table
        else:
            print("Invalid command")  # Handle invalid commands

# <END-OF-CODE>
