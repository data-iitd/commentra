
import java.util.Objects;
import java.util.Scanner;

public class Main {
    // Class variables
    private int tableSize;
    private Integer[] buckets;
    private final Integer emptySlot;
    private int size;
    private int thresh;

    // Constructor
    public Main(int tableSize) {
        this.tableSize = tableSize;
        this.buckets = new Integer[tableSize];
        this.emptySlot = Integer.MIN_VALUE;
        this.size = 0;
        this.thresh = (int) (Math.log(tableSize) / Math.log(2)) + 2;
        System.out.println("Hash table created with size: " + tableSize);
    }

    // Hash functions
    public int hashFunction1(int key) {
        int hash = key % tableSize;
        return (hash < 0) ? hash + tableSize : hash;
        // Hash function 1
    }

    public int hashFunction2(int key) {
        int hash = key / tableSize;
        hash %= tableSize;
        return (hash < 0) ? hash + tableSize : hash;
        // Hash function 2
    }

    // Insert key into hash table
    public void insertKey2HashTable(int key) {
        Integer wrappedInt = key;
        Integer temp;
        int hash;
        int loopCounter = 0;

        if (isFull()) {
            System.out.println("Hash table is full, rehashing...");
            reHashTableIncreasesTableSize();
        }

        while (loopCounter <= thresh) {
            loopCounter++;
            hash = hashFunction1(key);
            if (buckets[hash] == null || Objects.equals(buckets[hash], emptySlot)) {
                buckets[hash] = wrappedInt;
                size++;
                System.out.println("Key " + key + " inserted at index " + hash);
                return;
            }
            temp = buckets[hash];
            buckets[hash] = wrappedInt;
            wrappedInt = temp;
            hash = hashFunction2(temp);
            if (buckets[hash] == null || Objects.equals(buckets[hash], emptySlot)) {
                buckets[hash] = wrappedInt;
                size++;
                System.out.println("Key " + key + " rehashed and inserted at index " + hash);
                return;
            }
            temp = buckets[hash];
            buckets[hash] = wrappedInt;
            wrappedInt = temp;
        }

        System.out.println("Infinite loop detected, rehashing...");
        reHashTableIncreasesTableSize();
        insertKey2HashTable(key);
    }

    // Rehash table by increasing table size
    public void reHashTableIncreasesTableSize() {
        Main newT = new Main(tableSize * 2);
        for (int i = 0; i < tableSize; i++) {
            if (buckets[i] != null && !Objects.equals(buckets[i], emptySlot)) {
                newT.insertKey2HashTable(buckets[i]);
            }
        }
        this.buckets = newT.buckets;
        this.tableSize = newT.tableSize;
        this.thresh = (int) (Math.log(tableSize) / Math.log(2)) + 2;
        System.out.println("Hash table rehashed with size: " + tableSize);
    }

    // Delete key from hash table
    public void deleteKeyFromHashTable(int key) {
        int hash = hashFunction1(key);
        if (Objects.equals(buckets[hash], key)) {
            buckets[hash] = emptySlot;
            size--;
            System.out.println("Key " + key + " deleted from index " + hash);
            return;
        }
        hash = hashFunction2(key);
        if (Objects.equals(buckets[hash], key)) {
            buckets[hash] = emptySlot;
            size--;
            System.out.println("Key " + key + " deleted from index " + hash);
            return;
        }
        System.out.println("Key " + key + " not found.");
    }

    // Display hash table
    public void displayHashtable() {
        for (int i = 0; i < tableSize; i++) {
            if (buckets[i] == null || Objects.equals(buckets[i], emptySlot)) {
                System.out.println("Bucket " + i + ": Empty");
            } else {
                System.out.println("Bucket " + i + ": " + buckets[i]);
            }
        }
    }

    // Check if hash table is full
    public boolean isFull() {
        for (Integer bucket : buckets) {
            if (bucket == null || Objects.equals(bucket, emptySlot)) {
                return false;
            }
        }
        return true;
    }

    // Main method
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