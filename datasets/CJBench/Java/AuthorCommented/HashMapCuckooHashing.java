
import java.util.Objects;
import java.util.Scanner;

/**
 * This class implements a hash table using Cuckoo Hashing.
 * Cuckoo hashing is a type of open-addressing hash table that resolves collisions
 * by relocating existing keys. It utilizes two hash functions to minimize collisions
 * and automatically resizes the table when the load factor exceeds 0.7.
 *
 * For more information on cuckoo hashing, refer to
 * <a href="https://en.wikipedia.org/wiki/Cuckoo_hashing">this Wikipedia page</a>.
 */
public class HashMapCuckooHashing {
    private int tableSize;
    private Integer[] buckets;
    private final Integer emptySlot;
    private int size;
    private int thresh;

    /**
     * Constructs a HashMapCuckooHashing object with the specified initial table size.
     *
     * @param tableSize the initial size of the hash map
     */
    public HashMapCuckooHashing(int tableSize) {
        this.buckets = new Integer[tableSize];
        this.tableSize = tableSize;
        this.emptySlot = Integer.MIN_VALUE;
        this.size = 0;
        this.thresh = (int) (Math.log(tableSize) / Math.log(2)) + 2;
    }

    /**
     * Computes the first hash index for a given key using the modulo operation.
     *
     * @param key the key for which the hash index is computed
     * @return an integer index corresponding to the key
     */
    public int hashFunction1(int key) {
        int hash = key % tableSize;
        return (hash < 0) ? hash + tableSize : hash;
    }

    /**
     * Computes the second hash index for a given key using integer division.
     *
     * @param key the key for which the hash index is computed
     * @return an integer index corresponding to the key
     */
    public int hashFunction2(int key) {
        int hash = key / tableSize;
        hash %= tableSize;
        return (hash < 0) ? hash + tableSize : hash;
    }

    /**
     * Inserts a key into the hash table using cuckoo hashing.
     * If the target bucket is occupied, it relocates the existing key and attempts to insert
     * it into its alternate location. If the insertion process exceeds the threshold,
     * the table is resized.
     *
     * @param key the key to be inserted into the hash table
     * @throws IllegalArgumentException if the key already exists in the table
     */
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
                return;
            }

            temp = buckets[hash];
            buckets[hash] = wrappedInt;
            wrappedInt = temp;

            hash = hashFunction2(temp);
            if (buckets[hash] == null || Objects.equals(buckets[hash], emptySlot)) {
                buckets[hash] = wrappedInt;
                size++;
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

    /**
     * Rehashes the current table to a new size (double the current size) and reinserts existing keys.
     */
    public void reHashTableIncreasesTableSize() {
        HashMapCuckooHashing newT = new HashMapCuckooHashing(tableSize * 2);
        for (int i = 0; i < tableSize; i++) {
            if (buckets[i] != null && !Objects.equals(buckets[i], emptySlot)) {
                newT.insertKey2HashTable(buckets[i]);
            }
        }
        this.buckets = newT.buckets;
        this.tableSize = newT.tableSize;
        this.thresh = (int) (Math.log(tableSize) / Math.log(2)) + 2;
    }

    /**
     * Deletes a key from the hash table, marking its position as available.
     *
     * @param key the key to be deleted from the hash table
     * @throws IllegalArgumentException if the table is empty or if the key is not found
     */
    public void deleteKeyFromHashTable(int key) {
        int hash = hashFunction1(key);
        if (Objects.equals(buckets[hash], key)) {
            buckets[hash] = emptySlot;
            size--;
            return;
        }

        hash = hashFunction2(key);
        if (Objects.equals(buckets[hash], key)) {
            buckets[hash] = emptySlot;
            size--;
            return;
        }

        System.out.println("Key " + key + " not found.");
    }

    /**
     * Displays the hash table contents, bucket by bucket.
     */
    public void displayHashtable() {
        for (int i = 0; i < tableSize; i++) {
            if (buckets[i] == null || Objects.equals(buckets[i], emptySlot)) {
                System.out.println("Bucket " + i + ": Empty");
            } else {
                System.out.println("Bucket " + i + ": " + buckets[i]);
            }
        }
    }

    /**
     * Checks if the hash map is full.
     *
     * @return true if the hash map is full, false otherwise
     */
    public boolean isFull() {
        for (Integer bucket : buckets) {
            if (bucket == null || Objects.equals(bucket, emptySlot)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int initialSize = scanner.nextInt();
        HashMapCuckooHashing hashMap = new HashMapCuckooHashing(initialSize);

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
