
import math

class Main:
    def __init__(self, table_size):
        self.buckets = [None] * table_size  # Initialize buckets array
        self.table_size = table_size  # Set the size of the table
        self.empty_slot = -1  # Define the empty slot marker
        self.size = 0  # Initialize size to zero
        # Calculate the threshold for rehashing based on the table size
        self.thresh = math.ceil(math.log2(table_size)) + 2

    # Hash function 1: Computes the hash index for a given key
    def hash_function_1(self, key):
        hash = key % self.table_size  # Basic modulo operation for hash
        return hash if hash >= 0 else hash + self.table_size  # Ensure non-negative index

    # Hash function 2: Alternative hash function for collision resolution
    def hash_function_2(self, key):
        hash = key // self.table_size  # Compute an alternative hash
        hash %= self.table_size  # Ensure it fits within the table size
        return hash if hash >= 0 else hash + self.table_size  # Ensure non-negative index

    # Method to insert a key into the hash table
    def insert_key_to_hash_table(self, key):
        wrapped_int = key  # Wrap the key as an Integer object
        temp = None  # Temporary variable for swapping
        hash = self.hash_function_1(key)  # Compute the hash using function 1

        # Check if the hash table is full and rehash if necessary
        if self.is_full():
            print("Hash table is full, rehashing...")
            self.re_hash_table_increases_table_size()

        # Attempt to insert the key using open addressing
        while self.loop_counter <= self.thresh:
            self.loop_counter += 1  # Increment the loop counter
            hash = self.hash_function_1(key)  # Compute the hash using function 1

            # Check if the computed bucket is empty or marked as deleted
            if self.buckets[hash] is None or self.buckets[hash] == self.empty_slot:
                self.buckets[hash] = wrapped_int  # Insert the key
                self.size += 1  # Increment the size of the hash table
                return  # Exit the method after successful insertion

            # Handle collision by swapping and trying the second hash function
            temp = self.buckets[hash]  # Store the existing value
            self.buckets[hash] = wrapped_int  # Place the new key in the bucket
            wrapped_int = temp  # Update wrapped_int to the old value
            hash = self.hash_function_2(temp)  # Compute the second hash index

            # Check if the new computed bucket is empty or marked as deleted
            if self.buckets[hash] is None or self.buckets[hash] == self.empty_slot:
                self.buckets[hash] = wrapped_int  # Insert the key
                self.size += 1  # Increment the size of the hash table
                return  # Exit the method after successful insertion

            # Handle collision again by swapping
            temp = self.buckets[hash]  # Store the existing value
            self.buckets[hash] = wrapped_int  # Place the new key in the bucket
            wrapped_int = temp  # Update wrapped_int to the old value

        # If the loop exceeds the threshold, rehash and try to insert again
        print("Infinite loop detected, rehashing...")
        self.re_hash_table_increases_table_size()
        self.insert_key_to_hash_table(key)  # Retry inserting the key

    # Method to rehash the table and increase its size
    def re_hash_table_increases_table_size(self):
        new_t = Main(self.table_size * 2)  # Create a new hash table with double the size
        # Reinsert all existing keys into the new hash table
        for i in range(self.table_size):
            if self.buckets[i] is not None and self.buckets[i]!= self.empty_slot:
                new_t.insert_key_to_hash_table(self.buckets[i])  # Insert each key into the new table
        # Update the current hash table to the new one
        self.buckets = new_t.buckets
        self.table_size = new_t.table_size  # Update the size
        # Recalculate the threshold for the new table size
        self.thresh = math.ceil(math.log2(self.table_size)) + 2

    # Method to delete a key from the hash table
    def delete_key_from_hash_table(self, key):
        hash = self.hash_function_1(key)  # Compute the hash index using function 1
        # Check if the key is present in the computed bucket
        if self.buckets[hash] == key:
            self.buckets[hash] = self.empty_slot  # Mark the bucket as deleted
            self.size -= 1  # Decrement the size of the hash table
            return  # Exit the method after successful deletion
        # Check the second hash function for the key
        hash = self.hash_function_2(key)
        if self.buckets[hash] == key:
            self.buckets[hash] = self.empty_slot  # Mark the bucket as deleted
            self.size -= 1  # Decrement the size of the hash table
            return  # Exit the method after successful deletion
        # If the key is not found, print a message
        print("Key", key, "not found.")

    # Method to display the contents of the hash table
    def display_hash_table(self):
        for i in range(self.table_size):
            # Check if the bucket is empty or marked as deleted
            if self.buckets[i] is None or self.buckets[i] == self.empty_slot:
                print("Bucket", i, ": Empty")  # Print empty bucket
            else:
                print("Bucket", i, ":", self.buckets[i])  # Print the key in the bucket

    # Method to check if the hash table is full
    def is_full(self):
        for bucket in self.buckets:
            # If any bucket is empty or marked as deleted, the table is not full
            if bucket is None or bucket == self.empty_slot:
                return False
        return True  # All buckets are filled

    # Main method to run the hash table operations
    @staticmethod
    def main():
        initial_size = int(input())  # Read the initial size of the hash table
        hash_map = Main(initial_size)  # Create a new hash table instance
        operations = int(input())  # Read the number of operations to perform
        input()  # Consume the newline character

        # Loop through the number of operations
        for i in range(operations):
            command = input().split(" ")  # Read the command
            if command[0].upper() == "INSERT":
                hash_map.insert_key_to_hash_table(int(command[1]))  # Insert the key
            elif command[0].upper() == "DELETE":
                hash_map.delete_key_from_hash_table(int(command[1]))  # Delete the key
            elif command[0].upper() == "DISPLAY":
                hash_map.display_hash_table()  # Display the hash table
            else:
                print("Invalid command")  # Handle invalid commands

# Call the main method to run the hash table operations
Main.main()

