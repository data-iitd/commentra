import java.util.Objects;
import java.util.Scanner;

public class Main {
    private int tableSize; // Size of the hash table
    private Integer[] buckets; // Array to store the hash table entries
    private final Integer emptySlot; // Marker for empty slots
    private int size; // Current number of elements in the hash table
    private int thresh; // Threshold for rehashing

    // Constructor to initialize the hash table with a given size
    public Main(int tableSize) {
        this.buckets = new Integer[tableSize];
        this.tableSize = tableSize;
        this.emptySlot = Integer.MIN_VALUE; // Sentinel value for empty slots
        this.size = 0;
        this.thresh = (int) (Math.log(tableSize) / Math.log(2)) + 2; // Calculate threshold for rehashing
    }

    // Hash function 1: Simple modulo operation
    public int hashFunction1(int key) {
        int hash = key % tableSize;
        return (hash < 0) ? hash + tableSize : hash; // Ensure hash is non-negative
    }

    // Hash function 2: More complex operation
    public int hashFunction2(int key) {
        int hash = key / tableSize;
        hash %= tableSize;
        return (hash < 0) ? hash + tableSize : hash; // Ensure hash is non-negative
    }

    // Method to insert a key into the hash table
    public void insertKey2HashTable(int key) {
        Integer wrappedInt = key; // Wrap the key for potential use in hash table
        Integer temp;
        int hash;
        int loopCounter = 0;
        if (isFull()) { // Check if the hash table is full
            System.out.println("Hash table is full, rehashing...");
            reHashTableIncreasesTableSize(); // Rehash to increase table size
        }
        while (loopCounter <= thresh) { // Loop to resolve collisions using double hashing
            loopCounter++;
            hash = hashFunction1(key);
            if (buckets[hash] == null || Objects.equals(buckets[hash], emptySlot)) { // Check for empty slot
                buckets[hash] = wrappedInt;
                size++;
                return;
            }
            temp = buckets[hash];
            buckets[hash] = wrappedInt;
            wrappedInt = temp;
            hash = hashFunction2(temp);
            if (buckets[hash] == null || Objects.equals(buckets[hash], emptySlot)) { // Check for empty slot
                buckets[hash] = wrappedInt;
                size++;
                return;
            }
            temp = buckets[hash];
            buckets[hash] = wrappedInt;
            wrappedInt = temp;
        }
        System.out.println("Infinite loop detected, rehashing...");
        reHashTableIncreasesTableSize(); // Rehash in case of infinite loop
        insertKey2HashTable(key); // Retry inserting the key
    }

    // Method to rehash the table when it becomes full
    public void reHashTableIncreasesTableSize() {
        Main newT = new Main(tableSize * 2); // Create a new hash table with double size
        for (int i = 0; i < tableSize; i++) { // Reinsert all existing keys
            if (buckets[i] != null && !Objects.equals(buckets[i], emptySlot)) {
                newT.insertKey2HashTable(buckets[i]);
            }
        }
        this.buckets = newT.buckets; // Update the current hash table with the new one
        this.tableSize = newT.tableSize;
        this.thresh = (int) (Math.log(tableSize) / Math.log(2)) + 2; // Update threshold
    }

    // Method to delete a key from the hash table
    public void deleteKeyFromHashTable(int key) {
        int hash = hashFunction1(key);
        if (Objects.equals(buckets[hash], key)) { // Check if the key is at the first hash position
            buckets[hash] = emptySlot;
            size--;
            return;
        }
        hash = hashFunction2(key);
        if (Objects.equals(buckets[hash], key)) { // Check if the key is at the second hash position
            buckets[hash] = emptySlot;
            size--;
            return;
        }
        System.out.println("Key " + key + " not found."); // Key not found in either position
    }

    // Method to display the contents of the hash table
    public void displayHashtable() {
        for (int i = 0; i < tableSize; i++) {
            if (buckets[i] == null || Objects.equals(buckets[i], emptySlot)) {
                System.out.println("Bucket " + i + ": Empty");
            } else {
                System.out.println("Bucket " + i + ": " + buckets[i]);
            }
        }
    }

    // Method to check if the hash table is full
    public boolean isFull() {
        for (Integer bucket : buckets) {
            if (bucket == null || Objects.equals(bucket, emptySlot)) {
                return false;
            }
        }
        return true;
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int initialSize = scanner.nextInt();
        Main hashMap = new Main(initialSize);
        int operations = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < operations; i++) {
            String[] command = scanner.nextLine().split(" ");
            switch (command[0].toUpperCase()) {
                case "INSERT":
                    hashMap.insertKey2HashTable(Integer.parseInt(command[1]));
                    break;
                case "DELETE":
                    hashMap.deleteKeyFromHashTable(Integer.parseInt(command[1]));
                    break;
                case "DISPLAY":
                    hashMap.displayHashtable();
                    break;
                default:
                    System.out.println("Invalid command");
            }
        }
        scanner.close();
    }
}
