import java.util.Objects;
import java.util.Scanner;

public class Main {
    private int tableSize; // Size of the hash table
    private Integer[] buckets; // Array to store the hash table entries
    private final Integer emptySlot; // Placeholder for deleted slots
    private int size; // Current number of elements in the hash table
    private int thresh; // Threshold for rehashing

    // Constructor to initialize the hash table with a given size
    public Main(int tableSize) {
        this.buckets = new Integer[tableSize]; // Initialize buckets array
        this.tableSize = tableSize; // Set the size of the table
        this.emptySlot = Integer.MIN_VALUE; // Define the empty slot marker
        this.size = 0; // Initialize size to zero
        // Calculate the threshold for rehashing based on the table size
        this.thresh = (int) (Math.log(tableSize) / Math.log(2)) + 2;
    }

    // Hash function 1: Computes the hash index for a given key
    public int hashFunction1(int key) {
        int hash = key % tableSize; // Basic modulo operation for hash
        return (hash < 0) ? hash + tableSize : hash; // Ensure non-negative index
    }

    // Hash function 2: Alternative hash function for collision resolution
    public int hashFunction2(int key) {
        int hash = key / tableSize; // Compute an alternative hash
        hash %= tableSize; // Ensure it fits within the table size
        return (hash < 0) ? hash + tableSize : hash; // Ensure non-negative index
    }

    // Method to insert a key into the hash table
    public void insertKey2HashTable(int key) {
        Integer wrappedInt = key; // Wrap the key as an Integer object
        Integer temp; // Temporary variable for swapping
        int hash; // Variable to hold the computed hash index
        int loopCounter = 0; // Counter to track the number of attempts

        // Check if the hash table is full and rehash if necessary
        if (isFull()) {
            System.out.println("Hash table is full, rehashing...");
            reHashTableIncreasesTableSize();
        }

        // Attempt to insert the key using open addressing
        while (loopCounter <= thresh) {
            loopCounter++; // Increment the loop counter
            hash = hashFunction1(key); // Compute the hash using function 1

            // Check if the computed bucket is empty or marked as deleted
            if (buckets[hash] == null || Objects.equals(buckets[hash], emptySlot)) {
                buckets[hash] = wrappedInt; // Insert the key
                size++; // Increment the size of the hash table
                return; // Exit the method after successful insertion
            }

            // Handle collision by swapping and trying the second hash function
            temp = buckets[hash]; // Store the existing value
            buckets[hash] = wrappedInt; // Place the new key in the bucket
            wrappedInt = temp; // Update wrappedInt to the old value
            hash = hashFunction2(temp); // Compute the second hash index

            // Check if the new computed bucket is empty or marked as deleted
            if (buckets[hash] == null || Objects.equals(buckets[hash], emptySlot)) {
                buckets[hash] = wrappedInt; // Insert the key
                size++; // Increment the size of the hash table
                return; // Exit the method after successful insertion
            }

            // Handle collision again by swapping
            temp = buckets[hash]; // Store the existing value
            buckets[hash] = wrappedInt; // Place the new key in the bucket
            wrappedInt = temp; // Update wrappedInt to the old value
        }

        // If the loop exceeds the threshold, rehash and try to insert again
        System.out.println("Infinite loop detected, rehashing...");
        reHashTableIncreasesTableSize();
        insertKey2HashTable(key); // Retry inserting the key
    }

    // Method to rehash the table and increase its size
    public void reHashTableIncreasesTableSize() {
        Main newT = new Main(tableSize * 2); // Create a new hash table with double the size
        // Reinsert all existing keys into the new hash table
        for (int i = 0; i < tableSize; i++) {
            if (buckets[i] != null && !Objects.equals(buckets[i], emptySlot)) {
                newT.insertKey2HashTable(buckets[i]); // Insert each key into the new table
            }
        }
        // Update the current hash table to the new one
        this.buckets = newT.buckets;
        this.tableSize = newT.tableSize; // Update the size
        // Recalculate the threshold for the new table size
        this.thresh = (int) (Math.log(tableSize) / Math.log(2)) + 2;
    }

    // Method to delete a key from the hash table
    public void deleteKeyFromHashTable(int key) {
        int hash = hashFunction1(key); // Compute the hash index using function 1
        // Check if the key is present in the computed bucket
        if (Objects.equals(buckets[hash], key)) {
            buckets[hash] = emptySlot; // Mark the bucket as deleted
            size--; // Decrement the size of the hash table
            return; // Exit the method after successful deletion
        }
        // Check the second hash function for the key
        hash = hashFunction2(key);
        if (Objects.equals(buckets[hash], key)) {
            buckets[hash] = emptySlot; // Mark the bucket as deleted
            size--; // Decrement the size of the hash table
            return; // Exit the method after successful deletion
        }
        // If the key is not found, print a message
        System.out.println("Key " + key + " not found.");
    }

    // Method to display the contents of the hash table
    public void displayHashtable() {
        for (int i = 0; i < tableSize; i++) {
            // Check if the bucket is empty or marked as deleted
            if (buckets[i] == null || Objects.equals(buckets[i], emptySlot)) {
                System.out.println("Bucket " + i + ": Empty"); // Print empty bucket
            } else {
                System.out.println("Bucket " + i + ": " + buckets[i]); // Print the key in the bucket
            }
        }
    }

    // Method to check if the hash table is full
    public boolean isFull() {
        for (Integer bucket : buckets) {
            // If any bucket is empty or marked as deleted, the table is not full
            if (bucket == null || Objects.equals(bucket, emptySlot)) {
                return false;
            }
        }
        return true; // All buckets are filled
    }

    // Main method to run the hash table operations
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int initialSize = scanner.nextInt(); // Read the initial size of the hash table
        Main hashMap = new Main(initialSize); // Create a new hash table instance
        int operations = scanner.nextInt(); // Read the number of operations to perform
        scanner.nextLine(); // Consume the newline character

        // Loop through the number of operations
        for (int i = 0; i < operations; i++) {
            String[] command = scanner.nextLine().split(" "); // Read the command
            switch (command[0].toUpperCase()) { // Handle commands based on the first word
                case "INSERT":
                    hashMap.insertKey2HashTable(Integer.parseInt(command[1])); // Insert the key
                    break;
                case "DELETE":
                    hashMap.deleteKeyFromHashTable(Integer.parseInt(command[1])); // Delete the key
                    break;
                case "DISPLAY":
                    hashMap.displayHashtable(); // Display the hash table
                    break;
                default:
                    System.out.println("Invalid command"); // Handle invalid commands
            }
        }
        scanner.close(); // Close the scanner
    }
}
